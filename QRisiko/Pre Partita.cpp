#include "Pre Partita.h"
#include <QGridLayout>
#include <QSpacerItem>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QIcon>
#include <QLabel>
PrePartita::PrePartita(QWidget* parent/* =0 */)
:QWidget(parent)
,ContGiocatori(0)
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
	Interno=new QFrame(this);
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
	
	QGridLayout* ItemsLayout=new QGridLayout(Interno);
	QPixmap temp(QSize(20,20));
	for (int i=0;i<Giocatori::Max_Giocatori;i++){
		NomiGiocatori[i]=new QLineEdit(Interno);
		NomiGiocatori[i]->setObjectName(QString("Nome%1").arg(i+1));
		NomiGiocatori[i]->setText("");
		NomiGiocatori[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
		//NomiGiocatori[i]->hide();
		ColoriGiocatori[i]=new QComboBox(Interno);
		ColoriGiocatori[i]->setObjectName(QString("Colore%1").arg(i+1));
		ColoriGiocatori[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
		temp.fill(QColor(0,0,0,0));
		ColoriGiocatori[i]->addItem(temp,tr("Spettatore"),Giocatori::Spectator);
		for (int j=0;j<Giocatori::Max_Giocatori;j++){
			temp.fill(Giocatori::Colori[j]);
			ColoriGiocatori[i]->addItem(QIcon(temp),Giocatori::NomiColori[j],j);
		}
		//ColoriGiocatori[i]->hide();
		ItemsLayout->addWidget(NomiGiocatori[i],i,0);
		ItemsLayout->addWidget(ColoriGiocatori[i],i,1);
	}
	Sfondo=new QFrame(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setGeometry(0,0,width(),height());
	Interno->lower();
	Sfondo->lower();
}
void PrePartita::AggiuntoGiocatore(int ID, QString Nome){
	QString Temp=Nome;
	if (Temp=="") Temp=QString("Giocatore %1").arg(ContGiocatori+1);

}
void PrePartita::RimossoGiocatore(int ID){}
void PrePartita::resizeEvent(QResizeEvent *event){
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
	QWidget::resizeEvent(event);
}