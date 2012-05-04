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
class PrePartita: public QWidget{
	Q_OBJECT
	private:
		QFrame* Sfondo;
		QFrame* Interno;
		QPushButton* Pronto;
		QPushButton* Annulla;
		QLabel* ImpostazioniLabel;
		int ContGiocatori;
		QLineEdit* NomiGiocatori[Giocatori::Max_Giocatori];
		QComboBox* ColoriGiocatori[Giocatori::Max_Giocatori];
		QList<int> IDList;
	public:
		PrePartita(QWidget* parent=0);
	protected:
		void resizeEvent(QResizeEvent *event);
	signals:
		void ready(bool);
		void AllReady();
		void Annullato();
	public slots:
		void AggiuntoGiocatore(int ID, QString Nome="");
		void RimossoGiocatore(int ID);
};
#endif