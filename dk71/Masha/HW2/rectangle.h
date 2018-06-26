#include<stdio.h>
#ifndef dk_line_h
#define dk_line_h

typedef struct
{
	int x;
	int y;
}Coordinate;


typedef struct tagLine
{
	Coordinate *A;
	Coordinate *B;
	Coordinate *C;
	Coordinate *D;
}Point, *ppoint;

Coordinate *copyCoordinateWithCoordinate(Coordinate *Coordin);
Point *createRectangle(Coordinate *A, Coordinate *B, Coordinate *C,Coordinate *D);
void destroyRectangle(Point *aLine);
float lenghLine(Coordinate *A,Coordinate *B);
void printRectangle(Point *aPoint);
int checktherectangle(Coordinate *A,Coordinate *B,Coordinate *C,Coordinate *D);
float Ploscha(Point *Rectan);
#endif
