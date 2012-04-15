#include "qrisiko.h"
#include <QtGui>

QRisiko::QRisiko(QWidget *parent)
: QWidget(parent)
{
	gestoreServer= new GestoreServers(this);
	setObjectName(QString::fromUtf8("MappaDiGioco"));
	QSizePolicy politica(QSizePolicy::Expanding, QSizePolicy::Expanding);
	politica.setHorizontalStretch(0);
	politica.setVerticalStretch(0);
	politica.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
	setSizePolicy(politica);
	setMinimumSize(QSize(800, 448));
	setMouseTracking(false);
	setContextMenuPolicy(Qt::NoContextMenu);
	resize(1024, 574);
	Sfondo=new QFrame(this);
	Sfondo->setGeometry(0,0,1024,574);
	Sfondo->setStyleSheet("background-color: #84B4E4;");
	Sfondo->lower();
	for (int i=0;i<ID_Stati::num_stati;i++){
		Stati[i]= new ImmagineCliccabile(this,i);
		Stati[i]->setObjectName("Stato_"+ID_Stati::Nomi_Stati[i]);
		Stati[i]->setContextMenuPolicy(Qt::NoContextMenu);
		politica.setHeightForWidth(Stati[i]->sizePolicy().hasHeightForWidth());
		Stati[i]->setSizePolicy(politica);
		Stati[i]->setPixmap(QPixmap(ID_Stati::img_Stati[i]));
		Stati[i]->setScaledContents(true);
		Stati[i]->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
		Stati[i]->setGeometry(ID_Stati::PosData_Stati[i].rettangolo());
		connect(this,SIGNAL(resized(QSize)),Stati[i],SLOT(Redimensiona(QSize)));
	}
	connect(this,SIGNAL(cliccato(int)),this,SLOT(funziona(int)));
}

void QRisiko::funziona(int identita){
	QMessageBox::warning(this, tr("Funziona"),tr((QString("Hai cliccato ")+ID_Stati::Nomi_Stati[identita]).toUtf8()));
}
void QRisiko::mousePressEvent(QMouseEvent *event){
	if (event->button()==Qt::LeftButton){
		for (int i=0;i<ID_Stati::num_stati;i++){
			if(Stati[i]->isEnabled() && Stati[i]->geometry().contains(event->pos(),true)){
				if (!Stati[i]->IsTransparent(event->pos()-Stati[i]->pos()))
					emit cliccato(i);
			}
		}
	}
}
void QRisiko::resizeEvent (QResizeEvent * event){
	QWidget::resizeEvent(event);
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
	emit resized(event->size());
}
void QRisiko::setStyleSheet(const QString& stsh){
	Sfondo->setStyleSheet("background-color: #84B4E4;"+stsh);
}