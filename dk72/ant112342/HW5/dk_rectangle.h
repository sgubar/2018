#ifndef dk_rectangle_h
#define dk_rectangle_h

#include <stdio.h>


typedef struct
{
	int x;
	int y;
}Point;


typedef struct tagLine
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Rectangle, *ppoint;

Point *copyCoordinateWithCoordinate(Point *Coordin);
Rectangle *createRectangle(Rectangle *A,Rectangle *B, Rectangle *C,Rectangle *D);
void destroyRectangle(Rectangle *aLine);
float lenghLine(Point *A,Point *B);
void printRectangle(Rectangle *aPoint);
int checktherectangle(Point *A,Point *B,Point *C,Point *D);
float Ploscha(Rectangle *Rectan);
void writeCoordinateToJSON(FILE *aFile, Point *aCoordinate);
void writeRectangleToJSON(FILE *aFile, Rectangle *aRectangle);

#endif


