#include <QtGui>
#include "ImmagineCliccabile.h"
ImmagineCliccabile::ImmagineCliccabile(QWidget *parent,int ID)
: QLabel(parent), Identita(ID)
{
	
}
void ImmagineCliccabile::mousePressEvent(QMouseEvent* event){
	QImage immagine=this->pixmap()->toImage();
	QRgb colore_pixel=immagine.pixel(event->pos());
	if (colore_pixel==QColor(0, 0, 0, 0).rgba()) return;
	emit(clicked(Identita));
}