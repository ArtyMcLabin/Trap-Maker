#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QKeyEvent>

#include "looped.h"
#include "personal_macros.h"

namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();


		Looped *hat       = new Looped(this,"hat.wav");
		Looped *snare     = new Looped(this,"snare.wav");
		Looped *kick808   = new Looped(this,"808.wav",75);
		Looped *travel808 = new Looped(this,"808c.wav");
		Looped *hey       = new Looped(this,"hey.wav");
		Looped *cymbal    = new Looped(this,"cymbal.wav");
		Looped *clap      = new Looped(this,"clap.wav");


private:
	Ui::Widget *ui;

protected:
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
};

#endif // WIDGET_H
