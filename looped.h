#ifndef LOOPED_H
#define LOOPED_H

#include <QObject>
#include <QMediaPlayer>
#include <QTimer>



typedef const float regime;

class Looped : public QObject
{
		Q_OBJECT

	QTimer* timer = new QTimer(this);
	int splitter = 0; //split job between players

	float regimes[2][6] =  {{1.0/1, 1.0/2, 1.0/4, 1.0/8, 1.0/16, 1.0/32}, //? check if const pointer or values
							{1.0/1, 1.0/3, 1.0/6, 1.0/12,1.0/24, 1.0/48}};
	int currentRegimePtr[2] = {0,0}; //points to a "regimes" member
	#define currentRegime regimes[currentRegimePtr[0]][currentRegimePtr[1]]





public:
	explicit Looped(QObject *parent = 0, QString sample = "hat.wav", int volume = 100); //? explicit

	const static int bpm = 140;
	QMediaPlayer *player0 = new QMediaPlayer(this);
	QMediaPlayer *player1 = new QMediaPlayer(this);

	bool b_loop = 0;





signals:

public slots:
	void playOnce();
	void trap();
	void untrap();
	void loop(); //is unloop too
	void moveTempo(int row, bool changeColon=0);


};





#endif // LOOPED_H
