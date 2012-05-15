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
PrePartita::PrePartita(int ID, const QString& PlNam, QWidget* parent)
:QWidget(parent)
,MyID(ID)
,ContGiocatori(0)
,PlayerName(PlNam)
{
	Pronto=new QPushButton(this);
	Pronto->setObjectName("ProntoButton");
	Pronto->setText("Pronto");
	Pronto->setDefault(true);
	Pronto->setCheckable(true);
	Pronto->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	Pronto->setMinimumSize(Giocatori::MinButtonSize);
	connect(Pronto,SIGNAL(clicked(bool)),this,SIGNAL(ready(bool)));
	Annulla=new QPushButton(this);
	Annulla->setObjectName("AnnullaButton");
	Annulla->setText("Annulla");
	Annulla->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	Annulla->setMinimumSize(Giocatori::MinButtonSize);
	connect(Annulla,SIGNAL(clicked()),this,SIGNAL(Annullato()));
	Interno=new QScrollArea(this);
	Interno->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
	AggiuntoGiocatore(MyID,PlayerName);
	
	Sfondo=new QFrame(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setGeometry(0,0,width(),height());
	Interno->lower();
	Sfondo->lower();
}
void PrePartita::AggiuntoGiocatore(int ID, QString Nome){
	IDList.append(ID);
	QString Temp=Nome;
	QPixmap temp(QSize(20,20));
	if (Temp=="") Temp=QString("Giocatore %1").arg(ContGiocatori+1);
	NomiGiocatori.append(new QLineEdit(Interno));
	NomiGiocatori.last()->setText(Temp);
	//NomiGiocatori.last()->setMaximumHeight(50);
	if (ID==MyID) NomiGiocatori.last()->setEnabled(true);
	else NomiGiocatori.last()->setEnabled(false);
	NomiGiocatori.last()->setObjectName(QString("Nome%1").arg(NomiGiocatori.size()));
	NomiGiocatori.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
	ColoriGiocatori.append(new QComboBox(Interno));
	//ColoriGiocatori.last()->setMaximumHeight(80);
	if (ID==MyID) ColoriGiocatori.last()->setEnabled(true);
	else ColoriGiocatori.last()->setEnabled(false);
	ColoriGiocatori.last()->setObjectName(QString("Colore%1").arg(ColoriGiocatori.size()));
	ColoriGiocatori.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
	temp.fill(QColor(0,0,0,0));
	ColoriGiocatori.last()->addItem(temp,tr("Spettatore"),Giocatori::Spectator);
	for (int j=0;j<Giocatori::Max_Giocatori;j++){
		temp.fill(Giocatori::Colori[j]);
		ColoriGiocatori.last()->addItem(QIcon(temp),Giocatori::NomiColori[j],j);
	}
	ItemsLayout->removeItem(separatore);
	ItemsLayout->addWidget(NomiGiocatori.last(),NomiGiocatori.size()-1,0);
	ItemsLayout->addWidget(ColoriGiocatori.last(),ColoriGiocatori.size()-1,1);
	ItemsLayout->addItem(separatore,ColoriGiocatori.size(),0);



}
void PrePartita::RimossoGiocatore(int ID){
	int Index=IDList.indexOf(ID);
	if (Index<0) return;
	ItemsLayout->removeWidget(NomiGiocatori.at(Index));
	ItemsLayout->removeWidget(ColoriGiocatori.at(Index));
	NomiGiocatori.erase(NomiGiocatori.begin()+Index);
	ColoriGiocatori.erase(ColoriGiocatori.begin()+Index);
	NomiGiocatori.at(Index)->deleteLater();
	ColoriGiocatori.at(Index)->deleteLater();
}
void PrePartita::TogliColore(int ID, int ColorID){
	if (ColorID==Giocatori::Spectator) return;
	bool tolto=false;
	for (int i=0;i<ColoriGiocatori.size();i++){
		if (ID!=IDList.at(i)){
			for (int j=0;j<ColoriGiocatori.at(i)->count() && !tolto;j++){
				if (ColoriGiocatori.at(i)->itemData(j)==ColorID){
					ColoriGiocatori.at(i)->removeItem(j);
					tolto=true;
				}
			}
		}
	}
}
void PrePartita::AggiungiColore(int ColorID){
	if (ColorID==Giocatori::Spectator) return;
	QPixmap temp(QSize(20,20));
	for (int i=0;i<ColoriGiocatori.size();i++){
		if (ColoriGiocatori.at(i)->findData(ColorID)==-1){
			temp.fill(Giocatori::Colori[ColorID]);
			ColoriGiocatori.at(i)->addItem(QIcon(temp),Giocatori::NomiColori[ColorID],ColorID);
		}
	}
}
void PrePartita::resizeEvent(QResizeEvent *event){
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
	QWidget::resizeEvent(event);
}