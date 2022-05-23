#ifndef LINE_DRAWER_H
#define LINE_DRAWER_H

// Xiaolin Wu algo, from wikipedia
// arranged inside a struct
// with "next()/hasNext() iterator philosophy"
// to be independant from display techno.
//
// usage :
// struct LineDrawer d;
// start(&d, ....)
// while(!hasFinished(&d)
// {
// 		... use d._currX, ...
//		next(&d);
// }


struct LineDrawer
{
	//input
	float _yStart;
	float _xStart;
	float _yEnd;
	float _xEnd;

	//outout
	int _currY;
	int _currX;
	int _currYbis;
	int _currXbis;
	float _currDist;
	float _currDistBis;

	//private
	float __totalDy;
	float __totalDx;
	float __gradient;
	float __currFloatY;
	int __lastY;
	int __lastX;
	int __lastYbis;
	int __lastXbis;
	int __xIter;
	int __lastXIter;
	float __lastDist;
	float __lastDistBis;
	int __steep;//bool
};

void start(struct LineDrawer* drawer, float yStart, float xStart, float yEnd, float xEnd);
void next(struct LineDrawer* drawer);
int hasFinished(struct LineDrawer* drawer);

#endif // LINE_DRAWER_H

