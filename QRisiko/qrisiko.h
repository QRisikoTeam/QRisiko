#ifndef QRISIKO_H
#define QRISIKO_H
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
#include "Gestore Servers.h"
#include "Sfondo Risiko.h"

class QRisiko : public QWidget
{
	Q_OBJECT
	private:
		ImmagineCliccabile *Stati[ID_Stati::num_stati];
		QLabel* Sfondo;
		GestoreServers* gestoreServer;
		QVector<short> ID_Attaccabili[ID_Stati::num_stati];
		void Popola_ID_Attaccabili();
		short fase;
	protected:
		void resizeEvent (QResizeEvent * event);
	signals:
		void resized(QSize new_size);
		void FaseCambiata(short);
	public:
		QRisiko(QWidget *parent = 0);
		enum{Not_My_Turn=0, Schieramento=1, Attacco=2, Spostamento=3};
	private slots:
		void funziona(bool che, int identita);
	public slots:
		void ProssimaFase();

};

#endif
