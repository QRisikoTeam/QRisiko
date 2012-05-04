#include "Gioco Thread.h"
GiocoThread::GiocoThread(int soketDescriptor, QObject *parent)
: QThread(parent), socketDescriptor(soketDescriptor)
{
	keepRunning=true;
	socket= new GiocoSocket(socketDescriptor,this);
	connect(socket,SIGNAL(disconnected()), this, SLOT(stop()));

	connect(socket,SIGNAL(GotRichiediInfo()),this,SLOT(IdentificaInfoReq()));
	connect(this,SIGNAL(InviaInformazioni(QString,int,int)),socket,SLOT(InviaInformazioni(QString,int,int)));
}

void GiocoThread::run()
{
	while(keepRunning){}
}

void  GiocoThread::stop(){
	keepRunning=false;
}