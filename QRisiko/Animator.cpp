#include "Animator.h"
#include <QHBoxLayout>
#include <QApplication>
#include <QDesktopWidget>

Animator::Animator(QWidget* base, QWidget* base_Parent,AnimationType tipo/* =AnimationType::SlideOut */, QEasingCurve easCurv/* =QEasingCurve::Linear */ )
:QWidget(base_Parent),
baseParent(base_Parent),
tipoAnimazione(tipo),
CurvaEasing(easCurv),
Posizione(base->pos()),
Durata(1000)
{
	setMinimumSize(QSize(0,0));
	WidImage=new QPixmap(QPixmap::grabWidget(base));
	setGeometry(QRect(base->pos(),base->size()));
	
	anim=NULL;

	Displayer=new QGraphicsView(this);
	Displayer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	Displayer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	Displayer->setMinimumSize(QSize(0,0));
	Displayer->setStyleSheet("border-style: none; background-color: rgba(0,0,0,0);");
	Scena=new QGraphicsScene(QRect(QPoint(0,0),WidImage->size()),Displayer);
	Scena->setBackgroundBrush(Qt::transparent);
	Displayer->setScene(Scena);
	Immagine=new QGraphicsPixmapItem(*WidImage,0,Scena);
	

	QHBoxLayout* Laiout=new QHBoxLayout(this);
	Laiout->setMargin(0);
	Laiout->setSpacing(0);
	Laiout->addWidget(Displayer);
}
void Animator::SetDegree(const double& dg){
	Degree=dg;
	double ScaleGrade;
	while(Degree>360.0) Degree-=360.0;
	while(Degree<0) Degree+=360.0;
	if(tipoAnimazione==RotateIn){
		QTransform transform;
		ScaleGrade=-((Degree/360.0)-1.0);
		transform.scale(ScaleGrade,ScaleGrade);
		transform.shear(0, (Degree/180.0)*((double)WidImage->height())/((double)WidImage->width()));
		Immagine->setTransform(transform);

		if(baseParent==0)
			setGeometry(Posizione.x()+(QApplication::desktop()->width()*(1-ScaleGrade)),Posizione.y(),WidImage->width()*ScaleGrade,WidImage->height());
		else
			setGeometry(Posizione.x()+(baseParent->width()*(1-ScaleGrade)),Posizione.y(),WidImage->width()*ScaleGrade,WidImage->height());
	}
	if(tipoAnimazione==RotateOut){
		QTransform transform;
		ScaleGrade=Degree/360.0;
		transform.scale(ScaleGrade,ScaleGrade);
		transform.shear(0, ((Degree/180.0)-2.0)*((double)WidImage->height())/((double)WidImage->width()));
		Immagine->setTransform(transform);

		setGeometry(
			Posizione.x()*ScaleGrade,
			Posizione.y()-(WidImage->height())*(ScaleGrade-1.0),
			WidImage->width()*ScaleGrade,
			WidImage->height()+(WidImage->height())*(ScaleGrade-1.0));		
	}
}
void Animator::Anima(){
	if(tipoAnimazione==RotateOut || tipoAnimazione==RotateIn){
		anim=new QPropertyAnimation(this,"Degree",this);
		anim->setDuration(Durata);
		anim->setEasingCurve(CurvaEasing);
		anim->setKeyValueAt(0.0,360.0);
		anim->setKeyValueAt(1.0,0.0);
		anim->start(QAbstractAnimation::DeleteWhenStopped);
	}
	else if(tipoAnimazione==SlideIn || tipoAnimazione==SlideOut){
		anim=new QPropertyAnimation(this,"pos",this);
		anim->setDuration(Durata);
		anim->setEasingCurve(CurvaEasing);
		if (tipoAnimazione==SlideIn){
			anim->setKeyValueAt(0.0,QPoint(0,Posizione.y()));
			anim->setKeyValueAt(1.0,Posizione);
		}
		if (tipoAnimazione==SlideOut){
			anim->setKeyValueAt(0.0,Posizione);
			if(baseParent==0)
				anim->setKeyValueAt(1.0,QPoint(QApplication::desktop()->width(),Posizione.y()));
			else
				anim->setKeyValueAt(1.0,QPoint(baseParent->width(),Posizione.y()));
		}
		anim->start(QAbstractAnimation::DeleteWhenStopped);
	}
}
