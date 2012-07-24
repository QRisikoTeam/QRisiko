#include "Gioco Thread.h"
GiocoThread::GiocoThread(int soketDescriptor, QObject *parent)
: QThread(parent), socketDescriptor(soketDescriptor)
{
	keepRunning=true;
	socket= new GiocoSocket(socketDescriptor,this);
	connect(socket,SIGNAL(disconnected()), this, SLOT(stop()));

	connect(socket,SIGNAL(GotRichiediInfo()),this,SLOT(IdentificaInfoReq()));
	connect(socket,SIGNAL(CambiateInfo(int,QString,int)),this,SIGNAL(CambiateInfo(int,QString,int)));
	connect(this,SIGNAL(InviaInformazioni(QString,int,int)),socket,SLOT(InviaInformazioni(QString,int,int)));
	connect(this,SIGNAL(MandaMioID(int)),socket,SLOT(MandaMioID(int)));
	connect(this,SIGNAL(NuovoUtente(int)),socket,SLOT(NuovoUtente(int)));
	connect(this,SIGNAL(UpdateInfo(int,QString,int)),socket,SLOT(UpdateInfo(int,QString,int)));
		
}

void GiocoThread::run()
{
	while(keepRunning){}
}

void  GiocoThread::stop(){
	keepRunning=false;
}