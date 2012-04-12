#include "Chat Thread.h"
#include "Chat Const.h"
void ChatThread::SendMessage(QString Message){
	QMutexLocker locker(&mutex);
	sentMessageQueue.enqueue(Message);
	if(!isRunning())
	 start();
}

ChatThread::ChatThread(QString Host, unsigned int por, bool Server):
HostIP(Host),
port(por),
IsServer(Server)
{
	TCPsocket.connectToHost(HostIP,port);
	emit MessageRecieved(tr("<font color=\""+Colors::ServerColor.name().toUtf8()+"\">"+"Connessione in corso...</font>"),true);
	connect(&TCPsocket, SIGNAL(connected()), this, SLOT(Connesso()));
	connect(&TCPsocket, SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ErroreConnessione()));
	connect(&TCPsocket, SIGNAL(readyRead()),this, SLOT(Inbox()));
	connect(&TCPsocket, SIGNAL(disconnected()),this, SLOT(connectionClosedByServer()));
	nextBlockSize=0;
	finito=false;
}

void ChatThread::Connesso(){emit MessageRecieved(tr("<font color=\""+Colors::ServerColor.name().toUtf8()+"\">"+"Connesso</font>"),true);}
void ChatThread::ErroreConnessione(){emit MessageRecieved(tr("<font color=\"red\">ERRORE!!!</font><br/><font color=\"red\">"+TCPsocket.errorString().toUtf8()+"</font>"),true);}
void ChatThread::run(){
	forever {
		mutex.lock();
		if(sentMessageQueue.isEmpty() && recievedMessageQueue.isEmpty())
		{
			mutex.unlock();
			break;
		}
		else if(!sentMessageQueue.isEmpty()){
			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_4_7);
			out << qint16(0) << sentMessageQueue.dequeue();
			out.device()->seek(0);
			out << quint16(block.size() - sizeof(quint16));
			TCPsocket.write(block);
		}
		if(!recievedMessageQueue.isEmpty())
			emit MessageRecieved(recievedMessageQueue.dequeue(),false);
	}
}
void ChatThread::Inbox(){
	finito=false;
	QMutexLocker locker(&mutex);
	QDataStream in(&TCPsocket);
	in.setVersion(QDataStream::Qt_4_7);
	forever {
		if (nextBlockSize == 0) {
			if (TCPsocket.bytesAvailable() < sizeof(quint16))
				break;
			in >> nextBlockSize;
		}
		if (nextBlockSize == 0xFFFF) {
			nextBlockSize = 0;
			finito=true;
			break;
		}
		if (TCPsocket.bytesAvailable() < nextBlockSize)
			break;
		QString IncomingMessage;
		in >> IncomingMessage;
		recievedMessageQueue.enqueue(IncomingMessage);
		nextBlockSize = 0;
		if(!isRunning())
			start();
	}
}

ChatThread::~ChatThread(){
	TCPsocket.close();
	QThread::~QThread();
}

void ChatThread::connectionClosedByServer()
{
	if(!finito){
		TCPsocket.close();
		emit MessageRecieved(tr("<font color=\"red\">ERRORE!!!</font><br/><font color=\"red\">Connessione Chiusa dal Server</font>"),true);
	}
}