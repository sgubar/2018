#include "dk_triangle.h"
#include <stdlib.h>



triangle_t *create(Point_t *A, Point_t *B, Point_t *C)
{
	triangle_t *theResult = NULL;

	if (NULL != A && NULL != B && NULL != C)
	{
		theResult = (triangle_t *)malloc(sizeof(triangle_t));
		if (NULL != theResult)
		{
			theResult->A = (Point_t *)malloc(sizeof(Point_t));
            theResult->A->x = A->x;
            theResult->A->y = A->y;
			theResult->B = (Point_t *)malloc(sizeof(Point_t));
            theResult->B->x = B->x;
            theResult->B->y = B->y;
			theResult->C = (Point_t *)malloc(sizeof(Point_t));
            theResult->C->x = C->x;
            theResult->C->y = C->y;
		}
	}

	return theResult;
}

float square(triangle_t *atriangle)
{
	float theResult = 0.0;

	if (NULL != atriangle)
	{
		float X = (atriangle->A->x - atriangle->C->x);
		float Y = (atriangle->B->y - atriangle->C->y);
		float Z = (atriangle->B->x - atriangle->C->x);
		float D = (atriangle->A->y - atriangle->C->y);
		theResult = abs(((X*Y) - (Z*D))/2);
	}

	return theResult;
}

void print_t(triangle_t *atriangle)
{
	if (NULL != atriangle)
	{
		printf ("Coordinates:\nA(%d,%d)\nB(%d,%d)\nC(%d,%d)\n\n",atriangle->A->x, atriangle->A->y,atriangle->B->x, atriangle->B->y,atriangle->C->x, atriangle->C->y);
	}
}



void delete_(triangle_t *atriangle)
{
	if (NULL != atriangle)
	{
		free(atriangle->A);
		free(atriangle->B);
		free(atriangle->C);
		free(atriangle);
	}
}
