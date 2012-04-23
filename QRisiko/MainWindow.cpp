#include "MainWindow.h"
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget* parent/* =0 */)
:QMainWindow(parent),
PrevWidget(NULL),
SelettoreServer(NULL),
DurataAnimazioniMenu(1000)
{
	setObjectName("FinestraPrincipale");

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setObjectName("centralWidget");
	centralWidget->setMouseTracking(false);
	centralWidget->setStyleSheet(CSS::MainWindow_CentralCSS);

	TopFrame=new QFrame(this);
	TopFrame->setObjectName("TopFrame");
	TopFrame->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	TopFrame->setStyleSheet(CSS::MainWindow_TopFrame);

	mappa=new QRisiko(TopFrame);
	mappa->setObjectName("Mappa");
	mappa->hide();

	MainMenu=new MenuPrincipale(TopFrame);
	MainMenu->setObjectName("MenuPrincipale");
	connect(MainMenu,SIGNAL(HostLoad()),this,SLOT(MostraMappa()));
	connect(MainMenu,SIGNAL(Join()),this,SLOT(MostraSelettoreServer()));
	connect(MainMenu,SIGNAL(HostNew()),this,SLOT(MostraMappa()));
	connect(MainMenu,SIGNAL(Exit()),this,SLOT(close()));
	CurrWidget=MainMenu;
	
	BottomFrame=new QFrame(this);
	BottomFrame->setObjectName("BottomFrame");
	BottomFrame->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
	BottomFrame->setStyleSheet(CSS::MainWindow_BottomFrameCSS);

	chat=new ChatWidget(BottomFrame,"Host",QColor(0,0,255,255),true,true/*false,"192.168.1.3"*/);
	
	Log=new QTextEdit(BottomFrame);
	Log->setHtml("");
	Log->setMinimumSize(chat->minimumWidth(),chat->minimumHeight());
	Log->setObjectName("Log");

	QPushButton* CloseButton=new QPushButton(BottomFrame);
	CloseButton->setText("Close");
	CloseButton->setMinimumWidth(Giocatori::MinButtonWidth);
	CloseButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
	connect(CloseButton,SIGNAL(clicked()),this,SLOT(close()));

	QLabel* ChatLabel=new QLabel(BottomFrame);
	ChatLabel->setText("<b>Chat</b>");
	ChatLabel->setIndent(18);

	BottomFrame->setMaximumHeight(chat->minimumHeight()+ChatLabel->sizeHint().height()+30);

	QLabel* LogLabel=new QLabel(BottomFrame);
	LogLabel->setText("<b>Log</b>");

	QGridLayout* BottomPart=new QGridLayout(BottomFrame);
	BottomPart->addWidget(ChatLabel,0,0);
	BottomPart->addWidget(chat,1,0);
	BottomPart->addWidget(LogLabel,0,1);
	BottomPart->addWidget(Log,1,1);
	BottomPart->addWidget(CloseButton,0,2,2,1);

	QGridLayout* MainLayout=new QGridLayout(centralWidget);
	MainLayout->setMargin(0);
	MainLayout->setSpacing(0);
	MainLayout->addWidget(TopFrame,0,0);
	MainLayout->addWidget(BottomFrame,1,0);

	BottomFrame->setEnabled(false);
	BottomFrameCover=new QLabel(BottomFrame);
	BottomFrameCover->setObjectName("BottomFrameCover");
	BottomFrameCover->setGeometry(QRect(QPoint(0,0),BottomFrame->size()));
	BottomFrameCover->setAlignment(Qt::AlignCenter);
	BottomFrameCover->setText("RisiQo");
	BottomFrameCover->raise();

	setCentralWidget(centralWidget);
	resize(1024,768);
}
void MainWindow::closeEvent(QCloseEvent *event){
	chat->close();
	if(mappa) mappa->close();
	MainMenu->close();
	event->accept();
}
void MainWindow::resizeEvent(QResizeEvent *event){
	QMainWindow::resizeEvent(event);
	if(mappa) mappa->setGeometry(0,0,TopFrame->size().width(),TopFrame->size().height());
	MainMenu->move((TopFrame->size().width()-MainMenu->width())/2.0,(TopFrame->size().height()-MainMenu->height())/2.0);
	if(SelettoreServer) SelettoreServer->move((TopFrame->size().width()-SelettoreServer->width())/2.0,(TopFrame->size().height()-SelettoreServer->height())/2.0);
	BottomFrameCover->setGeometry(QRect(QPoint(0,0),BottomFrame->size()));
}

void MainWindow::MostraMappa(){

	mappa->show();
	QPropertyAnimation* animOut= new QPropertyAnimation(CurrWidget,"pos",TopFrame);
	animOut->setDuration((DurataAnimazioniMenu*(CurrWidget->pos().x()+CurrWidget->width()))/TopFrame->width());
	animOut->setEasingCurve(QEasingCurve::Linear);
	animOut->setKeyValueAt(1.0,QPoint(-CurrWidget->width()-40,CurrWidget->pos().y()));
	animOut->setKeyValueAt(0.0,CurrWidget->pos());

	QPropertyAnimation* animIn= new QPropertyAnimation(mappa,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::Linear);
	animIn->setKeyValueAt(1.0,QPoint(0,0));
	animIn->setKeyValueAt(0.0,QPoint(TopFrame->width()+40,0));

	QPropertyAnimation* animBottomOut= new QPropertyAnimation(BottomFrameCover,"pos",BottomFrame);
	animBottomOut->setDuration(DurataAnimazioniMenu);
	animBottomOut->setEasingCurve(QEasingCurve::Linear);
	animBottomOut->setKeyValueAt(1.0,QPoint(-BottomFrameCover->width()-40,BottomFrameCover->pos().y()));
	animBottomOut->setKeyValueAt(0.0,BottomFrameCover->pos());

	QParallelAnimationGroup *Animazioni=new QParallelAnimationGroup;
	Animazioni->addAnimation(animIn);
	Animazioni->addAnimation(animOut);
	Animazioni->addAnimation(animBottomOut);
	connect(Animazioni,SIGNAL(finished()),this,SLOT(NascondiPrev()));

	BottomFrame->setEnabled(true);
	chat->Avvia();

	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=mappa;
}

void MainWindow::MostraSelettoreServer(){
	if(!SelettoreServer){
		SelettoreServer=new ServerSelector(TopFrame);
		SelettoreServer->setObjectName("SelettoreServer");
		connect(SelettoreServer,SIGNAL(Annullato()),this,SLOT(MostraMainMenu()));
		connect(SelettoreServer,SIGNAL(Selezionato(QString)),this,SLOT(MostraMappa())); //DA MODIFICARE
	}
	SelettoreServer->show();

	QPropertyAnimation* animOut= new QPropertyAnimation(CurrWidget,"pos",TopFrame);
	animOut->setDuration((DurataAnimazioniMenu*(CurrWidget->pos().x()+CurrWidget->width()))/(TopFrame->width()+SelettoreServer->width()));
	animOut->setEasingCurve(QEasingCurve::Linear);
	animOut->setKeyValueAt(1.0,QPoint(-CurrWidget->width()-40,CurrWidget->pos().y()));
	animOut->setKeyValueAt(0.0,CurrWidget->pos());

	QPropertyAnimation* animIn= new QPropertyAnimation(SelettoreServer,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::Linear);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->size().width()-SelettoreServer->width())/2.0,(TopFrame->size().height()-SelettoreServer->height())/2.0));
	animIn->setKeyValueAt(0.0,QPoint(TopFrame->width()+40,(TopFrame->size().height()-SelettoreServer->height())/2.0));

	QParallelAnimationGroup *Animazioni=new QParallelAnimationGroup;
	Animazioni->addAnimation(animIn);
	Animazioni->addAnimation(animOut);
	connect(Animazioni,SIGNAL(finished()),this,SLOT(NascondiPrev()));

	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=SelettoreServer;
}

void MainWindow::MostraMainMenu(){
	MainMenu->show();
	QPropertyAnimation* animOut= new QPropertyAnimation(CurrWidget,"pos",TopFrame);
	animOut->setDuration((DurataAnimazioniMenu*(CurrWidget->pos().x()+CurrWidget->width()))/(TopFrame->width()+MainMenu->width()));
	animOut->setEasingCurve(QEasingCurve::Linear);
	animOut->setKeyValueAt(1.0,QPoint(-CurrWidget->width()-40,CurrWidget->pos().y()));
	animOut->setKeyValueAt(0.0,CurrWidget->pos());

	QPropertyAnimation* animIn= new QPropertyAnimation(MainMenu,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::Linear);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->size().width()-MainMenu->width())/2.0,(TopFrame->size().height()-MainMenu->height())/2.0));
	animIn->setKeyValueAt(0.0,QPoint(TopFrame->width()+40,(TopFrame->size().height()-MainMenu->height())/2.0));

	QParallelAnimationGroup *Animazioni=new QParallelAnimationGroup;
	Animazioni->addAnimation(animIn);
	Animazioni->addAnimation(animOut);
	connect(Animazioni,SIGNAL(finished()),this,SLOT(NascondiPrev()));

	BottomFrame->setEnabled(false);
	chat->Ferma();

	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=MainMenu;
}