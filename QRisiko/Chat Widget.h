#ifndef CHATWIDGET_H
#define CHATWIDGET_H
#include <QWidget>
#include <QTcpSocket>
#include "ui_Chat.h"
#include "Smiles Selector.h"
#include "Chat Server.h"
class ChatWidget : public QWidget, public Ui::Chat
{
	Q_OBJECT
	private:
		QString UserName;
		QColor UserColor;
		bool ShowTimeStamp;
		bool IsServer;
		QString Host;
		unsigned int port;
		QString ProcessaSmiles(const QString& str) const;
		SmilesSelector* selector;
		quint16 nextBlockSize;
		QTcpSocket* TCPsocket;
		ChatServer* TCPServer;
		void Disconnesso();
		bool finito;
		bool partito;
		bool disconnectRecieved;
		bool fistTime;
	public:
		ChatWidget(
			QWidget *parent=0,
			QString name="",
			QColor col=QColor(0,0,0,255),
			bool timestamp=true,
			bool server=false,
			QString hostIP="127.0.0.1",
			unsigned int por= 2200
			);
		void SetShowTimeStamp(const bool& a){ShowTimeStamp=a;}
		void SetIsServer(const bool& a){IsServer=a;}
		void SetHostIP(const QString& a){Host=a;}
		void SetPort(const unsigned int& a){port=a;}
		QString GetUserName() const {return UserName;}
		QColor GetUserColor() const {return UserColor;}
		bool GetShowTimeStamp() const {return ShowTimeStamp;}
		bool GetIsServer() const {return IsServer;}
		QString GetHostIP() const {return Host;}
		unsigned int GetPort() const {return port;}
	public slots:
		bool Avvia();
	private slots:
		void sendMessage();
		void addSmile(int id);
		void Connesso();
		void ErroreConnessione();
		void Inbox();
		void connectionClosedByServer();
		void PrintMessage(QString msg, bool fromserv=false);
		void StampaMessaggioUtente(QString msg);
	protected:
		bool eventFilter(QObject *target, QEvent *event);
		void resizeEvent(QResizeEvent *event);
		void closeEvent(QCloseEvent *event);
	signals:
		void MessageRecieved(QString Message, bool fromserver=false);
		void MessageFromServer(QString Message);
};
#endif