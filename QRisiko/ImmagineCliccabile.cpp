#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
#include <QSize>
#include <QResizeEvent>
ImmagineCliccabile::ImmagineCliccabile(int ID,QWidget *parent)
: QPushButton(parent), Identita(ID)
{
	immagineOriginale=NULL;
	immagineRidimensionata=NULL;
	setImage();
	connect(this,SIGNAL(clicked()),this,SLOT(clickID()));
}

void ImmagineCliccabile::setImage(){
	if (immagineOriginale)
		delete immagineOriginale;
	if(Identita<0) immagineOriginale=NULL;
	else{
		immagineOriginale=new QPixmap(ID_Stati::img_Stati[Identita]);
		setMask(immagineOriginale->mask());
	}
}

void ImmagineCliccabile::resizeEvent (QResizeEvent * event){
	if(immagineOriginale){
		if(immagineRidimensionata)
			delete immagineRidimensionata;
		immagineRidimensionata=new QPixmap(immagineOriginale->scaled(event->size(),Qt::IgnoreAspectRatio));
		setMask(immagineRidimensionata->mask());
	}
}

void ImmagineCliccabile::MostraImmagine(){
	setStyleSheet(
		"ImmagineCliccabile{border-image: url("+ID_Stati::img_Stati[Identita]+");"
		"border-style: none;}"
		"ImmagineCliccabile:hover {"
		"border-image: url("+ID_Stati::img_Stati_select[Identita]+");"
		"}"
	);
}
