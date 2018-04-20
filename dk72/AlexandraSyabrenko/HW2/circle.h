#ifndef circle_h
#define circle_h

#include <stdio.h>

typedef struct tagPoint
{
    int x, y;
} Point;

typedef struct tagCircle
{
    Point *center;
    int radius;
} Circle;


float square(Circle *circle);


Circle *createCircle(Point *center , int radius);


Circle *createCircle2(int x, int y, int radius);


void printCircle(Circle *circle);


void destroyCircle(Circle *aCircle);


Point *copyPointWithPoint(Point *aPoint);


#endif /* circle_h */
