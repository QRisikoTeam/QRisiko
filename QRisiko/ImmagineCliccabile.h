#ifndef IMMAGINECLICCABILE_H
#define IMMAGINECLICCABILE_H
#include <QLabel>
class ImmagineCliccabile: public QLabel
{
	Q_OBJECT
public:
	ImmagineCliccabile(QWidget *parent, int ID);
	bool IsTransparent(const QPoint& pnt) const;
public slots:
	void Redimensiona(QSize nuova_dimensione);
private:
	int Identita;

};
#endif
