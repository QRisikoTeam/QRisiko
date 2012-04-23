#include "MainMenu.h"
#include "Costanti Nazioni.h"
#include <QSpacerItem>

MenuPrincipale::MenuPrincipale(QWidget *parent)
:QWidget(parent)
{
	setObjectName("MenuPrincipale");
	setWindowTitle(tr("MenuPrincipale"));
	setMaximumSize(512, 574);
	resize(512, 574);
	
	Simbolo = new QLabel(this);
	Simbolo->setObjectName("Simbolo");
	Simbolo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	Simbolo->setMinimumSize(QSize(400, 160));
	Simbolo->setMaximumSize(QSize(400, 160));
	Simbolo->setPixmap(QPixmap(":/Generale/Resources/Simbolo.png"));
	Simbolo->setScaledContents(true);

	HostLoadButton = new QPushButton(this);
	HostLoadButton->setObjectName("HostLoadButton");
	HostLoadButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	HostLoadButton->setMinimumSize(QSize(130, 50));
	HostLoadButton->setText(tr("Ospita una\nPartita Salvata"));
	connect(HostLoadButton,SIGNAL(clicked()),this,SIGNAL(HostLoad()));

	JoinButton = new QPushButton(this);
	JoinButton->setObjectName("JoinButton");
	JoinButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	JoinButton->setMinimumSize(QSize(130, 50));
	JoinButton->setText(tr("Unisciti ad\nuna Partita"));
	connect(JoinButton,SIGNAL(clicked()),this,SIGNAL(Join()));

	HostNewButton = new QPushButton(this);
	HostNewButton->setObjectName("HostNewButton");
	HostNewButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	HostNewButton->setMinimumSize(QSize(130, 50));
	HostNewButton->setText(tr("Ospita una\nNuova Partita"));
	connect(HostNewButton,SIGNAL(clicked()),this,SIGNAL(HostNew()));

	OptionButton = new QPushButton(this);
	OptionButton->setObjectName("OptionButton");
	OptionButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	OptionButton->setMinimumSize(QSize(130, 50));
	OptionButton->setText(tr("Opzioni"));
	connect(OptionButton,SIGNAL(clicked()),this,SIGNAL(Option()));

	AboutButton = new QPushButton(this);
	AboutButton->setObjectName("AboutButton");
	AboutButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	AboutButton->setMinimumSize(QSize(130, 50));
	AboutButton->setText(tr("Info"));
	connect(AboutButton,SIGNAL(clicked()),this,SIGNAL(About()));

	RulesButton = new QPushButton(this);
	RulesButton->setObjectName("RulesButton");
	RulesButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	RulesButton->setMinimumSize(QSize(130, 50));
	RulesButton->setText(tr("Regolamento"));
	connect(RulesButton,SIGNAL(clicked()),this,SIGNAL(Rules()));

	ExitButton = new QPushButton(this);
	ExitButton->setObjectName("ExitButton");
	ExitButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	ExitButton->setMinimumSize(QSize(337, 50));
	ExitButton->setText(tr("Esci"));
	connect(ExitButton,SIGNAL(clicked()),this,SIGNAL(Exit()));

	QSpacerItem *SimbolHSpacerL=new QSpacerItem(56,20,QSizePolicy::Preferred,QSizePolicy::Minimum);
	QSpacerItem *SimbolHSpacerR=new QSpacerItem(56,20,QSizePolicy::Preferred,QSizePolicy::Minimum);
	QSpacerItem *SimbolVSpacerT=new QSpacerItem(20,49,QSizePolicy::Minimum,QSizePolicy::Preferred);
	QSpacerItem *SimbolVSpacerM=new QSpacerItem(20,48,QSizePolicy::Minimum,QSizePolicy::Preferred);
	QSpacerItem *SimbolVSpacerB=new QSpacerItem(20,49,QSizePolicy::Minimum,QSizePolicy::Preferred);

	gridLayout = new QGridLayout(this); //8x5
	gridLayout->setObjectName("gridLayout");
	gridLayout->addItem(SimbolVSpacerT, 0, 0, 1, 5);
	gridLayout->addItem(SimbolHSpacerL, 1, 0, 7, 1);
	gridLayout->addItem(SimbolHSpacerR, 1, 4, 7, 1);
	gridLayout->addWidget(Simbolo, 1, 1, 1, 3);
	gridLayout->addItem(SimbolVSpacerM, 2, 0, 1, 5);
	gridLayout->addWidget(HostNewButton, 3, 1, 1, 1);
	gridLayout->addWidget(JoinButton, 3, 3, 1, 1);
	gridLayout->addWidget(HostLoadButton, 4, 1, 1, 1);
	gridLayout->addWidget(OptionButton, 4, 3, 1, 1);
	gridLayout->addWidget(RulesButton, 5, 1, 1, 1);
	gridLayout->addWidget(AboutButton, 5, 3, 1, 1);
	gridLayout->addWidget(ExitButton, 6, 1, 1, 3);
	gridLayout->addItem(SimbolVSpacerB, 7, 0, 1, 5);
	
	Sfondo=new QFrame(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setGeometry(0,0,width(),height());
	Sfondo->lower();
	
}
void MenuPrincipale::resizeEvent(QResizeEvent *event){
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
}