#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point_t;

typedef struct tagtriangle
{
	Point_t *A;
	Point_t *B;
	Point_t *C;
}triangle_t;

triangle_t *create(Point_t *A, Point_t *B, Point_t *C);
void delete_(triangle_t *atriangle);
float square(triangle_t *atriangle);
void print_t(triangle_t *atriangle);

