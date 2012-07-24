#include "Gioco Server.h"
GiocoServer::GiocoServer(QObject *parent): QTcpServer(parent),NumGiocatori(1){}
GiocoServer::GiocoServer(const QString& Nome, const int& MaxPl, QObject *parent)
:QTcpServer(parent)
,NomeServer(Nome)
,MaxGiocatori(MaxPl)
,NumGiocatori(1)
{}
void GiocoServer::incomingConnection(int socketId)
{
	clients.append(new GiocoThread(socketId,this));
	connect(clients.last(), SIGNAL(finished()), clients.last(), SLOT(deleteLater()));

	connect(clients.last(),SIGNAL(GotRichiediInfo(int)),this,SLOT(FormaInfo(int)));
	connect(this,SIGNAL(InviaInformazioni(QString,int,int)),clients.last(),SIGNAL(InviaInformazioni(QString,int,int)));
	connect(this,SIGNAL(NuovaConnessione(int)),clients.last(),SIGNAL(MandaMioID(int)));
	connect(this,SIGNAL(NuovaConnessione(int)),clients.last(),SIGNAL(NuovoUtente(int)));
	connect(clients.last(),SIGNAL(CambiateInfo(int,QString,int)),this,SIGNAL(UpdateInfo(int,QString,int)));
	connect(this,SIGNAL(UpdateInfo(int,QString,int)),clients.last(),SIGNAL(UpdateInfo(int,QString,int)));

	clients.last()->start();
	emit NuovaConnessione(socketId);
}
void GiocoServer::FormaInfo(int SoDe){
	for (int i=0;i<clients.size();i++){
		if (clients.at(i)->GetSocketDescriptor()==SoDe){
			clients.at(i)->SendInfo(NomeServer,NumGiocatori,MaxGiocatori);
			return;
		}
	}
}