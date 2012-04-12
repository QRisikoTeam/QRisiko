#ifndef CHATSERVER_H
#define CHATSERVER_H
#include <QTcpServer>

class ChatServer : public QTcpServer
{
	Q_OBJECT
	public:
		ChatServer(QObject *parent = 0);
	private:
		void incomingConnection(int socketId);
};

#endif