#include "Chat Widget.h"
#include "Chat Const.h"
#include <QtGui>
#include <QtNetwork>
#include <QTest>

ChatWidget::ChatWidget(QWidget *parent, QString name, QColor col, bool timestamp, bool server, QString hostIP, unsigned int por)
:QWidget(parent),
UserName(name),
UserColor(col),
ShowTimeStamp(timestamp),
IsServer(server),
Host(hostIP),
port(por)
{
	setupUi(this);
	TCPServer=NULL;
	TCPsocket=NULL;
	connect(reconnectButton,SIGNAL(clicked()),this,SLOT(Avvia()));
	MessageText->installEventFilter(this);
	connect(SendButton,SIGNAL(clicked()),this,SLOT(sendMessage()));
	ChatText->setHtml("");
	selector=new SmilesSelector(this);
	selector->setGeometry(253-selector->sizeHint().width()
		,154-selector->sizeHint().height()
		,selector->sizeHint().width(),
		selector->sizeHint().height());
	connect(SmilesButton,SIGNAL(clicked()),selector,SLOT(show_toggle()));
	connect(selector,SIGNAL(selected(int)),this,SLOT(addSmile(int))) ;
	partito=false;	
}

bool ChatWidget::Avvia(){
	reconnectButton->setVisible(false);
	if(!IsServer){
		TCPsocket=new QTcpSocket(this);
		connect(TCPsocket, SIGNAL(connected()), this, SLOT(Connesso()));
		connect(TCPsocket, SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ErroreConnessione()));
		connect(TCPsocket, SIGNAL(disconnected()),this, SLOT(connectionClosedByServer()));
		connect(TCPsocket, SIGNAL(readyRead()),this, SLOT(Inbox()));
		connect(this, SIGNAL(MessageRecieved(QString,bool)), this, SLOT(PrintMessage(QString,bool)));
		PrintMessage(tr("Connessione in corso..."),true);
		TCPsocket->connectToHost(Host,port);
		nextBlockSize=0;
		finito=false;
	}
	else{
		TCPServer=new ChatServer(this);
		if (!TCPServer->listen(QHostAddress::Any, port)) {
			PrintMessage(tr("Failed to bind to port"),true);
			return false;
		}
		else {
			QString ipAddress("");
			QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
			// use the first non-localhost IPv4 address
			for (int i = 0; i < ipAddressesList.size(); ++i) {
				if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
					ipAddressesList.at(i).toIPv4Address()) {
						ipAddress = ipAddressesList.at(i).toString();
						break;
				}
			}
			// if we did not find one, use IPv4 localhost
			if (ipAddress.isEmpty())
				ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
			PrintMessage(tr("Server Avviato<br/>IP: %1<br/>Port: %2").arg(ipAddress).arg(TCPServer->serverPort()),true);
		}
		connect(TCPServer,SIGNAL(SendMessage(QString)),this, SLOT(StampaMessaggioUtente(QString)));
		connect(this,SIGNAL(MessageFromServer(QString)),TCPServer,SIGNAL(SendMessage(QString)));
	}
	partito=true;
	disconnectRecieved=false;
	return true;
}
void ChatWidget::StampaMessaggioUtente(QString msg){
		PrintMessage(msg,false);
}
void ChatWidget::Connesso(){
	if(TCPsocket->isOpen()){
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		out << qint16(0) << tr("<b>%1 si � unito alla conversazione</b>").arg(UserName);
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		TCPsocket->write(block);
	}
}
void ChatWidget::Disconnesso(){
	if(!IsServer){
		if(TCPsocket->isOpen()){
			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_4_7);
			out << qint16(0) << tr("<b>%1 ha abbandonato la conversazione</b>").arg(UserName);
			out.device()->seek(0);
			out << quint16(block.size() - sizeof(quint16));
			TCPsocket->write(block);
		}
	}
	else {
		emit MessageFromServer(tr("<b>%1 ha abbandonato la conversazione</b>").arg(UserName));
	}
	reconnectButton->setVisible(true);
}
void ChatWidget::ErroreConnessione(){
	PrintMessage(tr("ERRORE!!!<br/>")+TCPsocket->errorString().toUtf8(),true);
	if(TCPsocket->isOpen())
		TCPsocket->close();
	reconnectButton->setVisible(true);
}

void ChatWidget::Inbox(){
	finito=false;
	QDataStream in(TCPsocket);
	in.setVersion(QDataStream::Qt_4_7);
	forever {
		if (nextBlockSize == 0) {
			if (TCPsocket->bytesAvailable() < sizeof(quint16))
				break;
			in >> nextBlockSize;
		}
		if (nextBlockSize == 0xFFFF) {
			nextBlockSize = 0;
			finito=true;
			break;
		}
		if (TCPsocket->bytesAvailable() < nextBlockSize)
			break;
		QString IncomingMessage;
		in >> IncomingMessage;
		emit MessageRecieved(IncomingMessage,false);
		nextBlockSize = 0;
	}
}

void ChatWidget::addSmile(int id){
	if (id<0 || id>Smiles::Num_Smiles) return;
	MessageText->textCursor().insertText(
		Smiles::smiles[id][0]
		);
}

void ChatWidget::sendMessage(){
	if (MessageText->toPlainText().isEmpty()) return;
	QDateTime timestamp(QDateTime::currentDateTime());
	QString result(
		QString("<html><font color=\"")+
		UserColor.name()+
		QString("\"><b>")+
		(ShowTimeStamp ? timestamp.time().toString("hh:mm:ss")+" - " : "")+
		UserName+
		QString("</b></font>: ")+
		ProcessaSmiles(MessageText->toPlainText())
		);
	MessageText->clear();

	//Online:
	if (partito){
		if(!IsServer){
			if(TCPsocket->isOpen()){
				QByteArray block;
				QDataStream out(&block, QIODevice::WriteOnly);
				out.setVersion(QDataStream::Qt_4_7);
				out << qint16(0) << result;
				out.device()->seek(0);
				out << quint16(block.size() - sizeof(quint16));
				TCPsocket->write(block);
			}
			else{
				emit MessageRecieved(result,false);
				emit MessageRecieved(tr("Messaggio non inviato! Nessun Server Connesso!"),true);
			}
		}
		else{
			emit MessageFromServer(result);
		}
	}
	else emit MessageRecieved(tr("Messaggio non inviato! Nessuna Connessione Avviata!"),true);
}

QString ChatWidget::ProcessaSmiles(const QString& str) const{
	QString result(str);
	result.replace("\n","<br/>");
	for (int i=0;i<Smiles::Num_Smiles;i++){
		result.replace(Smiles::smiles[i][0],Smiles::smiles[i][1]);
	}
	return result;
}

bool ChatWidget::eventFilter(QObject *target, QEvent *event){
	if(target==MessageText){
		if (event->type()==QEvent::KeyPress )
		{
			QKeyEvent* keyEvent=static_cast<QKeyEvent *>(event);
			if (keyEvent->key()==Qt::Key_Enter || keyEvent->key()==Qt::Key_Return){
				if(keyEvent->modifiers() & Qt::AltModifier)
					MessageText->textCursor().insertText("\n");
				else{
					sendMessage();
					return true;
				}
			}
			if (keyEvent->key()==Qt::Key_Tab){
				focusNextChild();
				return true;
			}
		}
	}
	return QWidget::eventFilter(target,event);
}

void ChatWidget::resizeEvent(QResizeEvent *event){
	QWidget::resizeEvent(event);
	selector->setGeometry(
		253-selector->sizeHint().width()+event->size().width()-341,
		159-selector->sizeHint().height()+event->size().height()-190,
		selector->width(),
		selector->height()
		);
}

void ChatWidget::closeEvent(QCloseEvent *event)
{
	Disconnesso();
	QTest::qWait(250);
	if(!IsServer){
		if(TCPsocket){
			if(TCPsocket->isOpen())
				TCPsocket->close();
		}
	}
	else{
		if(TCPServer) TCPServer->close();
	}
	event->accept();
}

void ChatWidget::connectionClosedByServer()
{
	if(!finito){
		if(TCPsocket->isOpen())
			TCPsocket->close();
		emit MessageRecieved(tr("<font color=\"red\">ERRORE!!!</font><br/><font color=\"red\">Connessione Chiusa dal Server</font>"),true);
	}
	reconnectButton->setVisible(true);
}
void ChatWidget::PrintMessage(QString msg, bool fromserv){
	if (fromserv){
		ChatText->append("<font color=\""+Colors::ServerColor.name()+"\">Server: " +msg +"</font>");
	}
	else ChatText->append(msg);
}