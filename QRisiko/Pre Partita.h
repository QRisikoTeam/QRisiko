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
	public:
		PrePartita(int ID, const QString& PlNam="", QWidget* parent=0);
	protected:
		void resizeEvent(QResizeEvent *event);
	signals:
		void ready(bool);
		void AllReady();
		void Annullato();
	public slots:
		void TogliColore(int ID, int ColorID);
		void AggiungiColore(int ColorID);
		void AggiuntoGiocatore(int ID, QString Nome="");
		void RimossoGiocatore(int ID);
};
#endif