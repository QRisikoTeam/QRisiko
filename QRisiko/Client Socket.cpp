#include "Client Socket.h"
#include "Chat Const.h"
ClientSocket::ClientSocket(int soketDescriptor, QObject *parent)
: QTcpSocket(parent), socketDescriptor(soketDescriptor)
{
	this->setSocketDescriptor(socketDescriptor);
	connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
	connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
	nextBlockSize = 0;
}
void ClientSocket::readClient()
{
	QDataStream incom(this);
	incom.setVersion(QDataStream::Qt_4_7);

	forever {
		if (nextBlockSize == 0) {
			if (bytesAvailable() < sizeof(quint16))
				break;
			incom >> nextBlockSize;
		}
		if (nextBlockSize == 0xFFFF) {
			nextBlockSize = 0;
			break;
		}
		if (bytesAvailable() < nextBlockSize)
			break;
		QString message;
		incom >> message;
		emit incomingMessage(message);
		nextBlockSize = 0;
	}
}

void ClientSocket::SendMessage(QString msg){
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << quint16(0) << msg << quint16(0xFFFF);
	out.device()->seek(0);
	out << quint16(block.size() - 2*sizeof(quint16));
	write(block);
}