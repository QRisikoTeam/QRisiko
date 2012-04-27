#include "qrisiko.h"
#include <QtGui>

QRisiko::QRisiko(QWidget *parent)
: QWidget(parent)
//Test
,Player("Luca",Giocatore::Giallo)
,fase(Not_My_Turn)
,ArmiesToPlace(10)
{
	gestoreServer= new GestoreServers(this);
	setObjectName(QString::fromUtf8("MappaDiGioco"));
	QSizePolicy politica(QSizePolicy::Expanding, QSizePolicy::Expanding);
	politica.setHorizontalStretch(0);
	politica.setVerticalStretch(0);
	politica.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
	setSizePolicy(politica);
	setMinimumSize(QSize(800, 448));
	setMouseTracking(false);
	setContextMenuPolicy(Qt::NoContextMenu);
	resize(1024, 574);
	Sfondo=new QLabel(this);
	Sfondo->setObjectName("Sfondo");
	Sfondo->setScaledContents(true);
	Sfondo->setPixmap(QPixmap(":/Stati/Sfondo.png"));
	Sfondo->setGeometry(0,0,1024,574);
	Sfondo->lower();
	for (int i=0;i<ID_Stati::num_stati;i++){
		Stati[i]= new ImmagineCliccabile(i,this);
		Stati[i]->setObjectName("Stato_"+ID_Stati::Nomi_Stati[i]);
		Stati[i]->setContextMenuPolicy(Qt::NoContextMenu); //TODO Implement Custom
		politica.setHeightForWidth(Stati[i]->sizePolicy().hasHeightForWidth());
		Stati[i]->setSizePolicy(politica);
		Stati[i]->setGeometry(ID_Stati::PosData_Stati[i].rettangolo());
		Stati[i]->MostraImmagine();
		Stati[i]->setCheckable(true);
		Stati[i]->SetNoArmate(1);
		//test
		if(i%2==0)
			Stati[i]->SetOwner(Giocatore::Giallo);
		else
			Stati[i]->SetOwner(Giocatore::Verde);
		
		connect(Stati[i],SIGNAL(Cliccato(bool,int)),this,SLOT(funziona(bool,int)));
	}
	Popola_ID_Attaccabili();
	ProssimaFase();
}

void QRisiko::funziona(bool che, int identita){
	QMessageBox::information(this, "Cliccato", QString("Hai Cliccato: %1\nCheched: %2").arg(ID_Stati::Nomi_Stati[identita]).arg(che));
	switch(fase){
		case Attacco:
			if(che){
				AttackFrom_ID=identita;
				for (int i=0;i<ID_Stati::num_stati;i++){
					if(i!=identita) Stati[i]->setCheckable(false);
					if(Stati[i]->GetOwner()!=Player.GetColorID())
						Stati[i]->setResponsive(true);
					else
						{if (i!=identita) Stati[i]->setResponsive(false);}
				}
			}
			else{
				if(AttackFrom_ID==identita){
					AttackFrom_ID=-1;
					for (int i=0;i<ID_Stati::num_stati;i++){
						Stati[i]->setCheckable(true);
						if(Stati[i]->GetOwner()==Player.GetColorID())
							Stati[i]->setResponsive(true);
						else
							Stati[i]->setResponsive(false);
					}
				}
				else{
					bool Confina=false;
					for (
						QVector<short>::iterator i=ID_Attaccabili[AttackFrom_ID].begin();
						!Confina && i<ID_Attaccabili[AttackFrom_ID].end();
						i++
					) if(*i==identita) Confina=true;
					if (Confina){
						emit Attaccato(AttackFrom_ID,identita);
						AttackFrom_ID=-1;
						for (int i=0;i<ID_Stati::num_stati;i++){
							Stati[i]->setCheckable(true);
							Stati[i]->setChecked(false);
							if(Stati[i]->GetOwner()==Player.GetColorID())
								Stati[i]->setResponsive(true);
							else
								Stati[i]->setResponsive(false);
						}
					}
				}
			}
			break;
		case Schieramento:
			Aggiunte[identita]++;
			break;

		
		default: return;
	}
}

void QRisiko::resizeEvent (QResizeEvent * event){
	QWidget::resizeEvent(event);
	Sfondo->setGeometry(0,0,event->size().width(),event->size().height());
	for (int i=0;i<ID_Stati::num_stati;i++){
	int wid=int(
		double(event->size().width())
		*
		double(ID_Stati::PosData_Stati[i].dimensione().width())
		/
		double(ID_Stati::sp_mappa.dimensione().width()));
	int hei=int(
		double(event->size().height())
		*
		double(ID_Stati::PosData_Stati[i].dimensione().height())
		/
		double(ID_Stati::sp_mappa.dimensione().height()));
	double x=int(
		double(event->size().width())
		*
		double(ID_Stati::PosData_Stati[i].posizione().x())
		/
		double(ID_Stati::sp_mappa.dimensione().width()));
	double y=int(
		double(event->size().height())
		*
		double(ID_Stati::PosData_Stati[i].posizione().y())
		/
		double(ID_Stati::sp_mappa.dimensione().height()));
	Stati[i]->setGeometry(x,y,wid,hei);
	}
}

void QRisiko::Popola_ID_Attaccabili(){
		using namespace ID_Stati;
		//Id attaccabili da:
		//Asia
		QVector<short> Att_giappone;
		Att_giappone.append(kamchatka);
		Att_giappone.append(mongolia);
		ID_Attaccabili[giappone]=Att_giappone;
		QVector<short> Att_afganistan;
		Att_afganistan.append(ucraina);
		Att_afganistan.append(medio_oriente);
		Att_afganistan.append(urali);
		Att_afganistan.append(india);
		Att_afganistan.append(cina);
		ID_Attaccabili[afganistan]=Att_afganistan;
		QVector<short> Att_urali;
		Att_urali.append(ucraina);
		Att_urali.append(afganistan);
		Att_urali.append(siberia);
		Att_urali.append(cina);
		ID_Attaccabili[urali]=Att_urali;
		QVector<short> Att_siberia;
		Att_siberia.append(cita);
		Att_siberia.append(mongolia);
		Att_siberia.append(urali);
		Att_siberia.append(jacuzia);
		Att_siberia.append(cina);
		ID_Attaccabili[siberia]=(Att_siberia);
		QVector<short> Att_jacuzia;
		Att_jacuzia.append(cita);
		Att_jacuzia.append(siberia);
		Att_jacuzia.append(kamchatka);
		ID_Attaccabili[jacuzia]=Att_jacuzia;
		QVector<short> Att_kamchatka;
		Att_kamchatka.append(cita);
		Att_kamchatka.append(jacuzia);
		Att_kamchatka.append(mongolia);
		Att_kamchatka.append(giappone);
		Att_kamchatka.append(alaska);
		ID_Attaccabili[kamchatka]=Att_kamchatka;
		QVector<short> Att_cita;
		Att_cita.append(kamchatka);
		Att_cita.append(jacuzia);
		Att_cita.append(mongolia);
		Att_cita.append(siberia);
		ID_Attaccabili[cita]=Att_cita;
		QVector<short> Att_mongolia;
		Att_mongolia.append(cita);
		Att_mongolia.append(siberia);
		Att_mongolia.append(kamchatka);
		Att_mongolia.append(giappone);
		Att_mongolia.append(cina);
		ID_Attaccabili[mongolia]=Att_mongolia;
		QVector<short> Att_cina;
		Att_cina.append(siam);
		Att_cina.append(india);
		Att_cina.append(mongolia);
		Att_cina.append(afganistan);
		Att_cina.append(urali);
		Att_cina.append(siberia);
		ID_Attaccabili[cina]=Att_cina;
		QVector<short> Att_medio_oriente;
		Att_medio_oriente.append(ucraina);
		Att_medio_oriente.append(europa_meridionale);
		Att_medio_oriente.append(egitto);
		Att_medio_oriente.append(afganistan);
		Att_medio_oriente.append(india);
		ID_Attaccabili[medio_oriente]=Att_medio_oriente;
		QVector<short> Att_india;
		Att_india.append(medio_oriente);
		Att_india.append(siam);
		Att_india.append(cina);
		Att_india.append(afganistan);
		ID_Attaccabili[india]=Att_india;
		QVector<short> Att_siam;
		Att_siam.append(india);
		Att_siam.append(indonesia);
		Att_siam.append(cina);
		ID_Attaccabili[siam]=Att_siam;
		//Oceania
		QVector<short> Att_australia_orientale;
		Att_australia_orientale.append(nuova_guinea);
		Att_australia_orientale.append(australia_occidentale);
		ID_Attaccabili[australia_orientale]=Att_australia_orientale;
		QVector<short> Att_australia_occidentale;
		Att_australia_occidentale.append(nuova_guinea);
		Att_australia_occidentale.append(australia_orientale);
		Att_australia_occidentale.append(indonesia);
		ID_Attaccabili[australia_occidentale]=Att_australia_occidentale;
		QVector<short> Att_nuova_guinea;
		Att_nuova_guinea.append(australia_occidentale);
		Att_nuova_guinea.append(australia_orientale);
		Att_nuova_guinea.append(indonesia);
		ID_Attaccabili[nuova_guinea]=Att_nuova_guinea;
		QVector<short> Att_indonesia;
		Att_indonesia.append(australia_occidentale);
		Att_indonesia.append(nuova_guinea);
		Att_indonesia.append(siam);
		ID_Attaccabili[indonesia]=Att_indonesia;
		//Africa
		QVector<short> Att_egitto;
		Att_egitto.append(africa_del_nord);
		Att_egitto.append(africa_orientale);
		Att_egitto.append(medio_oriente);
		Att_egitto.append(europa_meridionale);
		ID_Attaccabili[egitto]=Att_egitto;
		QVector<short> Att_africa_del_nord;
		Att_africa_del_nord.append(egitto);
		Att_africa_del_nord.append(africa_orientale);
		Att_africa_del_nord.append(europa_occidentale);
		Att_africa_del_nord.append(europa_meridionale);
		Att_africa_del_nord.append(congo);
		Att_africa_del_nord.append(brasile);
		ID_Attaccabili[africa_del_nord]=Att_africa_del_nord;
		QVector<short> Att_africa_del_sud;
		Att_africa_del_sud.append(congo);
		Att_africa_del_sud.append(africa_orientale);
		Att_africa_del_sud.append(madagascar);
		ID_Attaccabili[africa_del_sud]=Att_africa_del_sud;
		QVector<short> Att_africa_orientale;
		Att_africa_orientale.append(egitto);
		Att_africa_orientale.append(africa_del_nord);
		Att_africa_orientale.append(africa_del_sud);
		Att_africa_orientale.append(madagascar);
		Att_africa_orientale.append(congo);
		ID_Attaccabili[africa_orientale]=Att_africa_orientale;
		QVector<short> Att_congo;
		Att_congo.append(africa_orientale);
		Att_congo.append(africa_del_nord);
		Att_congo.append(africa_del_sud);
		ID_Attaccabili[congo]=Att_congo;
		QVector<short> Att_madagascar;
		Att_madagascar.append(africa_orientale);
		Att_madagascar.append(africa_del_sud);
		ID_Attaccabili[madagascar]=Att_madagascar;
		//Europa
		QVector<short> Att_europa_meridionale;
		Att_europa_meridionale.append(egitto);
		Att_europa_meridionale.append(africa_del_nord);
		Att_europa_meridionale.append(medio_oriente);
		Att_europa_meridionale.append(ucraina);
		Att_europa_meridionale.append(europa_settentrionale);
		Att_europa_meridionale.append(europa_occidentale);
		ID_Attaccabili[europa_meridionale]=Att_europa_meridionale;
		QVector<short> Att_europa_settentrionale;
		Att_europa_settentrionale.append(gran_bretagna);
		Att_europa_settentrionale.append(scandinavia);
		Att_europa_settentrionale.append(ucraina);
		Att_europa_settentrionale.append(europa_meridionale);
		Att_europa_settentrionale.append(europa_occidentale);
		ID_Attaccabili[europa_settentrionale]=Att_europa_settentrionale;
		QVector<short> Att_europa_occidentale;
		Att_europa_occidentale.append(gran_bretagna);
		Att_europa_occidentale.append(europa_settentrionale);
		Att_europa_occidentale.append(europa_meridionale);
		Att_europa_occidentale.append(africa_del_nord);
		ID_Attaccabili[europa_occidentale]=Att_europa_occidentale;
		QVector<short> Att_gran_bretagna;
		Att_gran_bretagna.append(scandinavia);
		Att_gran_bretagna.append(islanda);
		Att_gran_bretagna.append(europa_settentrionale);
		Att_gran_bretagna.append(europa_occidentale);
		ID_Attaccabili[gran_bretagna]=Att_gran_bretagna;
		QVector<short> Att_scandinavia;
		Att_scandinavia.append(gran_bretagna);
		Att_scandinavia.append(islanda);
		Att_scandinavia.append(europa_settentrionale);
		Att_scandinavia.append(ucraina);
		ID_Attaccabili[scandinavia]=Att_scandinavia;
		QVector<short> Att_islanda;
		Att_islanda.append(gran_bretagna);
		Att_islanda.append(scandinavia);
		Att_islanda.append(groenlandia);
		ID_Attaccabili[islanda]=Att_islanda;
		QVector<short> Att_ucraina;
		Att_ucraina.append(scandinavia);
		Att_ucraina.append(europa_meridionale);
		Att_ucraina.append(europa_settentrionale);
		Att_ucraina.append(medio_oriente);
		Att_ucraina.append(afganistan);
		Att_ucraina.append(urali);
		ID_Attaccabili[ucraina]=Att_ucraina;
		//Sud America
		QVector<short> Att_brasile;
		Att_brasile.append(venezuela);
		Att_brasile.append(peru);
		Att_brasile.append(argentina);
		Att_brasile.append(africa_del_nord);
		ID_Attaccabili[brasile]=Att_brasile;
		QVector<short> Att_argentina;
		Att_argentina.append(brasile);
		Att_argentina.append(peru);
		ID_Attaccabili[argentina]=Att_argentina;
		QVector<short> Att_venezuela;
		Att_venezuela.append(brasile);
		Att_venezuela.append(peru);
		Att_venezuela.append(america_centrale);
		ID_Attaccabili[venezuela]=Att_venezuela;
		QVector<short> Att_peru;
		Att_peru.append(venezuela);
		Att_peru.append(brasile);
		Att_peru.append(argentina);
		ID_Attaccabili[peru]=Att_peru;
		//Nord America
		QVector<short> Att_america_centrale;
		Att_america_centrale.append(venezuela);
		Att_america_centrale.append(stati_uniti_occidentali);
		Att_america_centrale.append(stati_uniti_orientali);
		ID_Attaccabili[america_centrale]=Att_america_centrale;
		QVector<short> Att_stati_uniti_occidentali;
		Att_stati_uniti_occidentali.append(america_centrale);
		Att_stati_uniti_occidentali.append(alberta);
		Att_stati_uniti_occidentali.append(stati_uniti_orientali);
		Att_stati_uniti_occidentali.append(ontario);
		ID_Attaccabili[stati_uniti_occidentali]=Att_stati_uniti_occidentali;
		QVector<short> Att_stati_uniti_orientali;
		Att_stati_uniti_orientali.append(america_centrale);
		Att_stati_uniti_orientali.append(quebec);
		Att_stati_uniti_orientali.append(stati_uniti_occidentali);
		Att_stati_uniti_orientali.append(ontario);
		ID_Attaccabili[stati_uniti_orientali]=Att_stati_uniti_orientali;
		QVector<short> Att_quebec;
		Att_quebec.append(stati_uniti_orientali);
		Att_quebec.append(ontario);
		Att_quebec.append(groenlandia);
		ID_Attaccabili[quebec]=Att_quebec;
		QVector<short> Att_ontario;
		Att_ontario.append(stati_uniti_orientali);
		Att_ontario.append(quebec);
		Att_ontario.append(stati_uniti_occidentali);
		Att_ontario.append(alberta);
		Att_ontario.append(groenlandia);
		Att_ontario.append(territori_del_nord_ovest);
		ID_Attaccabili[ontario]=Att_ontario;
		QVector<short> Att_alberta;
		Att_alberta.append(ontario);
		Att_alberta.append(stati_uniti_occidentali);
		Att_alberta.append(alaska);
		Att_alberta.append(territori_del_nord_ovest);
		ID_Attaccabili[alberta]=Att_alberta;
		QVector<short> Att_groenlandia;
		Att_groenlandia.append(islanda);
		Att_groenlandia.append(quebec);
		Att_groenlandia.append(ontario);
		Att_groenlandia.append(territori_del_nord_ovest);
		ID_Attaccabili[groenlandia]=Att_groenlandia;
		QVector<short> Att_alaska;
		Att_alaska.append(kamchatka);
		Att_alaska.append(alberta);
		Att_alaska.append(territori_del_nord_ovest);
		ID_Attaccabili[alaska]=Att_alaska;
		QVector<short> Att_territori_del_nord_ovest;
		Att_territori_del_nord_ovest.append(groenlandia);
		Att_territori_del_nord_ovest.append(alberta);
		Att_territori_del_nord_ovest.append(ontario);
		Att_territori_del_nord_ovest.append(alaska);
		ID_Attaccabili[territori_del_nord_ovest]=Att_territori_del_nord_ovest;
}

void QRisiko::ProssimaFase(){
	if(fase==Spostamento) fase=Not_My_Turn;
	else fase++;
	switch (fase){
		case Not_My_Turn:
			for (int i=0;i<ID_Stati::num_stati;i++){
				Stati[i]->setResponsive(false);
			}
			break;
		case Schieramento:
			Aggiunte.clear();
			for (int i=0;i<ID_Stati::num_stati;i++){
				Stati[i]->setCheckable(false);
				if(Stati[i]->GetOwner()==Player.GetColorID()){
					Stati[i]->setResponsive(true);
					Aggiunte[i]=0;
				}
				else Stati[i]->setResponsive(false);
			}
			break;
		case Attacco:
			for (int i=0;i<ID_Stati::num_stati;i++){
				if (Aggiunte.contains(i)) Stati[i]->AggiungiArmate(Aggiunte[i]);
			}
			AttackFrom_ID=-1;
			for (int i=0;i<ID_Stati::num_stati;i++){
				if(Stati[i]->GetNoArmate()<=1) Stati[i]->setResponsive(false);
				Stati[i]->setCheckable(true);
			}
			break;
		case Spostamento:
			for (int i=0;i<ID_Stati::num_stati;i++){
				Stati[i]->setCheckable(false);
				if(Stati[i]->GetOwner()==Player.GetColorID())
					Stati[i]->setResponsive(true);
				else
					Stati[i]->setResponsive(false);
			}
			break;
		default:
			return;			
	}
}