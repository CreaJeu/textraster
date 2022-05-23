#include "LineDrawer.h"
#include <math.h>


//for Xiaolin Wu algo
float xw_round(float w)
{
	return floor(w + .5);
}
float xw_fpart(float w)
{
	return w - floor(w);
}
float xw_rfpart(float w)
{
	return 1 - xw_fpart(w);
}

void start(struct LineDrawer* d, float yStart, float xStart, float yEnd, float xEnd)
{
	d->_yStart = yStart;
	d->_xStart = xStart;
	d->_yEnd = yEnd;
	d->_xEnd = xEnd;

	d->__totalDy = d->_yEnd - d->_yStart;
	d->__totalDx = d->_xEnd - d->_xStart;
	d->__steep = fabs(d->__totalDy) > fabs(d->__totalDx);
	float tmpSwap = 0;

	if(d->__steep)
	{
		//swap x<->y
		d->_yStart = xStart;
		d->_xStart = yStart;
		d->_yEnd = xEnd;
		d->_xEnd = yEnd;
	}

	if(d->_xStart > d->_xEnd)
	{
		//swap start<->end
		tmpSwap = d->_yStart;
		d->_yStart = d->_yEnd;
		d->_yEnd = tmpSwap;
		tmpSwap = d->_xStart;
		d->_xStart = d->_xEnd;
		d->_xEnd = tmpSwap;
	}

	d->__totalDy = d->_yEnd - d->_yStart;
	d->__totalDx = d->_xEnd - d->_xStart;
	if(fabs(d->__totalDx) < 1) // dx == 0
	{
		d->__gradient = 1;//line reduced to a point anyway
	}
	else
	{
		d->__gradient = d->__totalDy / d->__totalDx;
	}
	d->_currDist = 0;

	// ------ handle first curr x/y
	float intXend = xw_round(d->_xStart);
	float floatYend = d->_yStart + d->__gradient * (intXend - d->_xStart);
	float xGap = xw_rfpart(d->_xStart + .5);
	if(d->__steep)
	{
		// un-swap x<->y
		d->_currX = (int)floor(floatYend);
		d->_currY = (int)intXend;
		d->_currXbis = d->_currX + 1;
		d->_currYbis = d->_currY;
	}
	else
	{
		d->_currX = (int)intXend;
		d->_currY = (int)floor(floatYend);
		d->_currXbis = d->_currX;
		d->_currYbis = d->_currY + 1;
	}
	d->_currDist = xw_rfpart(floatYend) * xGap;
	d->_currDistBis = xw_fpart(floatYend) * xGap;
	d->__currFloatY = floatYend;
	d->__xIter = ((int)intXend);

	// ------ prepare last point, for later at the end of the loop
	d->__lastX = (int)xw_round(d->_xEnd);
	d->__lastXIter = d->__lastX;
	floatYend = d->_yEnd + d->__gradient * (d->__lastX - d->_xEnd);
	xGap = xw_fpart(d->_xEnd + .5);
	if(d->__steep)
	{
		d->__lastY = d->__lastX;
		d->__lastX = (int)floor(floatYend);
		d->__lastYbis = d->__lastY;
		d->__lastXbis = d->__lastX + 1;
	}
	else
	{
		d->__lastY = (int)floor(floatYend);
		d->__lastX = d->__lastX;
		d->__lastYbis = (int)floor(floatYend) + 1;
		d->__lastXbis = d->__lastX;
	}
	d->__lastDist = xw_rfpart(floatYend) * xGap;
	d->__lastDistBis = xw_fpart(floatYend) * xGap;
}

void next(struct LineDrawer* d)
{
	d->__xIter++;
	if(d->__xIter > d->__lastXIter)
	{
		return;
	}
	if(d->__xIter == d->__lastXIter)
	{
		d->_currY = d->__lastY;
		d->_currX = d->__lastX;
		d->_currDist = d->__lastDist;
		d->_currYbis = d->__lastYbis;
		d->_currXbis = d->__lastXbis;
		d->_currDistBis = d->__lastDistBis;

		return;
	}

	d->__currFloatY += d->__gradient;
	if(d->__steep)
	{
		d->_currY = d->__xIter;
		d->_currX = (int)floor(d->__currFloatY);
		d->_currDist = xw_rfpart(d->__currFloatY);
		d->_currYbis = d->__xIter;
		d->_currXbis = (int)floor(d->__currFloatY) + 1;
		d->_currDistBis = xw_fpart(d->__currFloatY);
	}
	else
	{
		d->_currY = (int)floor(d->__currFloatY);
		d->_currX = d->__xIter;
		d->_currDist = xw_rfpart(d->__currFloatY);
		d->_currYbis = (int)floor(d->__currFloatY) + 1;
		d->_currXbis = d->__xIter;
		d->_currDistBis = xw_fpart(d->__currFloatY);
	}
}

int hasFinished(struct LineDrawer* d)
{
	return d->__xIter > d->__lastXIter;
}

