#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
#include <QSize>
#include <QResizeEvent>
ImmagineCliccabile::ImmagineCliccabile(int ID,QWidget *parent)
: QPushButton(parent),
Identita(ID),
DelayTimer(this),
Responsive(true),
No_Armate(0),
CurrVisual(Carte)
{
	immagineOriginale=NULL;
	immagineRidimensionata=NULL;
	DelayTimer.setSingleShot(true);
	DelayTimer.setInterval(50);
	connect(&DelayTimer,SIGNAL(timeout()),this,SLOT(ImpostaMaschera()));
	setImage();
	NextVisual();
	connect(this,SIGNAL(clicked(bool)),this,SLOT(clickID(bool)));
	connect(this,SIGNAL(ResponsiveChanged()),this,SLOT(ResettaStile()));
	setText(ID_Stati::Nomi_Stati[Identita]+QString("\nArmate: %1").arg(No_Armate));
}
void ImmagineCliccabile::SimulaClick(){
	if(Responsive){
		if(isCheckable()){
			setChecked(!isChecked());
			emit Cliccato(isChecked(),Identita);
		}
		else emit Cliccato(false,Identita);
	}
}
void ImmagineCliccabile::setImage(){
	if (immagineOriginale)
		delete immagineOriginale;
	if(Identita<0 || Identita>=ID_Stati::num_stati) immagineOriginale=NULL;
	else{
		immagineOriginale=new QPixmap(ID_Stati::img_Stati[Identita]);
		setMask(immagineOriginale->mask());
	}
}

void ImmagineCliccabile::ImpostaMaschera(){
	setMask(immagineRidimensionata.mask());
}

void ImmagineCliccabile::resizeEvent (QResizeEvent * event){
	if(immagineOriginale){
		immagineRidimensionata=immagineOriginale->scaled(event->size(),Qt::IgnoreAspectRatio);
		DelayTimer.start();
	}
}


void ImmagineCliccabile::SetOwner(const short& Ow){
	if (Ow>=0 && Ow <=6) Owner=Ow;
	else Owner=6;
}
void ImmagineCliccabile::NextVisual(){
	if(CurrVisual>=Carte) CurrVisual=Normale;
	else CurrVisual++;
	UpdateVisual();
}

void ImmagineCliccabile::UpdateVisual(){
	setStyleSheet("");
	QColor RossoVerde, RossoVerdeSelected;
	int IntensitaMinaccia;
	switch (CurrVisual){
		case Normale:
			setStyleSheet(
				"ImmagineCliccabile{"
					"border-image: url("+ID_Stati::img_Stati_bordo[Identita]+");"
					"background-color: "+ID_Stati::Colori_Nazioni[Identita].name()+";"
					"border-style: none;"
					"font: bold;"
				"}"
				"ImmagineCliccabile[Responsive=\"true\"]:hover, ImmagineCliccabile[Responsive=\"true\"]:checked{"
					"background-color: "+ID_Stati::Colori_Nazioni_Select[Identita].name()+";"
				"}"
				"ImmagineCliccabile:disabled{"
					"background-color:#777;"
				"}"
				);
			break;
		case Proprietari:
			setStyleSheet(
				"ImmagineCliccabile{"
					"border-image: url("+ID_Stati::img_Stati_bordo[Identita]+");"
					"background-color: "+Giocatori::Colori[Owner].name()+";"
					"border-style: none;"
					"font: bold;"
				"}"
					"ImmagineCliccabile[Responsive=\"true\"]:hover, ImmagineCliccabile[Responsive=\"true\"]:checked{"
					"background-color: "+Giocatori::ColoriSelected[Owner].name()+";"
				"}"
					"ImmagineCliccabile:disabled{"
					"background-color:#777;"
				"}"
				);
			break;
		case IntensitaArmate:
			setStyleSheet(
				"ImmagineCliccabile{"
				"border-image: url("+ID_Stati::img_Stati_bordo[Identita]+");"
				"background-color: "+QString("rgba(%1,%2,%3,%4)")
				.arg(Giocatori::Colori[Owner].red())
				.arg(Giocatori::Colori[Owner].green())
				.arg(Giocatori::Colori[Owner].blue())
				.arg(100+((155*No_Armate)/AbsoluteMaxArmy))
				+";"
				"border-style: none;"
				"font: bold;"
				"}"
				"ImmagineCliccabile[Responsive=\"true\"]:hover, ImmagineCliccabile[Responsive=\"true\"]:checked{"
				"background-color: "+QString("rgba(%1,%2,%3,255)")
				.arg(Giocatori::ColoriSelected[Owner].red())
				.arg(Giocatori::ColoriSelected[Owner].green())
				.arg(Giocatori::ColoriSelected[Owner].blue())+";"
				"}"
				"ImmagineCliccabile:disabled{"
				"background-color:#777;"
				"}"
			);
		break;
		case Minacce:
			if (Menace<100) {
				RossoVerde=Giocatori::Colori[Giocatori::Verde];
				RossoVerdeSelected=Giocatori::ColoriSelected[Giocatori::Verde];
				IntensitaMinaccia=Menace;
			}
			else if(Menace==100) {
				RossoVerde=Giocatori::Colori[Giocatori::Giallo];
				RossoVerdeSelected=Giocatori::ColoriSelected[Giocatori::Giallo];
				IntensitaMinaccia=100;
			}
			else {
				RossoVerde=Giocatori::Colori[Giocatori::Rosso];
				RossoVerdeSelected=Giocatori::ColoriSelected[Giocatori::Rosso];
				IntensitaMinaccia=(Menace*100)/Max_Menace;
			}
			setStyleSheet(
				"ImmagineCliccabile{"
				"border-image: url("+ID_Stati::img_Stati_bordo[Identita]+");"
				"background-color: "+QString("rgba(%1,%2,%3,%4)")
				.arg(RossoVerde.red())
				.arg(RossoVerde.green())
				.arg(RossoVerde.blue())
				.arg(100+((155*IntensitaMinaccia)/100))
				+";"
				"border-style: none;"
				"font: bold;"
				"}"
				"ImmagineCliccabile[Responsive=\"true\"]:hover, ImmagineCliccabile[Responsive=\"true\"]:checked{"
				"background-color: "+QString("rgba(%1,%2,%3,255)")
				.arg(RossoVerdeSelected.red())
				.arg(RossoVerdeSelected.green())
				.arg(RossoVerdeSelected.blue())+";"
				"}"
				"ImmagineCliccabile:disabled{"
				"background-color:#777;"
				"}"
				);
		break;
		default: return;
	}
}