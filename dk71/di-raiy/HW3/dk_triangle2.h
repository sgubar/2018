#ifndef dk_triangle2
#define dk_triangle2
#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}point_t;

typedef struct tagtriangle
{
	point_t *A;
	point_t *B;
	point_t *C;
}triangle_t;

triangle_t *create_triangle(point_t *A, point_t *B, point_t *C);
void enter(int *X, int *Y);
void destroy_triangle(triangle_t *atriangle);
float flat_triangle(triangle_t *atriangle);
void print_triangle(triangle_t *atriangle);
void writePointToJSON(FILE *aFile, point_t *aPoint);
void writetriangleToJSON(FILE *aFile, triangle_t *atriangle);
#endif
