#include "dk_triangle2.h"
#include <stdlib.h>

triangle_t *create_triangle(point_t *A, point_t *B, point_t *C)
{
	triangle_t *theResult = NULL;

	if (NULL != A && NULL != B && NULL != C)
	{
		theResult = (triangle_t *)malloc(sizeof(triangle_t));
		if (NULL != theResult)
		{
			theResult->A = (point_t *)malloc(sizeof(point_t));
            theResult->A->x = A->x;
            theResult->A->y = A->y;
			theResult->B = (point_t *)malloc(sizeof(point_t));
            theResult->B->x = B->x;
            theResult->B->y = B->y;
			theResult->C = (point_t*)malloc(sizeof(point_t));
            theResult->C->x = C->x;
            theResult->C->y = C->y;
		}
	}

	return theResult;
}

float flat_triangle(triangle_t *atriangle)
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

void print_triangle(triangle_t *atriangle)
{
	if (NULL != atriangle)
	{
		printf ("\tCoordinates of vertices\n\n \t\tA(%d,%d)\n  \t\tB(%d,%d)\n  \t\tC(%d,%d)\n\n",
					atriangle->A->x, atriangle->A->y,atriangle->B->x, atriangle->B->y,atriangle->C->x, atriangle->C->y);
	}
}

void destroy_triangle(triangle_t *atriangle)
{
	if (NULL != atriangle)
	{
		free(atriangle->A);
		free(atriangle->B);
		free(atriangle->C);
		free(atriangle);
	}
}

void writePointToJSON(FILE *aFile, point_t *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writetriangleToJSON(FILE *aFile, triangle_t *atriangle)
{
	if (NULL == atriangle || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, atriangle->A);
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, atriangle->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, atriangle->C);
	fprintf(aFile, "\n}");
}


 void enter(int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}
