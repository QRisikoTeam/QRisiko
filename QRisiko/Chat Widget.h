#ifndef CHATWIDGET_H
#define CHATWIDGET_H
#include <QDialog>
#include "ui_Chat.h"
#include "Smiles Selector.h"
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
	public:
		ChatWidget(
			QWidget *parent,
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
	private slots:
		void sendMessage();
		void addSmile(int id);
	protected:
		bool eventFilter(QObject *target, QEvent *event);
		void resizeEvent(QResizeEvent *event);
};
#endif