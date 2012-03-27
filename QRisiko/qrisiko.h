#ifndef QRISIKO_H
#define QRISIKO_H

#include <QtGui/QMainWindow>
#include "ui_qrisiko.h"

class QRisiko : public QMainWindow
{
	Q_OBJECT

public:
	QRisiko(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QRisiko();

private:
	Ui::QRisikoClass ui;
};

#endif // QRISIKO_H
