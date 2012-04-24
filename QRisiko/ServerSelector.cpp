#include "ServerSelector.h"
#include "Costanti Nazioni.h"
#include <QRegExp>

ServerSelector::ServerSelector(QWidget* parent)
:QWidget(parent),
Parallelo(NULL)
{
	setupUi(this);

	Sfondo=new QFrame(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setGeometry(0,0,width(),height());
	Sfondo->lower();

	connect(connectButton,SIGNAL(clicked()),this,SLOT(OttieniIpSelezionato()));
	connect(cancelButton,SIGNAL(clicked()),this,SIGNAL(Annullato()));

	QStringList Etichette;
	Etichette.append(tr("Nome")); Etichette.append(tr("Giocatori")); Etichette.append("IP");
	TabellaServer->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	TabellaServer->setHorizontalHeaderLabels(Etichette);

	QRegExp validatore("^([1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");
	ManualInput->setValidator(new QRegExpValidator(validatore, this));

}
void ServerSelector::Avvia(){
	ListGetter=new GestoreServers(this);
	connect(ListGetter,SIGNAL(ListaOttenuta(QString)),this,SLOT(AvviaScansione(QString)));
	connect(ListGetter,SIGNAL(erroreConnessione()),this,SLOT(NoConnection()));
	ListGetter->OttieniLista();
}
void ServerSelector::NoConnection(){
	AggiornamentoLabel->setText(tr("Errore! Impossibile connettersi con il server."));
	AggiornamentoLabel->show();
}
void ServerSelector::resizeEvent(QResizeEvent * event){
	Sfondo->resize(event->size());
}

void ServerSelector::AvviaScansione(QString IPs){
	QStringList ListaIP=IPs.split("\n",QString::SkipEmptyParts);
	if (ListaIP.isEmpty()) {
		AggiornamentoLabel->hide();
		return;
	}
	Parallelo=new ServerSelectorThread(ListaIP,Comunicazioni::DefaultTCPPort,this);
	connect(Parallelo,SIGNAL(InfoRicevute(QString, int, int,QString)),this,SLOT(Popola(QString, int, int,QString)));
	connect(cancelButton,SIGNAL(clicked()),Parallelo,SLOT(stop()));
	connect(Parallelo,SIGNAL(finito()),AggiornamentoLabel,SLOT(hide()));
	Parallelo->start();
}

void ServerSelector::Popola(QString N, int GioOnline, int MaxGio, QString IP){


	TabellaServer->setSortingEnabled(false);
	int Riga=TabellaServer->rowCount();
	TabellaServer->setRowCount(Riga+1);

	QTableWidgetItem* Nome=TabellaServer->item(Riga,0);
	if(!Nome){
		Nome=new QTableWidgetItem;
		TabellaServer->setItem(Riga,0,Nome);
	}
	Nome->setData(Qt::DisplayRole,N);

	QTableWidgetItem* Giocat=TabellaServer->item(Riga,1);
	if(!Giocat){
		Giocat=new QTableWidgetItem;
		TabellaServer->setItem(Riga,1,Giocat);
	}
	Giocat->setData(Qt::DisplayRole,
		GioOnline<MaxGio ?
			QString ("%1/%2").arg(GioOnline,1,10,QChar(' ')).arg(MaxGio,1,10,QChar(' '))
		:
			QString ("<font color=\"red\">%1/%2</font>").arg(GioOnline,1,10,QChar(' ')).arg(MaxGio,1,10,QChar(' '))
		);

	QTableWidgetItem* CodiceIP=TabellaServer->item(Riga,2);
	if(!CodiceIP){
		CodiceIP=new QTableWidgetItem;
		TabellaServer->setItem(Riga,2,CodiceIP);
	}
	CodiceIP->setData(Qt::DisplayRole,IP);

	TabellaServer->setSortingEnabled(true);
}
void ServerSelector::OttieniIpSelezionato(){
	if (!TabellaServer->currentItem()) return;
	QString IPscelto=TabellaServer->item(TabellaServer->currentRow(),2)->data(Qt::DisplayRole).toString();
	if(Parallelo) Parallelo->stop();
	emit Selezionato(IPscelto);
}