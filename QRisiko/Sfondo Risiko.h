#include <QWidget>
class SfondoRisiko: public QWidget{
	Q_OBJECT
public:
	SfondoRisiko(QWidget* parent=0);
	void setStyleSheet(const QString& stsh);
protected:
//	void paintEvent(QPaintEvent *pnt);
};