#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui/QMainWindow>
#include "qrisiko.h"
#include "Chat Widget.h"
#include "MainMenu.h"
#include "ServerSelector.h"

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QWidget* parent=0);
	private:
		MenuPrincipale* MainMenu;
		ServerSelector* SelettoreServer;
		QRisiko* mappa;
		ChatWidget* chat;
		QTextEdit* Log;
		QFrame* BottomFrame;
		QFrame* TopFrame;
		QWidget* CurrWidget;
		QWidget* PrevWidget;
		QLabel* BottomFrameCover;
		int DurataAnimazioniMenu;
		void riposiziona();
	private slots:
		void MostraMappa();
		void NascondiPrev(){
			PrevWidget->hide();
		}
		void MostraSelettoreServer();
		void MostraMainMenu();
	protected:
		void closeEvent(QCloseEvent *event);
		void resizeEvent(QResizeEvent *event);
};

#endif