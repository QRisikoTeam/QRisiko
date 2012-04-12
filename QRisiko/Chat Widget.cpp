#include "Chat Widget.h"
#include "Chat Const.h"
#include <QtGui>

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
	MessageText->installEventFilter(this);
	connect(SendButton,SIGNAL(clicked()),this,SLOT(sendMessage()));
	ChatText->setHtml("");
	selector=new SmilesSelector(this);
	selector->setGeometry(253-selector->sizeHint().width()
		,159-selector->sizeHint().height()
		,selector->sizeHint().width(),
		selector->sizeHint().height());
	connect(SmilesButton,SIGNAL(clicked()),selector,SLOT(show_toggle()));
	connect(selector,SIGNAL(selected(int)),this,SLOT(addSmile(int))) ;
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

	ChatText->append(result);
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
	selector->setGeometry(253-selector->sizeHint().width()+event->size().width()-341,159-selector->sizeHint().height()+event->size().height()-194,selector->width(),selector->height());
}





