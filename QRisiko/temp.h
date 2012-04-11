#ifndef TEMP_H
#define TEMP_H
class Player{
	QString Name;
	QColor Colore;
public:
	Player(QString n,QColor c):Name(n), Colore(c) {}
	QString GetName(){return Name;}
	QColor GetColor(){return Colore;}
};
#endif