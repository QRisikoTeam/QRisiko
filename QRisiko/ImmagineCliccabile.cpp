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
	setText(ID_Stati::Nomi_Stati[Identita]+QString("\nArmate: %1").arg(No_Armate));
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
	switch (CurrVisual){
		case Normale:
			setStyleSheet(
				"ImmagineCliccabile{"
					"border-image: url("+ID_Stati::img_Stati_bordo[Identita]+");"
					"background-color: "+ID_Stati::Colori_Nazioni[Identita].name()+";"
					"border-style: none;"
					"font: bold;"
				"}"
					"ImmagineCliccabile:hover, ImmagineCliccabile:checked{"
					"border-image: url("+ID_Stati::img_Stati_select[Identita]+");"
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
				"ImmagineCliccabile:hover, ImmagineCliccabile:checked{"
					"background-color: "+Giocatori::ColoriSelected[Owner].name()+";"
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
				"ImmagineCliccabile:hover, ImmagineCliccabile:checked{"
					"background-color: "+QString("rgba(%1,%2,%3,%4)")
						.arg(Giocatori::ColoriSelected[Owner].red())
						.arg(Giocatori::ColoriSelected[Owner].green())
						.arg(Giocatori::ColoriSelected[Owner].blue())
						.arg(100+((155*No_Armate)/AbsoluteMaxArmy))+";"
				"}"
			);
			break;
		default:
			return;
	}
}

void ImmagineCliccabile::UpdateVisual(){
	switch (CurrVisual){
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
				"ImmagineCliccabile:hover, ImmagineCliccabile:checked{"
				"background-color: "+QString("rgba(%1,%2,%3,%4)")
				.arg(Giocatori::ColoriSelected[Owner].red())
				.arg(Giocatori::ColoriSelected[Owner].green())
				.arg(Giocatori::ColoriSelected[Owner].blue())
				.arg(100+((155*No_Armate)/AbsoluteMaxArmy))+";"
				"}"
			);
			break;
		default: return;
	}
}