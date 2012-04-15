#include "Chat Thread.h"
#include "Chat Const.h"
#include <QDebug>
/*DEBUG*/ #include <QMessageBox>
ChatThread::ChatThread(int soketDescriptor, QObject *parent)
: QThread(parent), socketDescriptor(soketDescriptor)
{
	keepRunning=true;
	socket= new ClientSocket(socketDescriptor,this);
	connect(socket,SIGNAL(incomingMessage(QString)),this,SIGNAL(incomingMessage(QString)));
	connect(this,SIGNAL(SendMessage(QString )),socket,SLOT(SendMessage(QString)));
}

void ChatThread::run()
{
	while(keepRunning){}
	socket->disconnectFromHost();
}

void  ChatThread::stop(){
	keepRunning=false;
}
