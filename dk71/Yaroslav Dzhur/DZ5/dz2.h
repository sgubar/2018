#ifndef dz2_h
#define dz2_h

#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagLine
{
	Point *A;
	Point *B;
}Line;

typedef struct tagTriangle
{
	Point *A;
	Point *B;
	Point *C;
}Triangle;

Line *createLine(Point *A, Point *B);
void destroyLine(Line *aLine);
float areaTriangle(Triangle *aTriangle);
float lenghLine(Line *aLine);
void printLine(Line *aLine);
void printTriangle(Triangle *aTriangle);
void destroyTriangle(Triangle *aTriangle);
Triangle *createTriangle(Point *A, Point *B, Point *C);

#endif /* dz2_h */
