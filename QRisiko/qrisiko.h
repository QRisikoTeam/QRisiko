#ifndef QRISIKO_H
#define QRISIKO_H

#include <QtGui/QMainWindow>
#include "ui_qrisiko.h"
#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"

class QRisiko : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
private:
	ImmagineCliccabile *Stati[ID_Stati::num_stati];
protected:
	void mousePressEvent(QMouseEvent *event);
	void resizeEvent (QResizeEvent * event);
signals:
	void cliccato(int identita);
	void resized(QSize new_size);
public:
	QRisiko(QWidget *parent = 0);
private slots:
	void funziona(int identita);

};

#endif // QRISIKO_H
