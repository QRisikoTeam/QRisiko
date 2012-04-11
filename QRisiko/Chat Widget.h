#ifndef CHATWIDGET_H
#define CHATWIDGET_H
#include <QDialog>
#include "ui_Chat.h"
#include "Smiles Selector.h"
#include "temp.h"
class ChatWidget : public QWidget, public Ui::Chat
{
	Q_OBJECT
	private:
		Player user;
		QString ProcessaSmiles(const QString& str) const;
		SmilesSelector* selector;
	public:
		ChatWidget(QWidget *parent = 0, Player player=Player("",QColor("#000000")));
	private slots:
		void sendMessage();
		void addSmile(int id);
};
#endif