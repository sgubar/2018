#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dru_arr.h"

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagTriangle
{
	Point *A;
	Point *B;
	Point *C;
	float S;
}triangle;

triangle *create_triangle(Point *A, Point *B, Point *C);
void enter(int *X, int *Y);
void destroy_triangle(triangle *atriangle);
float S_triangle(Point *A, Point *B, Point *C);
void print_triangle(triangle *atriangle);
void writePointToJSON(FILE *aFile, Point *aPoint);
void writetriangleToJSON(FILE *aFile, triangle *atriangle);
