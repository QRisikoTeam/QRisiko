#ifndef IMMAGINECLICCABILE_H
#define IMMAGINECLICCABILE_H
#include <QLabel>
class ImmagineCliccabile: public QLabel
{
	Q_OBJECT
public:
	ImmagineCliccabile(QWidget *parent, int ID);
protected:
	void mousePressEvent(QMouseEvent* event);
private:
	int Identita;
signals:
	void clicked(const int& ID);

};
#endif