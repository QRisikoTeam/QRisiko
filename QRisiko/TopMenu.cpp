#include "TopMenu.h"
#include <QSpacerItem>
#include <QGridLayout>
#include <QSizePolicy>

TopMenu::TopMenu(QWidget* parent/* =0 */)
:QWidget(parent){

	setObjectName("TopMenu");
	setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
	QSizePolicy PoliticaBottoni(QSizePolicy::Expanding,QSizePolicy::Minimum);
	QGridLayout *Layout = new QGridLayout(this);
	Layout->setSpacing(20);
	OpzioniButton = new QPushButton(this);
	OpzioniButton->setObjectName("OpzioniButton");
	OpzioniButton->setMinimumSize(QSize(100, 40));
	OpzioniButton->setSizePolicy(PoliticaBottoni);

	Layout->addWidget(OpzioniButton,1,0);

	StatisticheButton = new QPushButton(this);
	StatisticheButton->setObjectName("StatisticheButton");
	StatisticheButton->setMinimumSize(QSize(100, 40));
	StatisticheButton->setSizePolicy(PoliticaBottoni);

	Layout->addWidget(StatisticheButton,1,1);

	RegolamentoButton = new QPushButton(this);
	RegolamentoButton->setObjectName("RegolamentoButton");
	RegolamentoButton->setMinimumSize(QSize(100, 40));
	RegolamentoButton->setSizePolicy(PoliticaBottoni);

	Layout->addWidget(RegolamentoButton,1,2);

	abortButton = new QPushButton(this);
	abortButton->setObjectName("abortButton");
	abortButton->setMinimumSize(QSize(100, 40));
	abortButton->setSizePolicy(PoliticaBottoni);

	Layout->addWidget(abortButton,1,3);

	AnnullaSchieramentoButton=new QPushButton(this);
	AnnullaSchieramentoButton->setObjectName("AnnullaSchieramentoButton");
	AnnullaSchieramentoButton->setMinimumSize(QSize(100, 40));
	AnnullaSchieramentoButton->setEnabled(false);
	AnnullaSchieramentoButton->setSizePolicy(PoliticaBottoni);

	Layout->addWidget(AnnullaSchieramentoButton,1,4);

	RiprendiButton=new QPushButton(this);
	RiprendiButton->setObjectName("RiprendiButton");
	RiprendiButton->setMinimumSize(QSize(100, 40));
	RiprendiButton->setSizePolicy(PoliticaBottoni);

	Layout->addWidget(RiprendiButton,1,5);

	OpzioniButton->setText(tr("Opzioni"));
	StatisticheButton->setText(tr("Statistiche"));
	RegolamentoButton->setText(tr("Regolamneto"));
	abortButton->setText(tr("Abbandona"));
	RiprendiButton->setText(tr("Riprendi"));
	AnnullaSchieramentoButton->setText(tr("Annulla Schieramento"));

	QSpacerItem* spazio=new QSpacerItem(20,20,QSizePolicy::Fixed,QSizePolicy::Fixed);

	Layout->addItem(spazio,0,0,1,1);

	Sfondo=new QFrame(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setGeometry(0,0,width(),height());
	Sfondo->lower();
	connect(OpzioniButton,SIGNAL(clicked()),this,SIGNAL(Opzioni()));
	connect(abortButton,SIGNAL(clicked()),this,SIGNAL(Abbandona()));
	connect(StatisticheButton,SIGNAL(clicked()),this,SIGNAL(Statistiche()));
	connect(RegolamentoButton,SIGNAL(clicked()),this,SIGNAL(Regolamento()));
	connect(AnnullaSchieramentoButton,SIGNAL(clicked()),this,SIGNAL(AnnullaSchieramento()));
	connect(RiprendiButton,SIGNAL(clicked()),this,SIGNAL(Riprendi()));
}

void TopMenu::resizeEvent(QResizeEvent * event){
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
}
void TopMenu::keyPressEvent(QKeyEvent *keyev){
	if(keyev->key()==Qt::Key_Escape){
		emit Riprendi();
	}
	else QWidget::keyPressEvent(keyev);
}