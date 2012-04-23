#ifndef MAINMENUN_H
#define MAINMENUN_H
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QResizeEvent>

class MenuPrincipale: public QWidget
{
	Q_OBJECT
	private:
		QGridLayout *gridLayout;
		QLabel *Simbolo;
		QPushButton *HostLoadButton;
		QPushButton *JoinButton;
		QPushButton *HostNewButton;
		QPushButton *OptionButton;
		QPushButton *AboutButton;
		QPushButton *RulesButton;
		QPushButton *ExitButton;
		QFrame* Sfondo;
	public:
		MenuPrincipale(QWidget *parent=0);
	signals:
		void HostLoad();
		void Join();
		void HostNew();
		void Option();
		void About();
		void Rules();
		void Exit();
	protected:
		void resizeEvent(QResizeEvent *event);
};

#endif 
