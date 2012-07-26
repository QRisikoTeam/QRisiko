#ifndef PREPARTITA_H
#define PREPARTITA_H
#include <QWidget>
#include <QResizeEvent>
#include <QList>
#include "Costanti Nazioni.h"
class QFrame;
class QPushButton;
class QLabel;
class QLineEdit;
class QComboBox;
class QScrollArea;
class QGridLayout;
class QSpacerItem;
class PrePartita: public QWidget{
	Q_OBJECT
	private:
		QFrame* Sfondo;
		QScrollArea* Interno;
		QPushButton* Pronto;
		QPushButton* Annulla;
		QLabel* ImpostazioniLabel;
		int ContGiocatori;
		QList<QLineEdit*> NomiGiocatori;
		QList<QComboBox*> ColoriGiocatori;
		QList<int> IDList;
		int MyID;
		QGridLayout* ItemsLayout;
		QString PlayerName;
		QSpacerItem* separatore;
		int rowNumber;
		bool IsServer;
		void TogliColore(int ID, int ColorID);
		void AggiungiColore(int ColorID);
	public:
		PrePartita(int ID,const QString& PlNam="",QWidget* parent=0);
		QString GetPlayerName() const {return PlayerName;}
	protected:
		void resizeEvent(QResizeEvent *event);
	signals:
		void Annullato();
		void ColoreScelto(int ID, int ColorID);
		void PartitaPiena();
		void SonoPronto();
		void NonSonoPronto();
		void InfoCambiate(const QString& Nome, int ColorID);
	public slots:
		void AggiuntoGiocatore(int ID, QString Nome="");
		void RimossoGiocatore(int ID);
		void SetMyID(const int& a){MyID=a;}
		void SetPlayerName(const QString& a){PlayerName=a;}
		void AggiornaInformazioni(int ident, const QString& NuovoNome, int NuovoColore);
	private slots:
		void ready(bool pront);
		void disabilitaPronto(bool pront);
		void CreaInformazioni();
};
#endif