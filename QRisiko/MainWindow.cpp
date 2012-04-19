#include "MainWindow.h"
#include <QtGui>
MainWindow::MainWindow(QWidget* parent/* =0 */)
:QMainWindow(parent)
{
	QWidget* centralWidget = new QWidget(this);
	setObjectName("FinestraPrincipale");
	centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
	centralWidget->setMouseTracking(false);
	mappa=new QRisiko(this);
	chat=new ChatWidget(this,"Host",QColor(0,0,255,255),true,true/*false,"192.168.1.3"*/);
	chat->Avvia();
	QPushButton* CloseButton=new QPushButton(this);
	CloseButton->setText("Close");
	CloseButton->setMinimumSize(chat->minimumWidth(),chat->minimumHeight());
	connect(CloseButton,SIGNAL(clicked()),this,SLOT(close()));
	QFrame* BottomFrame=new QFrame(this);
	BottomFrame->setObjectName("BottomFrame");
	BottomFrame->setStyleSheet(
		"#BottomFrame {"
		//"border: 2px inset #555;"
		"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
		"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,"
		"stop: 0.39999 #717171, stop: 0.4 #626262,"
		"stop: 0.9 #4c4c4c, stop: 1 #333333);"
		"}"
		"#BottomFrame QPushButton {"
		"color: #333;"
		"border: 2px solid #555;"
		"border-radius: 11px;"
		"padding: 5px;"
		"background: qradialgradient(cx: 0.3, cy: -0.4,"
		"fx: 0.3, fy: -0.4,"
		"radius: 1.35, stop: 0 #fff, stop: 1 #888);"
		"}"

		"#BottomFrame QPushButton:hover {"
		"background: qradialgradient(cx: 0.3, cy: -0.4,"
		"fx: 0.3, fy: -0.4,"
		"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);"
		"}"

		"#BottomFrame QPushButton:pressed {"
		"background: qradialgradient(cx: 0.4, cy: -0.1,"
		"fx: 0.4, fy: -0.1,"
		"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);"
		"}"
	);
	QHBoxLayout* BottomPart=new QHBoxLayout(BottomFrame);
	BottomPart->addWidget(chat);
	BottomPart->addWidget(CloseButton);
	QGridLayout* MainLayout=new QGridLayout(centralWidget);
	MainLayout->setMargin(0);
	MainLayout->setSpacing(0);
	MainLayout->addWidget(mappa,0,0);
	MainLayout->addWidget(BottomFrame,1,0);
	setCentralWidget(centralWidget);
	resize(1024,768);
}
void MainWindow::closeEvent(QCloseEvent *event){
	chat->close();
	mappa->close();
	event->accept();
}