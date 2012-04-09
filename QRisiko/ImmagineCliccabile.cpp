#include <QtGui>
#include "ImmagineCliccabile.h"
ImmagineCliccabile::ImmagineCliccabile(QWidget *parent,int ID)
: QLabel(parent), Identita(ID)
{

}


bool ImmagineCliccabile::IsTransparent(const QPoint& pnt) const{
	QImage immagine=this->pixmap()->toImage();
	if (!immagine.valid(pnt)) return false;
	QRgb colore_pixel=immagine.pixel(pnt);

	return(colore_pixel==QColor(0, 0, 0, 0).rgba());
}