#include "MainWindow.h"
#include <QtGui>
MainWindow::MainWindow(QWidget* parent/* =0 */)
:QMainWindow(parent)
{
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
	centralWidget->setMouseTracking(false);
	mappa=new QRisiko(this);
	mappa->setStyleSheet("border-radius: 50px;");
	chat=new ChatWidget(this,"Il Beldus",QColor(0,0,255,255),true,true);
	chat->Avvia();
	QPushButton* CloseButton=new QPushButton(this);
	CloseButton->setText("Close");
	CloseButton->setMinimumSize(chat->minimumWidth(),chat->minimumHeight());
	connect(CloseButton,SIGNAL(clicked()),this,SLOT(close()));
	QGridLayout* MainLayout=new QGridLayout(centralWidget);
	MainLayout->addWidget(mappa,0,0,1,2);
	MainLayout->addWidget(chat,1,0,1,1);
	MainLayout->addWidget(CloseButton,1,1,1,1);
	setCentralWidget(centralWidget);
	resize(1024,768);
}