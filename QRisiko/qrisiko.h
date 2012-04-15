#ifndef QRISIKO_H
#define QRISIKO_H

#include <QWidget>
#include <QFrame>
#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
#include "Gestore Servers.h"

class QRisiko : public QWidget
{
	Q_OBJECT
	private:
		ImmagineCliccabile *Stati[ID_Stati::num_stati];
		QFrame* Sfondo;
		GestoreServers* gestoreServer;
	protected:
		void mousePressEvent(QMouseEvent *event);
		void resizeEvent (QResizeEvent * event);
	signals:
		void cliccato(int identita);
		void resized(QSize new_size);
	public:
		QRisiko(QWidget *parent = 0);
		void setStyleSheet(const QString& stsh);
	private slots:
		void funziona(int identita);

};

#endif
