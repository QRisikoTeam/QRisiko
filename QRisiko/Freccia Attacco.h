#ifndef FRECCIAATTACCO_H
#define FRECCIAATTACCO_H
#include <QWidget>
//class QPoint;
class Freccia: public QWidget{
	Q_OBJECT
	Q_PROPERTY(QPoint from READ GetFrom WRITE SetFrom)
	Q_PROPERTY(QPoint to READ GetTo WRITE SetTo)
public:
	Freccia(QWidget* parent=0);
	void SetFrom(const QPoint& fr){from=fr; emit ShapeChanged();}
	void SetFrom(const int& frx,const int& fry){from=QPoint(frx,fry); emit ShapeChanged();}
	void SetTo(const QPoint& a){to=a;  emit ShapeChanged();}
	void SetTo(const int& ax,const int& ay){to=QPoint(ax,ay); emit ShapeChanged();}
	QPoint GetFrom() const {return from;}
	QPoint GetTo() const {return to;}
	QPoint GetShift();
	QSize GetDimensione();
private:
	QVector<QPoint> Punti;
	QVector<QPoint> PuntiShift;
	double Larghezza;
	double Angolo; //in radianti
	QPoint from;
	QPoint to;
	QSize Dimensione;
	QPoint Shift;
	double RADtoDEG(const double& rad){return 180.0*rad/3.14159;}
private slots:
	void Recalculate();
signals:
	void ShapeChanged();
protected:
	void paintEvent(QPaintEvent *event);

};
#endif