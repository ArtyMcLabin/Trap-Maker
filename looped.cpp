#include "looped.h"

Looped::Looped(QObject *parent, QString sample, int volume) : QObject(parent)
{
	player0->setMedia(QUrl("qrc:/samples/"+sample));
	player0->setVolume(volume);

	player1->setMedia(QUrl("qrc:/samples/"+sample));
	player1->setVolume(volume);

	connect(timer,&QTimer::timeout,this,&playOnce);
}

void Looped::playOnce()
{
	qDebug() << this; //-

	if(splitter==0){
		player0->stop();
		player0->play();
		splitter++;
	}else if(splitter==1){
		player1->stop();
		player1->play();
		splitter--;
	}
}

void Looped::trap()
{
	playOnce();
	timer->start(60000/bpm/16); // second / base bpm / fast fragment
}

void Looped::untrap()
{
	timer->stop();
}

void Looped::loop()
{
	b_loop = !b_loop;
	if(b_loop){
		timer->start(60000/140*currentRegime);qDebug() << "looping";
		playOnce();
	}
	else{
		timer->stop();qDebug() << "unlooping";}


	//	while(b_loop)
//	{
		//playOnce();


//-		for(int i=1; i>=48; i++){
//-			if(std::fmod((i/48),currentRegime) == 0){ //O change regimes to integers
//-
//-			}
//-		}
	//}
}

void Looped::moveTempo(int row, bool changeColon)
{
	if(changeColon)
		currentRegimePtr[0] = !currentRegimePtr[0];

	if(currentRegimePtr[1]+row<0)
		currentRegimePtr[1] = 0;
	else if(currentRegimePtr[1]+row>5)
		currentRegimePtr[1] = 5;
	else
		currentRegimePtr[1] += row;

}



