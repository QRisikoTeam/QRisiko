#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class Animator: public QWidget{
	Q_OBJECT
	Q_PROPERTY(double Degree READ GetDegree WRITE SetDegree)
public:
	static enum AnimationType{RotateOut=0, RotateIn=1, SlideIn=2, SlideOut=3 };
	Animator(QWidget* base, QWidget* base_Parent=0, AnimationType tipo=SlideIn, QEasingCurve easCurv=QEasingCurve::Linear );
	AnimationType GetAnimationType() const {return tipoAnimazione;}
	void SetAnimationType(const AnimationType& ta) {tipoAnimazione=ta;}
	QEasingCurve GetCurvaEasing() const {return CurvaEasing;}
	void SetCurvaEasing(const QEasingCurve& qe) {CurvaEasing=qe;}
	double GetDegree() const {return Degree;}
	void SetDegree(const double& dg);
	int GetDurata() const {return Durata;}
	void SetDurata(const int& dr){Durata=dr;}
	void Anima();
private:
	QWidget* baseParent;
	int Durata;
	QPoint Posizione;
	QPropertyAnimation* anim;
	QPixmap* WidImage;
	QGraphicsView* Displayer;
	QGraphicsScene* Scena;
	QGraphicsPixmapItem* Immagine;
	double Degree;
	AnimationType tipoAnimazione;
	QEasingCurve CurvaEasing;
};