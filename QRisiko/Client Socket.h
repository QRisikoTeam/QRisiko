#ifndef CLIENTSOKET_H
#define CLIENTSOKET_H
#include <QTcpSocket>
#include <QString>
class ClientSocket : public QTcpSocket
{
	Q_OBJECT
	public:
		ClientSocket(int soketDescriptor, QObject *parent = 0);
	private slots:
			void readClient();
			void SendMessage(QString msg);
	private:
		quint16 nextBlockSize;
		int socketDescriptor;
	signals:
		void incomingMessage(QString message);
};


#endif