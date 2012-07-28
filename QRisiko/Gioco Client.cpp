#include "Gioco Client.h"

ClientGioco::ClientGioco(const QString& HIP,int por,QObject* parent)
:QObject(parent)
,HostIP(HIP)
,Porta(por)
,nextBlockSize(0)
{
	connect(&Cliente,SIGNAL(connected()),this,SIGNAL(Connesso()));
	connect(&Cliente,SIGNAL(connected()),this,SLOT(IWantToJoin()));
	connect(&Cliente,SIGNAL(disconnected()),this,SIGNAL(Disconnesso()));
	connect(&Cliente,SIGNAL(readyRead()),this,SLOT(IncomingTransmission()));
}
void ClientGioco::Connetti(){
	Cliente.connectToHost(HostIP,Porta);
}
void ClientGioco::Disconnetti(){
	Cliente.close();
}
void ClientGioco::IncomingTransmission(){
	QDataStream incom(&Cliente);
	incom.setVersion(QDataStream::Qt_4_7);
	qint16 TipoRichiesta;
	qint16 data1,data2;
	QString stringa1;
	forever {
		if (nextBlockSize == 0) {
			if (Cliente.bytesAvailable() < sizeof(quint16))
				break;
			incom >> nextBlockSize;
		}
		if (nextBlockSize == 0xFFFF) {
			nextBlockSize = 0;
			break;
		}
		if (Cliente.bytesAvailable() < nextBlockSize)
			break;

		incom >> TipoRichiesta;
		switch (TipoRichiesta){
			case Comunicazioni::WhatsMyID:
				incom >> data1;
				MyID=data1;
				emit MyIDIs(MyID);
				RicevutoID();
				break;
			case Comunicazioni::NewPlayer:
				incom >> data1; //Registra l'ID del nuovo utente
				emit NuovoGiocatore(data1);
				SonoProntoARicevere();
				break;
			case Comunicazioni::AggiornaInfo:
				incom >> data1 >> stringa1 >> data2; //ID da aggiornare, Nuovo Nome, Nuovo Colore
				emit AggiornaInfo(data1,stringa1,data2);
				break;
			case Comunicazioni::StartGame:
				emit StartGame();
				break;
			case Comunicazioni::Disconnesso:
				incom >> data1; //ID da rimuovere
				emit GiocatoreDisconnesso(data1);
				break;

		}
		nextBlockSize = 0;
	}
}

void ClientGioco::CambiateMieInfo(const QString& NuovoNome, int NuovoColore){
	if(Cliente.isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::CambiateInfo) << qint16(MyID) << NuovoNome << qint16(NuovoColore) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		Cliente.write(block);
	}
}

void ClientGioco::SonoPronto(){
	if(Cliente.isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::SonoPronto) << qint16(MyID) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		Cliente.write(block);
	}
}
void ClientGioco::NonSonoPronto(){
	if(Cliente.isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::NonSonoPronto) << qint16(MyID) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		Cliente.write(block);
	}
}

void ClientGioco::IWantToJoin(){
	if(Cliente.isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::PartecipaServer) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		Cliente.write(block);
	}
}
void ClientGioco::RicevutoID(){
	if(Cliente.isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::IDRicevuto) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		Cliente.write(block);
	}
}
void ClientGioco::SonoProntoARicevere(){
	if(Cliente.isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << quint16(0) << quint16(Comunicazioni::ProntoARicevere) << quint16(0xFFFF);
		out.device()->seek(0);
		out << quint16(block.size() - 2*sizeof(quint16));
		Cliente.write(block);
	}
}