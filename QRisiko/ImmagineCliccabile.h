#ifndef IMMAGINECLICCABILE_H
#define IMMAGINECLICCABILE_H
#include <QPushButton>
#include <QTimer>
#include <QBitmap>
#include <QStyle>
#include "Costanti Nazioni.h"
class ImmagineCliccabile: public QPushButton
{
	Q_OBJECT
	Q_PROPERTY(bool Responsive READ IsResponsive)
	Q_PROPERTY(short No_Armate READ GetNoArmate WRITE SetNoArmate NOTIFY NoArmateChanged)
public:
	enum{Normale=0, Proprietari=1, IntensitaArmate=2, Minacce=3, Carte=4};
	ImmagineCliccabile(int ID=-1,QWidget *parent=0);
	void setImage();
	void setResponsive(const bool& rsp){Responsive=rsp; emit ResponsiveChanged();}
	bool IsResponsive() const {return Responsive;}
	short GetOwner() const {return Owner;}
	void SetOwner(const short& Ow);
	short GetNoArmate() const {return No_Armate;}
	void SetNoArmate(const short& no){No_Armate=no; emit ArmateChanged(Identita); setText(ID_Stati::Nomi_Stati[Identita]+QString("\nArmate: %1").arg(No_Armate));}
	void AggiungiArmate(const short& no){No_Armate+=no; emit ArmateChanged(Identita); setText(ID_Stati::Nomi_Stati[Identita]+QString("\nArmate: %1").arg(No_Armate));}
	void RimuoviArmate(const short& no){No_Armate-=no; emit ArmateChanged(Identita); setText(ID_Stati::Nomi_Stati[Identita]+QString("\nArmate: %1").arg(No_Armate));}
	short GetCurrVisual() const {return CurrVisual;}
	void SetAbsoluteMaxArmy(const short& no){AbsoluteMaxArmy=no;}
	void SetMenace(const short& no){Menace=no;}
	void SetMaxMenace(const short& no){Max_Menace=no;}
	short GetMenace() const {return Menace;}
public slots:
	void NextVisual();
	void UpdateVisual();
	void SimulaClick();
private:
	void ImpostaMask();
	int Identita;
	QTimer DelayTimer; //Ritarda la creazione della maschera in quanto operazione complessa e lenta da ripetere ad ogni resize
	QPixmap* immagineOriginale;
	QPixmap immagineRidimensionata;
	short Owner;
	short No_Armate;
	bool Responsive;
	short CurrVisual;
	short AbsoluteMaxArmy;
	short Menace;
	short Max_Menace;
signals:
	void Cliccato(bool,int);
	void NoArmateChanged();
	void ResponsiveChanged();
	void ArmateChanged(int iden);
protected:
	void resizeEvent (QResizeEvent * event);
private slots:
	void ImpostaMaschera();
	void clickID(bool che){if(Responsive) emit Cliccato(che,Identita);}
	void ResettaStile(){style()->unpolish(this); style()->polish(this);}
};
#endif
