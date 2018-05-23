#ifndef tool
#define tool

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
void write_point_to_JSON(FILE *before, Point *aPoint);
void write_triangle_to_JSON(FILE *before, triangle *atriangle);
#endif 
