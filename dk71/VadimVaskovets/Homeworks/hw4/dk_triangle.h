
#ifndef dk_triangle
#define dk_triangle

#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagtriangle
{
	Point *A;
	Point *B;
	Point *C;
}triangle;
triangle *create_triangle(Point *A, Point *B, Point *C);
void enter(int *X, int *Y);
void destroy_triangle(triangle *atriangle);
float flat_triangle(triangle *atriangle);
void print_triangle(triangle *atriangle);
void writePointToJSON(FILE *aFile, Point *aPoint);
void writetriangleToJSON(FILE *aFile, triangle *atriangle);
#endif 
