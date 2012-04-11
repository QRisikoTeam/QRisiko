#include "Chat Widget.h"
#include "Chat Const.h"
#include <QtGui>

ChatWidget::ChatWidget(QWidget *parent, Player player)
:QWidget(parent), user(player)
{
	setupUi(this);
	connect(SendButton,SIGNAL(clicked()),this,SLOT(sendMessage()));
	ChatText->setHtml("");
	selector=new SmilesSelector(this);
	selector->setGeometry(MessageText->size().width(),this->size().height()-selector->sizeHint().height()-MessageText->size().height(),selector->sizeHint().width(),selector->sizeHint().height());
	connect(SmilesButton,SIGNAL(clicked()),selector,SLOT(show()));
	connect(selector,SIGNAL(selected(int)),this,SLOT(addSmile(int))) ;
}

void ChatWidget::addSmile(int id){
	if (id<0 || id>Smiles::Num_Smiles) return;
	MessageText->textCursor().insertText(
		Smiles::smiles[id][0]
		);
}

void ChatWidget::sendMessage(){
	QDateTime timestamp(QDateTime::currentDateTime());
	QString result(
		QString("<html><font color=\"")+
		user.GetColor().name()+
		QString("\"><b>")+
		timestamp.time().toString("hh:mm:ss")+
		QString(" - ")+
		user.GetName()+
		QString("</b></font>: ")+
		ProcessaSmiles(MessageText->toPlainText())
		);
	MessageText->clear();

	ChatText->append(result);
}

QString ChatWidget::ProcessaSmiles(const QString& str) const{
	QString result(str);
	for (int i=0;i<Smiles::Num_Smiles;i++){
		result.replace(Smiles::smiles[i][0],Smiles::smiles[i][1]);
	}
	return result;
}




