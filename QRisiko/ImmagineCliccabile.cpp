#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
#include <QSize>
#include <QResizeEvent>
ImmagineCliccabile::ImmagineCliccabile(int ID,QWidget *parent)
: QPushButton(parent),
Identita(ID),
DelayTimer(this),
Responsive(true),
No_Armate(0)
{
	immagineOriginale=NULL;
	immagineRidimensionata=NULL;
	DelayTimer.setSingleShot(true);
	DelayTimer.setInterval(50);
	connect(&DelayTimer,SIGNAL(timeout()),this,SLOT(ImpostaMaschera()));
	setImage();
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

void ImmagineCliccabile::MostraImmagine(){
	setStyleSheet(
		"ImmagineCliccabile{"
			"border-image: url("+ID_Stati::img_Stati[Identita]+");"
			"border-style: none;"
			"font: bold;"
		"}"
		"ImmagineCliccabile:hover, ImmagineCliccabile:checked{"
			"border-image: url("+ID_Stati::img_Stati_select[Identita]+");"
			"font:bold;"
		"}"
	);
}
void ImmagineCliccabile::SetOwner(const short& Ow){
	if (Ow>=0 && Ow <=6) Owner=Ow;
	else Owner=6;
}
