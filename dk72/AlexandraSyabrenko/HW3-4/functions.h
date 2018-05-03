#ifndef functions_h
#define functions_h

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

Circle *copyCircleWithCircle(Circle *circle);

void writeCircleToJSON(FILE *aFile, Circle *aCircle);

#endif /* functions_h */
