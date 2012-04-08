#ifndef QRISIKO_H
#define QRISIKO_H

#include <QtGui/QMainWindow>
#include "ui_qrisiko.h"
#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"

class QRisiko : public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT
	private:
		ImmagineCliccabile *Stati[ID_Stati::num_stati];
	public:
		QRisiko(QWidget *parent = 0);
	private slots:
		void funziona(int identita);

};

#endif // QRISIKO_H
