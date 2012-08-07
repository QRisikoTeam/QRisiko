#include "Gioco Thread.h"
GiocoThread::GiocoThread(int soketDescriptor, QObject *parent)
: QThread(parent), socketDescriptor(soketDescriptor),socket(NULL)
{
	socket= new GiocoSocket(socketDescriptor,this);
	connect(socket,SIGNAL(disconnected()), this, SLOT(stop()));

	connect(socket,SIGNAL(GotRichiediInfo()),this,SLOT(IdentificaInfoReq()));
	connect(socket,SIGNAL(IWantToJoin(int)),this,SIGNAL(IWantToJoin(int)));
	connect(socket,SIGNAL(CambiateInfo(int,QString,int)),this,SIGNAL(CambiateInfo(int,QString,int)));
	connect(this,SIGNAL(InviaInformazioni(QString,int,int)),socket,SLOT(InviaInformazioni(QString,int,int)));
	connect(this,SIGNAL(MandaMioID(int)),socket,SLOT(MandaMioID(int)));
	connect(this,SIGNAL(NuovoUtente(int)),socket,SLOT(NuovoUtente(int)));
	connect(this,SIGNAL(UpdateInfo(int,QString,int)),socket,SLOT(UpdateInfo(int,QString,int)));
	connect(socket,SIGNAL(IsReady(int)),this,SIGNAL(IsReady(int)));
	connect(socket,SIGNAL(IsNotReady(int)),this,SIGNAL(IsNotReady(int)));
	connect(this,SIGNAL(StartGame()),socket,SLOT(StartGame()));
	connect(this,SIGNAL(GiocatoreDisconnesso(int)),socket,SLOT(GiocatoreDisconnesso(int)));
	connect(this,SIGNAL(MandaInfoA(int,int,QString,int)),socket,SLOT(MandaInfoA(int,int,QString,int)));
	connect(socket,SIGNAL(RicevutoID(int)),this,SIGNAL(RicevutoID(int)));
		
}

void GiocoThread::run()
{
	exec();
}

void  GiocoThread::stop(){
	emit Disonnesso(socketDescriptor);
	exit(0);
}
void GiocoThread::ForzaDisconnessione(){
	if(socket){ 
		socket->disconnectFromHost();
		socket->waitForDisconnected();
	}
	exit(0);
}