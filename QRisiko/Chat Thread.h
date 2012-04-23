#ifndef CHATTHREAD_H
#define CHATTHREAD_H
#include <QThread>
#include <QString>
#include "Client Socket.h"

class ChatThread : public QThread
{
	Q_OBJECT
	public:
		ChatThread(int soketDescriptor, QObject *parent);
		void run();
		int GetSocketDescriptor() const {return socketDescriptor;}
		void stop();
	signals:
		void incomingMessage(QString msg);
		void SendMessage(QString msg);
	private:
		bool keepRunning;
		int socketDescriptor;
		QString text;
		ClientSocket* socket;
};


#endif
