#ifndef IMMAGINECLICCABILE_H
#define IMMAGINECLICCABILE_H
#include <QPushButton>
#include <QTimer>
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
	QTimer DelayTimer; //Ritarda la creazione della maschera in quanto operazione complessa e lenta da ripetere ad ogni resize
	QPixmap* immagineOriginale;
	QPixmap immagineRidimensionata;
	short Owner;
	short No_Armate;
signals:
	void Cliccato(bool,int);
protected:
	void resizeEvent (QResizeEvent * event);
private slots:
	void ImpostaMaschera();
	void clickID(bool che){emit Cliccato(che,Identita);}
};
#endif
