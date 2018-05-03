#ifndef _CIRCLE_H
#define _CIRCLE_H

//Point description
typedef struct tagPoint_x
{
	int x;
	int y;
}Point;

//Circle description
typedef struct tagCircle
{
	Point *C;
}Circle;

// Init interface
Circle *createCircle(Point *C);
void destroyCircle(Circle *aCircle);
float SquareCircle(Circle *aCircle);
void printCircle(Circle *aCircle);
Point *copyPointWithPoint(Point *aPoint);

#endif
