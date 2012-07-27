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
	int dato1, dato2;
	QString stringa1;
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
			case Comunicazioni::RichiediInfo:
				emit GotRichiediInfo();
				break;
			case Comunicazioni::PartecipaServer:
				emit IWantToJoin(socketDescriptor);
				break;
			case Comunicazioni::CambiateInfo:
				incom >> dato1 >> stringa1 >> dato2; // ID, Nuovo Nome, Nuovo Colore
				emit CambiateInfo(dato1,stringa1,dato2);
				break;
			case Comunicazioni::SonoPronto:
				incom >> dato1; //ID di chi è pronto
				emit IsReady(dato1);
				break;
			case Comunicazioni::NonSonoPronto:
				incom >> dato1; //ID di chi è pronto
				emit IsNotReady(dato1);
				break;
			/*case Comunicazioni::AggiunteArmate:
				incom >> dato1 >> dato2;
				emit GotAggiuntoArmate(Stato,Numero);
				break;*/
			default: break;
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

void GiocoSocket::MandaMioID(int ident){
	if(ident==socketDescriptor){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::WhatsMyID) << socketDescriptor << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		write(block);
	}
}
void GiocoSocket::NuovoUtente(int ident){
	if(ident!=socketDescriptor){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::NewPlayer) << ident << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		write(block);
	}
}
void GiocoSocket::UpdateInfo(int ident,const QString& NuovoNome,int NuovoColore){
	if(ident!=socketDescriptor){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::AggiornaInfo) << ident << NuovoNome << NuovoColore << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		write(block);
	}
}
void GiocoSocket::StartGame(){
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << quint16(0) << quint16(Comunicazioni::StartGame) << quint16(0xFFFF);
	out.device()->seek(0);
	out << quint16(block.size() - 2*sizeof(quint16));
	write(block);
}
void GiocoSocket::GiocatoreDisconnesso(int ident){
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << quint16(0) << quint16(Comunicazioni::Disconnesso) << ident << quint16(0xFFFF);
	out.device()->seek(0);
	out << quint16(block.size() - 2*sizeof(quint16));
	write(block);
}