#ifndef IMMAGINECLICCABILE_H
#define IMMAGINECLICCABILE_H
class QLabel;
class ImmagineCliccabile: QLabel
{
	ImmagineCliccabile(QWidget *parent);
	void mousePressEvent(QMouseEvent* event);
};
#endif