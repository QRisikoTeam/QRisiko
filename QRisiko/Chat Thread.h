#ifndef CHATTHREAD_H
#define CHATTHREAD_H
#include <QThread>
#include <QString>
#include <QTcpSocket>
#include <QMutex>
#include <QQueue>
class ChatThread: public QThread{
	Q_OBJECT
	public:
		ChatThread(QString Host, unsigned int por=2200, bool Server=false);
		~ChatThread();
	signals:
		void MessageRecieved(QString Message, bool fromserver=false);
	public slots:
		void SendMessage(QString Message);
	private slots:
		void Connesso();
		void ErroreConnessione();
		void Inbox();
		void connectionClosedByServer();
	private:
		QTcpSocket TCPsocket;
		QString HostIP;
		unsigned int port;
		bool IsServer;
		bool finito;
		QMutex mutex;
		QQueue<QString> sentMessageQueue;
		QQueue<QString> recievedMessageQueue;
		quint16 nextBlockSize;
	protected:
		void run();
};

#endif
