#include "Gioco Socket.h"
#include "Costanti Nazioni.h"
#include <QtGui>
GiocoSocket::GiocoSocket(int soketDescriptor, QObject *parent)
: QTcpSocket(parent), socketDescriptor(soketDescriptor), nextBlockSize(0)
{
	this->setSocketDescriptor(socketDescriptor);
	connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
	connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
	connect(this, SIGNAL(disconnected()), this,SLOT(Disconnessione()));
	nextBlockSize = 0;
}
void GiocoSocket::readClient()
{
	QDataStream incom(this);
	incom.setVersion(QDataStream::Qt_4_7);
	qint16 TipoRichiesta;
	qint16 dato1, dato2;
	QString stringa1;
	forever {
		if (nextBlockSize == 0) {
			if (bytesAvailable() < sizeof(quint16))
				break;
			incom >> nextBlockSize;
		}
		if (nextBlockSize == 0xFFFF) {
			nextBlockSize = 0;
			continue;
		}
		if (bytesAvailable() < nextBlockSize)
			break;

		incom >> TipoRichiesta;
		if(TipoRichiesta==Comunicazioni::RichiediInfo){
				emit GotRichiediInfo();
		}
		else if(TipoRichiesta==Comunicazioni::PartecipaServer){
			emit IWantToJoin(socketDescriptor);
		}
		else if(TipoRichiesta==Comunicazioni::CambiateInfo){
			incom >> dato1 >> stringa1 >> dato2; // ID, Nuovo Nome, Nuovo Colore
			emit CambiateInfo(dato1,stringa1,dato2);
		}
		else if(TipoRichiesta==Comunicazioni::SonoPronto){
			incom >> dato1; //ID di chi è pronto
			emit IsReady(dato1);
		}
		else if(TipoRichiesta==Comunicazioni::NonSonoPronto){
			incom >> dato1; //ID di chi è pronto
			emit IsNotReady(dato1);
		}
		else if(TipoRichiesta==Comunicazioni::IDRicevuto){
			emit RicevutoID(socketDescriptor);
		}
		nextBlockSize = 0;
	}
}

void GiocoSocket::InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori){
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << quint16(0) << quint16(Comunicazioni::OttieniInfo) << Nome << qint16(Giocatori) << qint16(MaxGiocatori) << quint16(0xFFFF);
	out.device()->seek(0);
	out << quint16(block.size() - 2*sizeof(quint16));
	write(block);
	qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
	disconnectFromHost();
}

void GiocoSocket::MandaMioID(int ident){
	if(ident==socketDescriptor){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::WhatsMyID) << qint16(socketDescriptor) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		write(block);
	}
}
void GiocoSocket::NuovoUtente(int ident){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::NewPlayer) << qint16(ident) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		write(block);
}
void GiocoSocket::UpdateInfo(int ident,const QString& NuovoNome,int NuovoColore){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::AggiornaInfo) << qint16(ident) << NuovoNome << qint16(NuovoColore) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		write(block);
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
	out << quint16(0) << quint16(Comunicazioni::Disconnesso) << qint16(ident) << quint16(0xFFFF);
	out.device()->seek(0);
	out << quint16(block.size() - 2*sizeof(quint16));
	write(block);
}
void GiocoSocket::MandaInfoA(int destinazione, int ident, const QString& nome, int colore){
	if (socketDescriptor==destinazione){
		NuovoUtente(ident);
		qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
		UpdateInfo(ident,nome,colore);
		qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
	}
}