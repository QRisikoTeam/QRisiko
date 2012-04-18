#ifndef IMMAGINECLICCABILE_H
#define IMMAGINECLICCABILE_H
#include <QPushButton>
#include <QBitmap>
class ImmagineCliccabile: public QPushButton
{
	Q_OBJECT
public:
	ImmagineCliccabile(int ID=-1,QWidget *parent=0);
	void setImage();
	void MostraImmagine();
private:
	void ImpostaMask();
	int Identita;
	QPixmap* immagineOriginale;
	QPixmap* immagineRidimensionata;
signals:
	void Cliccato(int);
protected:
	void resizeEvent (QResizeEvent * event);
private slots:
	void clickID(){emit Cliccato(Identita);}
};
#endif
