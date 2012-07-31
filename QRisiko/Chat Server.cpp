#include "Chat Server.h"
ChatServer::ChatServer(QObject *parent): QTcpServer(parent){}
void ChatServer::incomingConnection(int socketId)
{
	clients.append(new ChatThread(socketId,this));
	connect(clients.last(), SIGNAL(finished()), clients.last(), SLOT(deleteLater()));
	connect(this,SIGNAL(SendMessage(QString)),clients.last(),SIGNAL(SendMessage(QString)));
	connect(clients.last(),SIGNAL(incomingMessage(QString)),this,SIGNAL(SendMessage(QString)));
	clients.last()->start();
}
