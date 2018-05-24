#ifndef circle
#define circle
#include <stdio.h>
#include <math.h>


//Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

//Circle description
typedef struct tagCircle
{
     Point *Center;
     Point *Radius;

} Circle;

typedef struct tagCircleArray
{
	int number;
	int count;
	Circle **Circles;
} CircleArray;

// Init interface
Circle *createCircle(Point *Center , Point *Radius);
void FreeCircle(Circle *aCircle);
void writePointToJSON(FILE *aFile, Point *aPoint);
float SquareCircle(Circle *aCircle);
void printCircle(Circle *aCircle);
Point *copyPointWithPoint(Point *aPoint);
void writeCircletToJSON(FILE *aFile, Circle *aCircle);

CircleArray *CreateArray(int aNumber);
void freeArray(CircleArray *InstantArray);
void addElement(CircleArray *InstantArray, Circle *aCircle);
void writeArrayToJSON(FILE *aFile, CircleArray *InstantArray);
void insertion_sort(CircleArray *InstantArray);


#endif
