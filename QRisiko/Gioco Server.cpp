#include "Gioco Server.h"
#include "Costanti Nazioni.h"
GiocoServer::GiocoServer(QObject *parent): QTcpServer(parent),NumGiocatori(1),FasePrePartita(true){}
GiocoServer::GiocoServer(const QString& Nome, const int& MaxPl, QObject *parent)
:QTcpServer(parent)
,NomeServer(Nome)
,MaxGiocatori(MaxPl)
,NumGiocatori(1)
,FasePrePartita(true)
{
	IDs.append(Comunicazioni::ServerID);
	Pronti.append(false);
	connect(this,SIGNAL(IsNotReady(int)),this,SLOT(RimuoviPronto(int)));
	connect(this,SIGNAL(IsReady(int)),this,SLOT(AggiungiPronto(int)));
	connect(this,SIGNAL(Disonnesso(int)),this,SLOT(GiocatoreDisconnesso(int)));
}
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
	connect(clients.last(),SIGNAL(IsReady(int)),this,SIGNAL(IsReady(int)));
	connect(clients.last(),SIGNAL(IsNotReady(int)),this,SIGNAL(IsNotReady(int)));
	connect(this,SIGNAL(StartGame()),clients.last(),SIGNAL(StartGame()));
	connect(clients.last(),SIGNAL(Disonnesso(int)),this,SIGNAL(Disonnesso(int)));
	connect(this,SIGNAL(Disonnesso(int)),clients.last(),SIGNAL(GiocatoreDisconnesso(int)));

	clients.last()->start();
	IDs.append(socketId);
	Pronti.append(false);
	NumGiocatori++;
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

void GiocoServer::AggiungiPronto(int ident){
	if (FasePrePartita){
		*(Pronti.begin()+IDs.indexOf(ident))=true;
		bool TuttiPronti=true;
		for (QList<bool>::iterator i=Pronti.begin(); i!=Pronti.end() && TuttiPronti; i++){
			if (!(*i)) TuttiPronti=false;
		}
		if (TuttiPronti) emit StartGame();
	}
}
void GiocoServer::RimuoviPronto(int ident){
	if (FasePrePartita) *(Pronti.begin()+IDs.indexOf(ident))=false;
}
void GiocoServer::GiocatoreDisconnesso(int ident){
	Pronti.erase(Pronti.begin()+IDs.indexOf(ident));
	IDs.erase(IDs.begin()+IDs.indexOf(ident));
	if(FasePrePartita){
		bool TuttiPronti=true;
		for (QList<bool>::iterator i=Pronti.begin(); i!=Pronti.end() && TuttiPronti; i++){
			if (!(*i)) TuttiPronti=false;
		}
		if (TuttiPronti) emit StartGame();
	}
	NumGiocatori--;
}