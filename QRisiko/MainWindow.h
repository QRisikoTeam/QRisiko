#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui/QMainWindow>
#include "qrisiko.h"
#include "Chat Widget.h"

class MainWindow : public QMainWindow{
	public:
		MainWindow(QWidget* parent=0);
	private:
		QRisiko* mappa;
		ChatWidget* chat;
};

#endif