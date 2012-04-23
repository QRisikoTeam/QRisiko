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
	Sfondo=new QLabel(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setScaledContents(true);
	Sfondo->setPixmap(QPixmap(":/Stati/Sfondo.png"));
	Sfondo->setGeometry(0,0,1024,574);
	Sfondo->lower();
	for (int i=0;i<ID_Stati::num_stati;i++){
		Stati[i]= new ImmagineCliccabile(i,this);
		Stati[i]->setObjectName("Stato_"+ID_Stati::Nomi_Stati[i]);
		Stati[i]->setContextMenuPolicy(Qt::NoContextMenu);
		politica.setHeightForWidth(Stati[i]->sizePolicy().hasHeightForWidth());
		Stati[i]->setSizePolicy(politica);
		Stati[i]->setGeometry(ID_Stati::PosData_Stati[i].rettangolo());
		Stati[i]->MostraImmagine();
		connect(Stati[i],SIGNAL(Cliccato(int)),this,SLOT(funziona(int)));
	}
}

void QRisiko::funziona(int identita){
	QMessageBox::warning(this, tr("Funziona"),tr((QString("Hai cliccato ")+ID_Stati::Nomi_Stati[identita]).toUtf8()));
}

void QRisiko::resizeEvent (QResizeEvent * event){
	QWidget::resizeEvent(event);
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
	for (int i=0;i<ID_Stati::num_stati;i++){
	int wid=int(
		double(event->size().width())
		*
		double(ID_Stati::PosData_Stati[i].dimensione().width())
		/
		double(ID_Stati::sp_mappa.dimensione().width()));
	int hei=int(
		double(event->size().height())
		*
		double(ID_Stati::PosData_Stati[i].dimensione().height())
		/
		double(ID_Stati::sp_mappa.dimensione().height()));
	double x=int(
		double(event->size().width())
		*
		double(ID_Stati::PosData_Stati[i].posizione().x())
		/
		double(ID_Stati::sp_mappa.dimensione().width()));
	double y=int(
		double(event->size().height())
		*
		double(ID_Stati::PosData_Stati[i].posizione().y())
		/
		double(ID_Stati::sp_mappa.dimensione().height()));
	Stati[i]->setGeometry(x,y,wid,hei);
	}
}
