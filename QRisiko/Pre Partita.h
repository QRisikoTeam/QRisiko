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
	public:
		enum {ServerID=-1};
		PrePartita(int ID,const QString& PlNam="",QWidget* parent=0);
	protected:
		void resizeEvent(QResizeEvent *event);
	signals:
		void ready(bool);
		void AllReady();
		void Annullato();
		void ColoreScelto(int ID, int ColorID);
		void PartitaPiena();
	public slots:
		void ColoreSelezionato(int ID, int ColorID);
		void TogliColore(int ID, int ColorID);
		void AggiungiColore(int ColorID);
		void AggiuntoGiocatore(int ID, QString Nome="");
		void RimossoGiocatore(int ID);
		void SetMyID(const int& a){MyID=a;}
		void SetPlayerName(const QString& a){PlayerName=a;}
	private slots:
		void disabilitaPronto(bool pront);
		void NomeCambiato(const QString& nuovo);
};
#endif