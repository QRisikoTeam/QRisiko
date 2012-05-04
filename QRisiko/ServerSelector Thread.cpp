#include "ServerSelector Thread.h"
#include <QtGui>
ServerSelectorThread::ServerSelectorThread(const QStringList& Lista, unsigned int Port, QObject *parent)
: QThread(parent),
ListaIPs(Lista),
Porta(Port),
TimeoutTime(2000),
cancellatore(this)
{
	keepRunning=true;
}

void ServerSelectorThread::run()
{
	socket=new QTcpSocket(this);
	bool chiamato;
	connect(socket, SIGNAL(connected()), this, SLOT(Connesso()));
	connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ErroreConnessione()));
	connect(socket, SIGNAL(readyRead()),this, SLOT(OttieniInfo()));

	for (int i=0;i<ListaIPs.size() && keepRunning;i++){
		if(!keepRunning) return;
		if(socket->isOpen()) socket->close();
		Prossimo=false;
		currentIP=ListaIPs.at(i);
		socket->connectToHost(currentIP,Porta);
		chiamato=false;
		while(!Prossimo) {
			if(!keepRunning) return;
			if (!chiamato){
				if (!socket->waitForConnected(TimeoutTime)) ErroreConnessione();
				chiamato=true;
			}
		}
	}
	emit finito();
}

void ServerSelectorThread::Connesso(){
	if(socket->isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << qint16(sizeof(quint16)) << qint16(Comunicazioni::RichiediInfo) << quint16(0xFFFF);
		socket->write(block);
	}
	else ErroreConnessione();
}

void ServerSelectorThread::ErroreConnessione(){
	cancellatore.NotResponding(currentIP);
	Prossimo=true;
}

void ServerSelectorThread::OttieniInfo(){
	int nextBlockSize = 0;
	QDataStream in(socket);
	in.setVersion(QDataStream::Qt_4_7);
	forever {
		if (nextBlockSize == 0) {
			if (socket->bytesAvailable() < sizeof(quint16))
				break;
			in >> nextBlockSize;
		}
		if (nextBlockSize == 0xFFFF) {
			nextBlockSize = 0;
			break;
		}
		if (socket->bytesAvailable() < nextBlockSize)
			break;
		int Tipo;
		in >> Tipo;
		if (Tipo!=Comunicazioni::OttieniInfo) return;
		QString Name;
		int GiocatoriOnline;
		int MaxGiocatori;
		in >> Name >> GiocatoriOnline >> MaxGiocatori;
		emit InfoRicevute(Name,GiocatoriOnline,MaxGiocatori,currentIP);
		nextBlockSize = 0;
	}
	Prossimo=true;
}

void  ServerSelectorThread::stop(){
	keepRunning=false;
}
void ServerSelectorThread::Skip(){
	Prossimo=true;
	disconnect(&cancellatore,SIGNAL(done()),this,SLOT(Skip()));
}