#include "Freccia Attacco.h"
#include <cmath>
#include <QPainter>
Freccia::Freccia(QWidget* parent)
:QWidget(parent)
,from(QPoint(0,0))
,to(QPoint(0,0))
{

}
void Freccia::paintEvent(QPaintEvent *event){
	QVector<QPoint> PuntiFreccia;
	QPainter disegno(this);
	disegno.setRenderHint(QPainter::Antialiasing,true);
	disegno.setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::FlatCap));
	disegno.setBrush(QBrush(Qt::red,Qt::SolidPattern));
	/*QMatrix trasformazione;
	trasformazione.rotate(RADtoDEG(std::arctan(to.y()-from.y(),to.x()-from.x())));
	disegno.setMatrix(trasformazione);*/
	PuntiFreccia.append(QPoint(0,5));
	PuntiFreccia.append(QPoint(0.7*std::sqrt(static_cast<double>(((to.x()-from.x())*(to.x()-from.x()))+((to.y()-from.y())*(to.y()-from.y())))),5));

	PuntiFreccia.append(QPoint(0.7*std::sqrt(static_cast<double>(((to.x()-from.x())*(to.x()-from.x()))+((to.y()-from.y())*(to.y()-from.y())))),25));
	PuntiFreccia.append(QPoint(0,25));
	disegno.drawPolygon(QPolygon())
}
QSize Freccia::Dimensione() const{
	return QSize(std::sqrt(static_cast<double>(((to.x()-from.x())*(to.x()-from.x()))+((to.y()-from.y())*(to.y()-from.y())))),20);
}