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
	protected:
		void resizeEvent (QResizeEvent * event);
	signals:
		void resized(QSize new_size);
	public:
		QRisiko(QWidget *parent = 0);
	private slots:
		void funziona(int identita);

};

#endif
