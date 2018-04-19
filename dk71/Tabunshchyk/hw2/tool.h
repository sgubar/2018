#ifndef tool
#define tool

#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
} Point;

typedef struct tagtriangle
{
	Point *A;
	Point *B;
	Point *C; 
} triangle;



triangle *create_triangle(Point *A, Point *B, Point *C);
void destroy_triangle(triangle *atriangle);
float sqr_triangle(triangle *atriangle);
void print_triangle(triangle *atriangle);












#endif 
