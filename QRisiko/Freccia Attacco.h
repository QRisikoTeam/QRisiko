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
	void SetFrom(const QPoint& fr){from=fr;}
	void SetTo(const QPoint& a){to=a;}
	QPoint GetFrom() const {return from;}
	QPoint GetTo() const {return to;}
	QSize Dimensione() const;
private:
	QPoint from;
	QPoint to;
	double RADtoDEG(const double& rad){return 180.0*rad/3.14159;}
protected:
	void paintEvent(QPaintEvent *event);

};
#endif