#ifndef REGOLAMENTO_H
#define REGOLAMENTO_H
#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
class Regolamento :public QWidget{
	Q_OBJECT
	public:
		Regolamento(QWidget* parent);
	private:
		QTextBrowser* Testo;
		QPushButton *backButton;
	signals:
		void Indietro();
};
#endif