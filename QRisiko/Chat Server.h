#ifndef CHATSERVER_H
#define CHATSERVER_H
#include <QTcpServer>
#include <QList>
#include <QTcpServer>
#include "Chat Thread.h"

class ChatServer : public QTcpServer
{
	Q_OBJECT
	public:
		ChatServer(QObject *parent = 0);
	private:
		void incomingConnection(int socketId);
		QList<ChatThread*> clients;
	signals:
		void SendMessage(QString msg);

};

#endif