#include <QtGui>
#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
ImmagineCliccabile::ImmagineCliccabile(QWidget *parent,int ID)
: QLabel(parent), Identita(ID)
{
	
}


bool ImmagineCliccabile::IsTransparent(const QPoint& pnt) const{
	QImage immagine=QPixmap::grabWidget((QWidget *)this).toImage();
	if (!immagine.valid(pnt)) return true;
	QRgb colore_pixel=immagine.pixel(pnt);
	return !(colore_pixel==ID_Stati::Colori_Nazioni[Identita].rgba());
}

void ImmagineCliccabile::Redimensiona(QSize nuova_dimensione){
	int wid=int(
		double(nuova_dimensione.width())
		*
		double(ID_Stati::PosData_Stati[Identita].dimensione().width())
		/
		double(ID_Stati::sp_mappa.dimensione().width()));
	int hei=int(
		double(nuova_dimensione.height())
		*
		double(ID_Stati::PosData_Stati[Identita].dimensione().height())
		/
		double(ID_Stati::sp_mappa.dimensione().height()));
	int x=int(
		double(nuova_dimensione.width())
		*
		double(ID_Stati::PosData_Stati[Identita].posizione().x())
		/
		double(ID_Stati::sp_mappa.dimensione().width()));
	int y=int(
		double(nuova_dimensione.height())
		*
		double(ID_Stati::PosData_Stati[Identita].posizione().y())
		/
		double(ID_Stati::sp_mappa.dimensione().height()));
	resize(wid,hei);
	move(x,y);
}
