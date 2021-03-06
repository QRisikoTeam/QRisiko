#include "MainWindow.h"
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget* parent/* =0 */)
:QMainWindow(parent),
PrevWidget(NULL),
SelettoreServer(NULL),
Topmenu(NULL),
DurataAnimazioniMenu(1000),
ServerGioco(NULL),
ClientDiGioco(NULL)
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
	connect(MainMenu,SIGNAL(HostNew()),this,SLOT(MostraPrePartita()));
	connect(MainMenu,SIGNAL(HostNew()),this,SLOT(StartServer()));
	connect(MainMenu,SIGNAL(HostLoad()),this,SLOT(MostraPrePartita()));
	connect(MainMenu,SIGNAL(HostLoad()),this,SLOT(StartServer()));
	connect(MainMenu,SIGNAL(Join()),this,SLOT(MostraSelettoreServer()));
	connect(MainMenu,SIGNAL(Exit()),this,SLOT(close()));
	connect(MainMenu,SIGNAL(Rules()),this,SLOT(MostraRegolamento()));
	CurrWidget=MainMenu;

	regolamento=new Regolamento(TopFrame);
	regolamento->setObjectName("Regolamento");
	regolamento->hide();
	connect(regolamento,SIGNAL(Indietro()),this,SLOT(NascondiRegolamento()));

	Topmenu=new TopMenu(TopFrame);
	Topmenu->setObjectName("TopMenu");
	Topmenu->hide();
	Topmenu->resize(
		TopFrame->size().width()/2>Topmenu->sizeHint().width() ?
			TopFrame->size().width()/2
		:
			Topmenu->sizeHint().width()
		,Topmenu->sizeHint().height()
	);
	connect(Topmenu,SIGNAL(Riprendi()),this,SLOT(NascondiTopMenu()));
	connect(Topmenu,SIGNAL(Regolamento()),this,SLOT(NascondiTopMenu()));
	connect(Topmenu,SIGNAL(Regolamento()),this,SLOT(MostraRegolamento()));
	connect(Topmenu,SIGNAL(Opzioni()),this,SLOT(NascondiTopMenu()));
	connect(Topmenu,SIGNAL(Abbandona()),this,SLOT(NascondiTopMenu()));
	connect(Topmenu,SIGNAL(Abbandona()),this,SLOT(MostraMainMenu()));
	connect(Topmenu,SIGNAL(AnnullaSchieramento()),this,SLOT(NascondiTopMenu()));
	connect(Topmenu,SIGNAL(AnnullaSchieramento()),mappa,SLOT(ResetSchieramento()));
	connect(mappa,SIGNAL(PrimoPiazzato()),Topmenu,SLOT(EnableAnnullaSchieramentoButton()));
	connect(mappa,SIGNAL(TutteDaPiazzare()),Topmenu,SLOT(DisableAnnullaSchieramentoButton()));

	//TODO: Connetti

	SelettoreServer=new ServerSelector(TopFrame);
	SelettoreServer->setObjectName("SelettoreServer");
	SelettoreServer->hide();
	connect(MainMenu,SIGNAL(Join()),SelettoreServer,SLOT(Avvia()));
	connect(SelettoreServer,SIGNAL(Annullato()),this,SLOT(MostraMainMenu()));
	connect(SelettoreServer,SIGNAL(Selezionato(QString)),this,SLOT(StartClient(QString)));
	connect(SelettoreServer,SIGNAL(Selezionato(QString)),this,SLOT(MostraCaricamento(QString)));
	//connect(SelettoreServer,SIGNAL(Selezionato(QString)),this,SLOT(MostraPrePartita()));

	prePartita=new PrePartita(TopFrame);
	prePartita->setObjectName("PrePartita");
	prePartita->hide();
	connect(prePartita,SIGNAL(Annullato()),this,SLOT(MostraMainMenu()));
	connect(prePartita,SIGNAL(Annullato()),prePartita,SLOT(Azzera()));
	connect(prePartita,SIGNAL(InfoCambiate(QString,int)),this,SLOT(AggiornaChat(QString,int)));

	Avviso=new QFrame(TopFrame);
	Avviso->setObjectName("Avviso");
	QGridLayout* LayoutAvviso=new QGridLayout(Avviso);
	LayoutAvviso->setObjectName("LayoutAvviso");
	LayoutAvviso->setContentsMargins(12, 12, 12, 12);
	QHBoxLayout* LayoutAvvisoTop = new QHBoxLayout();
	LayoutAvvisoTop->setSpacing(12);
	LayoutAvvisoTop->setContentsMargins(12, 12, 12, 12);
	LayoutAvvisoTop->setObjectName("LayoutAvvisoTop");
	IconaAvviso = new QLabel(Avviso);
	IconaAvviso->setObjectName("IconaAvviso");
	IconaAvviso->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	IconaAvviso->setMaximumSize(QSize(40, 40));
	IconaAvviso->setMinimumSize(QSize(40, 40));
	IconaAvviso->setPixmap(QPixmap(":/Generale/BottoneErrore.png"));
	IconaAvviso->setScaledContents(true);
	AnimazioneAvviso=new QMovie(":/Generale/Loading.gif",QByteArray(),Avviso);
	LayoutAvvisoTop->addWidget(IconaAvviso);
	TestoAvviso = new QLabel(Avviso);
	TestoAvviso->setObjectName("TestoAvviso");
	TestoAvviso->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	TestoAvviso->setText(tr("Errore!"));
	LayoutAvvisoTop->addWidget(TestoAvviso);
	LayoutAvviso->addLayout(LayoutAvvisoTop, 0, 0, 1, 3);
	QSpacerItem* horizontalSpacer = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	QSpacerItem* horizontalSpacer_2 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	LayoutAvviso->addItem(horizontalSpacer, 1, 0, 1, 1);
	ChiudiAvviso = new QPushButton(Avviso);
	ChiudiAvviso->setObjectName("ChiudiAvviso");
	ChiudiAvviso->setText(tr("Ok"));
	ChiudiAvviso->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	connect(ChiudiAvviso,SIGNAL(clicked()),this,SLOT(NascondiAvviso()));
	LayoutAvviso->addWidget(ChiudiAvviso, 1, 1, 1, 1);
	LayoutAvviso->addItem(horizontalSpacer_2, 1, 2, 1, 1);
	Avviso->setGeometry((TopFrame->width()-Avviso->sizeHint().width())/2,(TopFrame->height()-Avviso->sizeHint().height())/2,Avviso->sizeHint().width(),Avviso->sizeHint().height());
	Avviso->hide();

	GestoreOnline=new GestoreServers(this);
	
	BottomFrame=new QFrame(this);
	BottomFrame->setObjectName("BottomFrame");
	BottomFrame->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
	BottomFrame->setStyleSheet(CSS::MainWindow_BottomFrameCSS);

	chat=new ChatWidget(BottomFrame);
	connect(chat,SIGNAL(DontSayEgitto()),mappa,SLOT(DontSayEgitto()));
	
	Log=new QTextEdit(BottomFrame);
	Log->setHtml("");
	Log->setMinimumSize(chat->minimumWidth(),chat->minimumHeight());
	Log->setObjectName("Log");

	QPushButton* CloseButton=new QPushButton(BottomFrame);
	CloseButton->setText("Close");
	CloseButton->setMinimumWidth(Giocatori::MinButtonSize.width());
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
	mappa->setGeometry(0,0,TopFrame->size().width(),TopFrame->size().height());
	MainMenu->move((TopFrame->size().width()-MainMenu->width())/2.0,(TopFrame->size().height()-MainMenu->height())/2.0);
	regolamento->setGeometry(
		(TopFrame->size().width()-SelettoreServer->width())/2.0,
		(TopFrame->size().height()-SelettoreServer->height())/2.0,
		TopFrame->size().width()/2,
		(TopFrame->size().height()*2)/3
	);
	SelettoreServer->setGeometry(
		(TopFrame->size().width()-SelettoreServer->width())/2.0,
		(TopFrame->size().height()-SelettoreServer->height())/2.0,
		TopFrame->size().width()/2,
		TopFrame->size().height()/2
	);
	prePartita->setGeometry(
		(TopFrame->size().width()-SelettoreServer->width())/2.0,
		(TopFrame->size().height()-SelettoreServer->height())/2.0,
		TopFrame->size().width()/2,
		TopFrame->size().height()/2
	);
	BottomFrameCover->setGeometry(QRect(QPoint(0,0),BottomFrame->size()));
}

void MainWindow::MostraMappa(){

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

	QParallelAnimationGroup *Animazioni=new QParallelAnimationGroup;
	Animazioni->addAnimation(animIn);
	Animazioni->addAnimation(animOut);
	connect(Animazioni,SIGNAL(finished()),this,SLOT(NascondiPrev()));

	mappa->show();

	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=mappa;
}

void MainWindow::MostraSelettoreServer(){
	
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

	SelettoreServer->show();
	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=SelettoreServer;
}
void MainWindow::MostraAvviso(const QString& Testo){
	ChiudiAvviso->show();
	IconaAvviso->setPixmap(QPixmap(":/Generale/BottoneErrore.png"));
	TestoAvviso->setText(Testo);
	mappa->setEnabled(false);
	MainMenu->setEnabled(false);
	Topmenu->setEnabled(false);
	regolamento->setEnabled(false);
	SelettoreServer->setEnabled(false);
	prePartita->setEnabled(false);
	BottomFrame->setEnabled(false);
	Avviso->setEnabled(true);
	QPropertyAnimation* animIn= new QPropertyAnimation(Avviso,"geometry",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::OutQuad);
	animIn->setKeyValueAt(0.0,QRect(TopFrame->width()/2,TopFrame->height()/2,0,0));
	animIn->setKeyValueAt(1.0,QRect((TopFrame->width()-Avviso->sizeHint().width())/2,(TopFrame->height()-Avviso->sizeHint().height())/2,Avviso->sizeHint().width(),Avviso->sizeHint().height()));
	Avviso->show();
	Avviso->raise();
	animIn->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::MostraCaricamento(const QString& Testo){
	QRegExp validatore("^([1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");
	if(validatore.exactMatch(Testo)) TestoAvviso->setText("Connessione in Corso...");
	else TestoAvviso->setText(Testo);
	ChiudiAvviso->hide();
	IconaAvviso->setMovie(AnimazioneAvviso);
	mappa->setEnabled(false);
	MainMenu->setEnabled(false);
	Topmenu->setEnabled(false);
	regolamento->setEnabled(false);
	SelettoreServer->setEnabled(false);
	prePartita->setEnabled(false);
	BottomFrame->setEnabled(false);
	BottomFrame->setEnabled(false);
	Avviso->setEnabled(true);
	AnimazioneAvviso->start();
	QPropertyAnimation* animIn= new QPropertyAnimation(Avviso,"geometry",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::OutQuad);
	animIn->setKeyValueAt(0.0,QRect(TopFrame->width()/2,TopFrame->height()/2,0,0));
	animIn->setKeyValueAt(1.0,QRect((TopFrame->width()-Avviso->sizeHint().width())/2,(TopFrame->height()-Avviso->sizeHint().height())/2,Avviso->sizeHint().width(),Avviso->sizeHint().height()));
	Avviso->show();
	Avviso->raise();
	animIn->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::NascondiAvviso(){
	mappa->setEnabled(true);
	MainMenu->setEnabled(true);
	Topmenu->setEnabled(true);
	regolamento->setEnabled(true);
	SelettoreServer->setEnabled(true);
	prePartita->setEnabled(true);
	BottomFrame->setEnabled(true);
	if(AnimazioneAvviso->state()==QMovie::Running) AnimazioneAvviso->stop();
	QPropertyAnimation* animIn= new QPropertyAnimation(Avviso,"geometry",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::InQuad);
	animIn->setKeyValueAt(1.0,QRect(TopFrame->width()/2,TopFrame->height()/2,0,0));
	animIn->setKeyValueAt(0.0,QRect((TopFrame->width()-Avviso->sizeHint().width())/2,(TopFrame->height()-Avviso->sizeHint().height())/2,Avviso->sizeHint().width(),Avviso->sizeHint().height()));
	connect(animIn,SIGNAL(finished()),Avviso,SLOT(hide()));
	animIn->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::MostraPrePartita(){

	QPropertyAnimation* animOut= new QPropertyAnimation(CurrWidget,"pos",TopFrame);
	animOut->setDuration((DurataAnimazioniMenu*(CurrWidget->pos().x()+CurrWidget->width()))/(TopFrame->width()+SelettoreServer->width()));
	animOut->setEasingCurve(QEasingCurve::Linear);
	animOut->setKeyValueAt(1.0,QPoint(-CurrWidget->width()-40,CurrWidget->pos().y()));
	animOut->setKeyValueAt(0.0,CurrWidget->pos());

	QPropertyAnimation* animIn= new QPropertyAnimation(prePartita,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::Linear);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->size().width()-prePartita->width())/2.0,(TopFrame->size().height()-prePartita->height())/2.0));
	animIn->setKeyValueAt(0.0,QPoint(TopFrame->width()+40,(TopFrame->size().height()-prePartita->height())/2.0));

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
	connect(Animazioni,SIGNAL(finished()),BottomFrameCover,SLOT(hide()));

	prePartita->show();
	BottomFrame->setEnabled(true);
	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=prePartita;
}

void MainWindow::MostraMainMenu(){
	
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
	if(!BottomFrameCover->isVisible()){
		BottomFrameCover->show();
		QPropertyAnimation* animInBottom= new QPropertyAnimation(BottomFrameCover,"pos",BottomFrame);
		animInBottom->setDuration(DurataAnimazioniMenu);
		animInBottom->setEasingCurve(QEasingCurve::Linear);
		animInBottom->setKeyValueAt(1.0,QPoint(0,0));
		animInBottom->setKeyValueAt(0.0,QPoint(BottomFrame->width()+40,0));
		Animazioni->addAnimation(animInBottom);
	}
	MainMenu->show();
	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	CurrWidget=MainMenu;
}
void MainWindow::NascondiRegolamento(){
	
	QPropertyAnimation* animOut= new QPropertyAnimation(regolamento,"pos",TopFrame);
	animOut->setDuration((DurataAnimazioniMenu*(TopFrame->size().width()+40-regolamento->pos().x()))/(40+(TopFrame->size().width()-PrevWidgetSizPos.dimensione().width())/2.0+PrevWidgetSizPos.dimensione().width()));
	animOut->setEasingCurve(QEasingCurve::Linear);
	animOut->setKeyValueAt(1.0,QPoint(TopFrame->size().width()+40,regolamento->pos().y()));
	animOut->setKeyValueAt(0.0,regolamento->pos());

	QPropertyAnimation* animIn= new QPropertyAnimation(PrevWidget,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::Linear);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->size().width()-PrevWidgetSizPos.dimensione().width())/2.0,(TopFrame->size().height()-PrevWidgetSizPos.dimensione().height())/2.0));
	animIn->setKeyValueAt(0.0,QPoint(-PrevWidget->width()-40,(TopFrame->size().height()-PrevWidgetSizPos.dimensione().height())/2.0));

	QParallelAnimationGroup *Animazioni=new QParallelAnimationGroup;
	Animazioni->addAnimation(animIn);
	Animazioni->addAnimation(animOut);
	connect(Animazioni,SIGNAL(finished()),this,SLOT(NascondiPrev()));

	PrevWidget->show();
	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	CurrWidget=PrevWidget;
	CurrWidget->setFocus();
	PrevWidget=regolamento;
}
void MainWindow::MostraRegolamento(){
	
	QPropertyAnimation* animOut= new QPropertyAnimation(CurrWidget,"pos",TopFrame);
	animOut->setDuration((DurataAnimazioniMenu*(40+CurrWidget->pos().x()+CurrWidget->width()))/(40+TopFrame->width()-((TopFrame->size().width()-regolamento->width())/2.0)));
	animOut->setEasingCurve(QEasingCurve::Linear);
	animOut->setKeyValueAt(1.0,QPoint(-CurrWidget->width()-40,CurrWidget->pos().y()));
	animOut->setKeyValueAt(0.0,CurrWidget->pos());

	QPropertyAnimation* animIn= new QPropertyAnimation(regolamento,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::Linear);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->size().width()-regolamento->width())/2.0,(TopFrame->size().height()-regolamento->height())/2.0));
	animIn->setKeyValueAt(0.0,QPoint(TopFrame->width()+40,(TopFrame->size().height()-regolamento->height())/2.0));

	QParallelAnimationGroup *Animazioni=new QParallelAnimationGroup;
	Animazioni->addAnimation(animIn);
	Animazioni->addAnimation(animOut);
	connect(Animazioni,SIGNAL(finished()),this,SLOT(NascondiPrev()));
	regolamento->show();

	Animazioni->start(QAbstractAnimation::DeleteWhenStopped);
	PrevWidget=CurrWidget;
	PrevWidgetSizPos.setDimensione(CurrWidget->size());
	PrevWidgetSizPos.setPosizione(CurrWidget->pos());
	CurrWidget=regolamento;
}

void MainWindow::NascondiTopMenu(){
	mappa->setEnabled(true);
	BottomFrame->setEnabled(true);
	QPropertyAnimation* animIn= new QPropertyAnimation(Topmenu,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::InBack);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->width()-Topmenu->width())/2,-Topmenu->height()));
	animIn->setKeyValueAt(0.0,Topmenu->pos());

	PrevWidget=Topmenu;
	connect(animIn,SIGNAL(finished()),this,SLOT(NascondiPrev()));
	animIn->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::MostraTopMenu(){
	if (mappa->GetFase()==QRisiko::Schieramento)
		Topmenu->ShowAnnullaSchieramentoButton();
	else Topmenu->HideAnnullaSchieramentoButton();
	mappa->setEnabled(false);
	BottomFrame->setEnabled(false);

	QPropertyAnimation* animIn= new QPropertyAnimation(Topmenu,"pos",TopFrame);
	animIn->setDuration(DurataAnimazioniMenu);
	animIn->setEasingCurve(QEasingCurve::OutBack);
	animIn->setKeyValueAt(1.0,QPoint((TopFrame->width()-Topmenu->width())/2,-20));
	animIn->setKeyValueAt(0.0,QPoint((TopFrame->width()-Topmenu->width())/2,-Topmenu->height()));
	Topmenu->show();
	animIn->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::keyPressEvent(QKeyEvent *keyev){
	if(keyev->key()==Qt::Key_Escape){
		if (mappa->IsContextMenuVisible())
			return mappa->NascondiMenuContestuale();
		if(mappa->isVisible()){
			if(!Topmenu->isVisible()) MostraTopMenu();
			else NascondiTopMenu();
		}
	}
	else QMainWindow::keyPressEvent(keyev);
}

void MainWindow::NascondiPrev(){
	PrevWidget->hide();
}

void MainWindow::StartClient(const QString& HostIP){
	if (ClientDiGioco) return;
	ClientDiGioco=new ClientGioco(HostIP,Comunicazioni::DefaultTCPPort,this);
	connect(ClientDiGioco,SIGNAL(Disconnesso()),this,SLOT(StopClient()),Qt::QueuedConnection);
	connect(ClientDiGioco,SIGNAL(Disconnesso()),this,SLOT(MostraMainMenu()));
	connect(prePartita,SIGNAL(SonoPronto()),ClientDiGioco,SLOT(SonoPronto()));
	connect(prePartita,SIGNAL(NonSonoPronto()),ClientDiGioco,SLOT(NonSonoPronto()));
	connect(prePartita,SIGNAL(InfoCambiate(QString,int)),ClientDiGioco,SLOT(CambiateMieInfo(QString,int)));
	connect(prePartita,SIGNAL(Annullato()),this,SLOT(StopClient()));
	connect(ClientDiGioco,SIGNAL(MyIDIs(int)),prePartita,SLOT(SetMyID(int)));
	connect(ClientDiGioco,SIGNAL(MyIDIs(int)),this,SLOT(MostraPrePartita()));
	connect(ClientDiGioco,SIGNAL(MyIDIs(int)),this,SLOT(NascondiAvviso()));
	connect(ClientDiGioco,SIGNAL(Errore(QString)),this,SLOT(MostraAvviso(QString)));
	connect(ClientDiGioco,SIGNAL(Errore(QString)),this,SLOT(StopClient()));
	connect(ClientDiGioco,SIGNAL(NuovoGiocatore(int)),prePartita,SLOT(AggiuntoGiocatoreID(int)));
	connect(ClientDiGioco,SIGNAL(GiocatoreDisconnesso(int)),prePartita,SLOT(RimossoGiocatore(int)));
	connect(ClientDiGioco,SIGNAL(StartGame()),this,SLOT(StartMatch()));
	connect(ClientDiGioco,SIGNAL(StartGame()),prePartita,SLOT(Azzera()));
	connect(ClientDiGioco,SIGNAL(AggiornaInfo(int,QString,int)),prePartita,SLOT(AggiornaInformazioni(int,QString,int)));
	ClientDiGioco->Connetti();
	chat->SetUserName(tr("Un Nuovo Giocatore"));
	chat->SetUserColor(Giocatori::ColoreSpettatore);
	chat->SetShowTimeStamp(false /*TODO da impostare in Opzioni*/);
	chat->SetIsServer(false);
	chat->SetHostIP(HostIP);
	chat->Avvia();
}
void MainWindow::StopClient(){
	chat->Ferma();
	if (!ClientDiGioco) return;
	ClientDiGioco->Disconnetti();
	qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
	//ClientDiGioco->disconnect(); //Disconnette tutti i signal e slot
	ClientDiGioco->deleteLater();
	ClientDiGioco=NULL;
}
void MainWindow::StartServer(){
	if (ServerGioco) return;
	prePartita->SetMyID(Comunicazioni::ServerID);
	ServerGioco=new GiocoServer("Server1" /*TODO da impostare in Opzioni*/,6 /*TODO da impostare in Opzioni*/, this);
	connect(ServerGioco,SIGNAL(NuovaConnessione(int)),prePartita,SLOT(AggiuntoGiocatoreID(int)));
	connect(prePartita,SIGNAL(SonoPronto()),ServerGioco,SLOT(ServerPronto()));
	connect(prePartita,SIGNAL(NonSonoPronto()),ServerGioco,SLOT(ServerNonPronto()));
	connect(prePartita,SIGNAL(InfoCambiate(QString,int)),ServerGioco,SLOT(CambiateInfoServer(QString,int)));
	connect(prePartita,SIGNAL(Annullato()),this,SLOT(StopServer()));
	connect(ServerGioco,SIGNAL(NuovaConnessione(int)),prePartita,SLOT(AggiuntoGiocatore(int,QString)));
	connect(ServerGioco,SIGNAL(Disconnesso(int)),prePartita,SLOT(RimossoGiocatore(int)));
	connect(ServerGioco,SIGNAL(StartGame()),this,SLOT(StartMatch()));
	connect(ServerGioco,SIGNAL(StartGame()),prePartita,SLOT(Azzera()));
	connect(ServerGioco,SIGNAL(UpdateInfo(int,QString,int)),prePartita,SLOT(AggiornaInformazioni(int,QString,int)));
	if( !ServerGioco->listen(QHostAddress::Any,Comunicazioni::DefaultTCPPort) ) QMessageBox::critical(TopFrame,tr("Errore nell'avvio del Server"),tr("Impossibile Associarsi alla porta specificata"));
	chat->SetUserName(tr("Un Nuovo Giocatore"));
	chat->SetUserColor(Giocatori::ColoreSpettatore);
	chat->SetShowTimeStamp(false /*TODO da impostare in Opzioni*/);
	chat->SetIsServer(true);
	chat->Avvia();
	ServerGioco->SegnalaGiocatoreServer();
}
void MainWindow::StopServer(){
	chat->Ferma();
//	if (!ServerGioco) return;
	//ServerGioco->disconnect(); //Disconnette tutti i signal e slot
	connect(ServerGioco,SIGNAL(RimossoIPDaLista()),ServerGioco,SLOT(deleteLater()));
	ServerGioco->Termina();
	ServerGioco=NULL;
}
void MainWindow::StartMatch(){
	
	//TODO Add Code
	MostraMappa();
}
void MainWindow::AggiornaChat(const QString& NuovoNome, int NuovoColore){
	if (NuovoNome=="" || NuovoColore<0 || NuovoColore>Giocatori::Max_Giocatori) return;
	chat->SetUserName(NuovoNome);
	if (NuovoColore==Giocatori::Spectator) chat->SetUserColor(Giocatori::ColoreSpettatore);
	else chat->SetUserColor(Giocatori::Colori[NuovoColore]);
}