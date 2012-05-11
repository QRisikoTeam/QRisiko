#include "Freccia Attacco.h"
#include <cmath>
#include <QPainter>
Freccia::Freccia(QWidget* parent)
:QWidget(parent)
,from(QPoint(0,0))
,to(QPoint(0,0))
{
	Recalculate();
}
void Freccia::paintEvent(QPaintEvent *event){
	QPainter disegno(this);
	disegno.setRenderHint(QPainter::Antialiasing,true);
	disegno.setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::FlatCap));
	disegno.setBrush(QBrush(Qt::red,Qt::SolidPattern));
	disegno.drawPolygon(QPolygon(PuntiShift));
}
QSize Freccia::Dimensione(){
	Recalculate();
	return QSize(Larghezza,Larghezza);
	//return QSize(MaxX-MinX,MaxY-MinY);
}

QPoint Freccia::GetShift(){
	Recalculate();
	return Shift;
}

void Freccia::Recalculate(){
	double Modulo;
	double Fase;
	Larghezza= std::sqrt(((static_cast<double>(to.x()-from.x())*static_cast<double>(to.x()-from.x()))+(static_cast<double>(to.y()-from.y())*static_cast<double>(to.y()-from.y()))));
	Angolo= (to.x()==from.x() ? 0.0:
		std::atan(static_cast<double>(to.y()-from.y())/static_cast<double>(to.x()-from.x()))
	);
	Punti.clear();
	if (Larghezza>0.0){
		Punti.append(QPoint(5.0*std::sin(Angolo),5.0*std::cos(Angolo)));

		Modulo=std::sqrt((0.7*Larghezza*0.7*Larghezza)+(5.0*5.0));
		Fase=std::atan(5.0/(0.7*Larghezza));
		Punti.append(QPoint(Modulo*std::cos(Angolo-Fase),Modulo*std::sin(Angolo-Fase)));
		
		Punti.append(QPoint(0.7*Larghezza*std::cos(Angolo),0.7*Larghezza*std::sin(Angolo)));

		Modulo=std::sqrt((Larghezza*Larghezza)+(15.0*15.0));
		Fase=std::atan(15.0/Larghezza);
		Punti.append(QPoint(Modulo*std::cos(Angolo-Fase),Modulo*std::sin(Angolo-Fase)));
		
		Modulo=std::sqrt((0.7*Larghezza*0.7*Larghezza)+(30.0*30.0));
		Fase=std::atan(30.0/(0.7*Larghezza));
		Punti.append(QPoint(Modulo*std::cos(Angolo-Fase),Modulo*std::sin(Angolo-Fase)));

		Modulo=std::sqrt((0.7*Larghezza*0.7*Larghezza)+(25.0*25.0));
		Fase=std::atan(25.0/(0.7*Larghezza));
		Punti.append(QPoint(Modulo*std::cos(Angolo-Fase),Modulo*std::sin(Angolo-Fase)));

		Punti.append(QPoint(25.0*std::sin(Angolo),25.0*std::cos(Angolo)));

		MaxY=Punti.begin()->y();
		MinY=Punti.begin()->y();
		MaxX=Punti.begin()->x();
		MinX=Punti.begin()->x();
		for(QVector<QPoint>::iterator i=Punti.begin()+1;i<Punti.end();i++){
			if(i->y()>MaxY) MaxY=i->y();
			if(i->y()<MinY) MinY=i->y();
			if(i->x()>MaxX) MaxX=i->x();
			if(i->x()<MinX) MinX=i->x();
		}
		Shift=QPoint(MinX,MinY);
		PuntiShift.clear();
		for(QVector<QPoint>::iterator i=Punti.begin();i<Punti.end();i++){
			PuntiShift.append(*i-Shift);
		}
	}
	update();
}