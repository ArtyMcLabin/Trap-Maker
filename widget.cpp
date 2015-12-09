#include "widget.h"
#include "ui_widget.h"






Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

	setFocusPolicy(Qt::StrongFocus);
	setFocus();





	//mouse traps
	//connect(ui->pushTrapHat, &QPushButton::pressed,this,[this]{ trapSwitch(hat,1); });
	//connect(ui->pushTrapHat, &QPushButton::released,this,[this]{ trapSwitch(hat,0); });
	//connect(ui->pushTrapSnare, &QPushButton::pressed,this,[this]{ snare->trap(); });
	//connect(ui->pushTrapSnare, &QPushButton::released,this,[this]{ snare->untrap(); });






}

Widget::~Widget()
{
	delete ui;
}


void Widget::keyPressEvent(QKeyEvent *e)
{
	switch(e->key())
	{
		case Qt::Key_Space:			//# focuspolicy suck on spacebar
			kick808->playOnce();
			break;
		case Qt::Key_Alt:			//# focuspolicy suck on spacebar
			travel808->playOnce();
			break;
		case Qt::Key_Shift:
			snare->trap(); D("shift");
			break;
		case Qt::Key_Q:
			hat->loop(); D("Q");
			break;
		case Qt::Key_Right:
			hat->moveTempo(1,0);
			if(hat->b_loop){
				hat->loop(); // unloop
				hat->loop();} // reloop for reset
			break;
		case Qt::Key_Left:
			hat->moveTempo(-1,0);
			if(hat->b_loop){
				hat->loop();
				hat->loop();}
			break;
		case Qt::Key_Up:
			hat->moveTempo(1,1);
			if(hat->b_loop){
				hat->loop();
				hat->loop();}
			break;
		case Qt::Key_Down:
			hat->moveTempo(-1,1);
			if(hat->b_loop){
				hat->loop();
				hat->loop();}
			break;
		case Qt::Key_W:
			hat->trap(); D("W");
			break;

	}
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
	switch(e->key())
	{
		case Qt::Key_Shift:
			snare->untrap(); D("N/A");
			break;
		case Qt::Key_W:
			hat->untrap(); D("N/A");
			if(hat->b_loop){
				hat->loop();
				hat->loop();}

			break;
	}
}

