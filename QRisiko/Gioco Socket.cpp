#include "Gioco Socket.h"
#include "Costanti Nazioni.h"
GiocoSocket::GiocoSocket(int soketDescriptor, QObject *parent)
: QTcpSocket(parent), socketDescriptor(soketDescriptor)
{
	this->setSocketDescriptor(socketDescriptor);
	connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
	connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
	nextBlockSize = 0;
}
void GiocoSocket::readClient()
{
	QDataStream incom(this);
	incom.setVersion(QDataStream::Qt_4_7);
	int TipoRichiesta;
	int Stato, Numero;
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

		incom >> TipoRichiesta;
		switch (TipoRichiesta){
			case Comunicazioni::RichiediInfo: emit GotRichiediInfo(); break;
			case Comunicazioni::AggiunteArmate:
				incom >> Stato >> Numero;
				emit GotAggiuntoArmate(Stato,Numero);
				break;

		}
		nextBlockSize = 0;
	}
}

void GiocoSocket::InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori){
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << quint16(0) << quint16(Comunicazioni::OttieniInfo) << Nome << Giocatori << MaxGiocatori << quint16(0xFFFF);
	out.device()->seek(0);
	out << quint16(block.size() - 2*sizeof(quint16));
	write(block);
	disconnectFromHost();
}