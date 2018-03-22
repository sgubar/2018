#ifndef dz2_h
#define dz2_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagLine
{
	Point *A;
	Point *B;
}Line;

//Trapeze description
typedef struct tagTrapeze
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Trapeze;

// Init interface
Line *createLine(Point *A, Point *B);
void destroyLine(Line *aLine);
double areaTrapeze(Trapeze *aTrapeze);
float lenghLine(Line *aLine);
void printLine(Line *aLine);
void printTrapeze(Trapeze *aTrapeze);
void destroyTrapeze(Trapeze *aTrapeze);
Trapeze *createTrapeze(Point *A, Point *B, Point *C, Point *D);

#endif /* dz2_h */
