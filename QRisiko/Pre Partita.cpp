//Menu PrePartita Online
#include "Pre Partita.h"
#include <QGridLayout>
#include <QSpacerItem>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QIcon>
#include <QLabel>
#include <QScrollArea>
#include <QSpacerItem>
#include <QHBoxLayout>

#include <QtGui>

PrePartita::PrePartita(QWidget* parent)
:QWidget(parent)
,ContGiocatori(0)
,rowNumber(0)
,Duplicato(false)
{
	Pronto=new QPushButton(this);
	Pronto->setObjectName("ProntoButton");
	Pronto->setText("Pronto");
	Pronto->setDefault(true);
	Pronto->setCheckable(true);
	Pronto->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	Pronto->setMinimumSize(Giocatori::MinButtonSize);
	connect(Pronto,SIGNAL(clicked(bool)),this,SLOT(ready(bool)));
	connect(Pronto,SIGNAL(clicked(bool)),this,SLOT(disabilitaPronto(bool)));
	Annulla=new QPushButton(this);
	Annulla->setObjectName("AnnullaButton");
	Annulla->setText("Annulla");
	Annulla->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	Annulla->setMinimumSize(Giocatori::MinButtonSize);
	connect(Annulla,SIGNAL(clicked()),this,SLOT(MostraRUSure()));
	Interno=new QScrollArea(this);
	Interno->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	Interno->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	Interno->setObjectName("Interno");
	Interno->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	ImpostazioniLabel=new QLabel(this);
	ImpostazioniLabel->setObjectName("ImpostazioniLabel");
	ImpostazioniLabel->setText("Impostazioni Partita");
	ImpostazioniLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	ImpostazioniLabel->setBuddy(Interno);
	QSpacerItem* Spacer=new QSpacerItem(20,Annulla->sizeHint().height(),QSizePolicy::Expanding,QSizePolicy::Preferred);
	QGridLayout* WidgetLayout=new QGridLayout(this);
	WidgetLayout->setMargin(12);
	WidgetLayout->addWidget(ImpostazioniLabel,0,0);
	WidgetLayout->addWidget(Interno,1,0,1,3);
	WidgetLayout->addItem(Spacer,2,0);
	WidgetLayout->addWidget(Pronto,2,2);
	WidgetLayout->addWidget(Annulla,2,1);
	
	ItemsLayout=new QGridLayout(Interno);
	separatore=new QSpacerItem(20,20,QSizePolicy::Minimum,QSizePolicy::Expanding);
	ItemsLayout->addItem(separatore,0,0);
	
	Sfondo=new QFrame(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setGeometry(0,0,width(),height());
	Interno->lower();
	Sfondo->lower();

	RUSure=new QFrame(this);
	RUSure->setObjectName("SeiSicuro");
	QGridLayout* SeiSicuroLayout = new QGridLayout(RUSure);
	SeiSicuroLayout->setObjectName("SeiSicuroLayout");
	SeiSicuroLayout->setContentsMargins(12, 12, 12, 12);
	QHBoxLayout* SeiSicuroLayoutTop = new QHBoxLayout();
	SeiSicuroLayoutTop->setSpacing(12);
	SeiSicuroLayoutTop->setContentsMargins(12, 12, 12, 12);
	SeiSicuroLayoutTop->setObjectName("SeiSicuroLayoutTop");
	PuntoDiDomanda = new QLabel(RUSure);
	PuntoDiDomanda->setObjectName("PuntoDiDomanda");
	PuntoDiDomanda->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	PuntoDiDomanda->setMaximumSize(QSize(40, 40));
	PuntoDiDomanda->setMinimumSize(QSize(40, 40));
	PuntoDiDomanda->setPixmap(QPixmap(":/Generale/QuestionMark.png"));
	PuntoDiDomanda->setScaledContents(true);
	SeiSicuroLayoutTop->addWidget(PuntoDiDomanda);
	SeiSicuroLabel = new QLabel(RUSure);
	SeiSicuroLabel->setObjectName("SeiSicuroLabel");
	SeiSicuroLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	SeiSicuroLabel->setText(tr("Sei Sicuro di Voler<br>Abbandonare la Partita?"));
	SeiSicuroLayoutTop->addWidget(SeiSicuroLabel);
	SeiSicuroLayout->addLayout(SeiSicuroLayoutTop, 0, 0, 1, 3);
	QSpacerItem* horizontalSpacer = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	QSpacerItem* horizontalSpacer_2 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	SeiSicuroLayout->addItem(horizontalSpacer, 1, 0, 1, 1);
	QHBoxLayout* SeiSicuroLayoutBottom = new QHBoxLayout();
	SeiSicuroLayoutBottom->setSpacing(12);
	SeiSicuroLayoutBottom->setContentsMargins(12, 12, 12, 12);
	SeiSicuroLayoutBottom->setObjectName("SeiSicuroLayoutBottom");
	SonoSicuro = new QPushButton(RUSure);
	SonoSicuro->setObjectName("SonoSicuro");
	SonoSicuro->setText(tr("Si"));
	SonoSicuro->setMinimumSize(100,Giocatori::MinButtonSize.height());
	connect(SonoSicuro,SIGNAL(clicked()),this,SIGNAL(Annullato()));
	connect(SonoSicuro,SIGNAL(clicked()),this,SLOT(NascondiRUSure()));
	SeiSicuroLayoutBottom->addWidget(SonoSicuro);
	NonSonoSicuro = new QPushButton(RUSure);
	NonSonoSicuro->setObjectName("NonSonoSicuro");
	NonSonoSicuro->setText(tr("No"));
	NonSonoSicuro->setMinimumSize(100,Giocatori::MinButtonSize.height());
	connect(NonSonoSicuro,SIGNAL(clicked()),this,SLOT(NascondiRUSure()));
	SeiSicuroLayoutBottom->addWidget(NonSonoSicuro);
	SeiSicuroLayout->addLayout(SeiSicuroLayoutBottom, 1, 1, 1, 1);
	SeiSicuroLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);
	RUSure->setGeometry((width()-RUSure->sizeHint().width())/2,(height()-RUSure->sizeHint().height())/2,RUSure->sizeHint().width(),RUSure->sizeHint().height());
	RUSure->hide();


	//Test
	/*
	AggiuntoGiocatore(32,"Pippo");
	AggiuntoGiocatore(21,"Pluto");
	AggiuntoGiocatore(12,"Topolino");
	RimossoGiocatore(21);
	AggiuntoGiocatore(5,"Paperino");
	AggiuntoGiocatore(17,"Minnie");
	AggiuntoGiocatore(101,"Zio Paperone");
	AggiuntoGiocatore(6,"Batman");
	AggiuntoGiocatore(21,"Pluto");*/

}
void PrePartita::MostraRUSure(){
	RUSure->show();
	RUSure->raise();
	Pronto->setEnabled(false);
	Annulla->setEnabled(false);
	Interno->setEnabled(false);
	Sfondo->setEnabled(false);
	ImpostazioniLabel->setEnabled(false);
}
void PrePartita::NascondiRUSure(){
	RUSure->hide();
	Pronto->setEnabled(true);
	Annulla->setEnabled(true);
	Interno->setEnabled(true);
	Sfondo->setEnabled(true);
	ImpostazioniLabel->setEnabled(true);
}
void PrePartita::AggiuntoGiocatore(int ID, QString Nome){
	IDList.append(ID);
	QString Temp=Nome;
	QPixmap temp(QSize(20,20));
	if (Temp=="") Temp=QString("Giocatore %1").arg(ContGiocatori+1);
	NomiGiocatori.append(new QLineEdit(Interno));
	NomiGiocatori.last()->setText(Temp);
	
	NomiGiocatori.last()->setObjectName(QString("Nome%1").arg(NomiGiocatori.size()));
	NomiGiocatori.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
	NomiGiocatori.last()->setMinimumSize(NomiGiocatori.last()->sizeHint());
	ColoriGiocatori.append(new QComboBox(Interno));
	ColoriGiocatori.last()->setObjectName(QString("Colore%1").arg(ColoriGiocatori.size()));
	ColoriGiocatori.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
	ColoriGiocatori.last()->setMinimumSize(ColoriGiocatori.last()->sizeHint());
	temp.fill(QColor(0,0,0,0));
	ColoriGiocatori.last()->addItem(temp,tr("Spettatore"),Giocatori::Spectator);
	for (int j=0;j<Giocatori::Max_Giocatori;j++){
		temp.fill(Giocatori::Colori[j]);
		ColoriGiocatori.last()->addItem(QIcon(temp),Giocatori::NomiColori[j],j);
	}
	if (ID==MyID){
		NomiGiocatori.last()->setEnabled(true);
		connect(NomiGiocatori.last(),SIGNAL(textEdited(QString)),this,SLOT(CreaInformazioni()));
		connect(NomiGiocatori.last(),SIGNAL(textEdited(QString)),this,SLOT(ControllaDuplicati()));
		connect(NomiGiocatori.last(),SIGNAL(textEdited(QString)),this,SLOT(SetPlayerName(QString)));
		ColoriGiocatori.last()->setEnabled(true);
		connect(ColoriGiocatori.last(),SIGNAL(currentIndexChanged(int)),this,SLOT(CreaInformazioni()));
		connect(ColoriGiocatori.last(),SIGNAL(currentIndexChanged(int)),this,SLOT(ControllaDuplicati()));
		CreaInformazioni();
	}
	else{
		NomiGiocatori.last()->setEnabled(false);
		ColoriGiocatori.last()->setEnabled(false);
	}
	ItemsLayout->removeItem(separatore);
	ItemsLayout->addWidget(NomiGiocatori.last(),rowNumber,0);
	ItemsLayout->addWidget(ColoriGiocatori.last(),rowNumber,1);
	ItemsLayout->addItem(separatore,++rowNumber,0);
	ContGiocatori++;
	ControllaDuplicati();


}
void PrePartita::RimossoGiocatore(int ID){
	if(!IDList.contains(ID)) return;
	int Index=IDList.indexOf(ID);
	AggiungiColore(ColoriGiocatori.at(Index)->itemData(ColoriGiocatori.at(Index)->currentIndex()).toInt());
	IDList.removeAt(Index);
	if (Index<0 || Index>=ColoriGiocatori.size()) return;
	ItemsLayout->removeWidget(NomiGiocatori.at(Index));
	ItemsLayout->removeWidget(ColoriGiocatori.at(Index));
	//TODO Rows increase allways, removing a widget doesn't remove the row from the widget
	/*ItemsLayout->removeItem(separatore);
	for (int i=Index+1;i<ColoriGiocatori.size();i++){
		ItemsLayout->addWidget(NomiGiocatori.at(i),i-1,0);
		ItemsLayout->addWidget(ColoriGiocatori.at(i),i-1,1);
		ItemsLayout->removeWidget(NomiGiocatori.at(i));
		ItemsLayout->removeWidget(ColoriGiocatori.at(i));
	}
	ItemsLayout->addItem(separatore,ColoriGiocatori.size(),0);*/
	NomiGiocatori.at(Index)->deleteLater();
	ColoriGiocatori.at(Index)->deleteLater();
	NomiGiocatori.erase(NomiGiocatori.begin()+Index);
	ColoriGiocatori.erase(ColoriGiocatori.begin()+Index);
	ContGiocatori--;
}
void PrePartita::TogliColore(int ID, int ColorID){
	if (ColorID==Giocatori::Spectator) return;
	int Indice=IDList.indexOf(MyID);
	disconnect(ColoriGiocatori.at(Indice),SIGNAL(currentIndexChanged(int)),this,SLOT(CreaInformazioni()));
	bool tolto;
	for (int i=0;i<ColoriGiocatori.size();i++){
		tolto=false;
		//TODO Usa FindData
		for (int j=0;j<ColoriGiocatori.at(i)->count() && !tolto;j++){
			if (ColoriGiocatori.at(i)->itemData(j).toInt()==ColorID){
				if (ID!=IDList.at(i)){
					ColoriGiocatori.at(i)->removeItem(j);
					tolto=true;
				}
				else{
					ColoriGiocatori.at(i)->setCurrentIndex(j);
					tolto=true;
				}
			}
		}
		
	}
	connect(ColoriGiocatori.at(Indice),SIGNAL(currentIndexChanged(int)),this,SLOT(CreaInformazioni()));
}
void PrePartita::AggiungiColore(int ColorID){
	if (ColorID==Giocatori::Spectator) return;
	int Indice=IDList.indexOf(MyID);
	disconnect(ColoriGiocatori.at(Indice),SIGNAL(currentIndexChanged(int)),this,SLOT(CreaInformazioni()));
	QPixmap temp(QSize(20,20));
	for (int i=0;i<ColoriGiocatori.size();i++){
		if (ColoriGiocatori.at(i)->findData(ColorID)==-1){
			temp.fill(Giocatori::Colori[ColorID]);
			ColoriGiocatori.at(i)->insertItem(ColorID,QIcon(temp),Giocatori::NomiColori[ColorID],ColorID);
		}
	}
	connect(ColoriGiocatori.at(Indice),SIGNAL(currentIndexChanged(int)),this,SLOT(CreaInformazioni()));
}
void PrePartita::resizeEvent(QResizeEvent *event){
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
	RUSure->setGeometry((event->size().width()-RUSure->sizeHint().width())/2,(event->size().height()-RUSure->sizeHint().height())/2,RUSure->sizeHint().width(),RUSure->sizeHint().height());
	QWidget::resizeEvent(event);
}

void PrePartita::disabilitaPronto(bool pront){
	int Index=IDList.indexOf(MyID);
	ColoriGiocatori.at(Index)->setEnabled(!pront);
	NomiGiocatori.at(Index)->setEnabled(!pront);
}
void PrePartita::ControllaDuplicati(){
	int Index=IDList.indexOf(MyID);
	if (Index==-1) return;
	bool Trovato=false;
	for (int i=0;i<NomiGiocatori.size() && !Trovato;i++){
		if (
			(i!=Index && NomiGiocatori.at(i)->text()==NomiGiocatori.at(Index)->text())
			||(
				ColoriGiocatori.at(Index)->itemData(ColoriGiocatori.at(Index)->currentIndex()).toInt()!=Giocatori::Spectator
				&&
				(i!=Index && ColoriGiocatori.at(i)->itemData(ColoriGiocatori.at(i)->currentIndex()).toInt()==ColoriGiocatori.at(Index)->itemData(ColoriGiocatori.at(Index)->currentIndex()).toInt())
				)
			|| ColoriGiocatori.at(Index)->itemData(ColoriGiocatori.at(Index)->currentIndex()).toInt()==Giocatori::Spectator
			){
				Trovato=true;
		}
	}
	Duplicato=!Trovato;
	Pronto->setEnabled(!Trovato);
}
void PrePartita::ready(bool pront){
	if (pront) emit SonoPronto();
	else emit NonSonoPronto();
}
void PrePartita::CreaInformazioni(){
	int i;
	for (i=0;i<NomiGiocatori.size();i++){
		if (NomiGiocatori.at(i)->isEnabled()) break;
	}
	if (i==NomiGiocatori.size()) return;
	emit InfoCambiate(NomiGiocatori.at(i)->text(),ColoriGiocatori.at(i)->itemData(ColoriGiocatori.at(i)->currentIndex()).toInt());
}
void PrePartita::AggiornaInformazioni(int ident, const QString& NuovoNome, int NuovoColore){
	int Index=IDList.indexOf(ident);
	NomiGiocatori.at(Index)->setText(NuovoNome);
	AggiungiColore(ColoriGiocatori.at(Index)->itemData(ColoriGiocatori.at(Index)->currentIndex()).toInt());
	TogliColore(ident,NuovoColore);
}
void PrePartita::Azzera(){
	for (QList<int>::iterator i=IDList.begin();i!=IDList.end();i++){
		RimossoGiocatore(*i);
	}
	IDList.clear();
	NomiGiocatori.clear();
	ColoriGiocatori.clear();
}