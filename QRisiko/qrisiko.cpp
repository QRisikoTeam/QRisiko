#include "qrisiko.h"
#include <QtGui>

QRisiko::QRisiko(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
	QSizePolicy politica(QSizePolicy::Expanding, QSizePolicy::Expanding);
	politica.setHorizontalStretch(0);
	politica.setVerticalStretch(0);
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
		connect(Stati[i],SIGNAL(clicked(int)),this,SLOT(funziona(int)));
	}
}

void QRisiko::funziona(int identita){
	QMessageBox::warning(this, tr("Funziona"),tr((QString("Hai cliccato ")+ID_Stati::Nomi_Stati[identita]).toUtf8()));
}
