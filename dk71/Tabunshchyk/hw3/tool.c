#include "tool.h"
#include <stdlib.h>


triangle *create_triangle(Point *A, Point *B, Point *C)
{
	triangle *theResult = NULL;
	
	if (NULL != A && NULL != B && NULL != C)
	{
		theResult = (triangle *)malloc(sizeof(triangle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
		}
	}
	
	return theResult;
}

/*
float sqr_triangle(triangle *atriangle)
{
	float result;
	
	if (NULL != atriangle)
	{
		float a1 = (atriangle->A->x - atriangle->C->x);
		float a2 = (atriangle->B->y - atriangle->C->y);
		float a3 = (atriangle->B->x - atriangle->C->x);
		float a4 = (atriangle->A->y - atriangle->C->y);
		result = abs(((a1*a2) - (a3*a4))/2);
	}
	
	return result;
}
*/


void print_triangle(triangle *atriangle)
{
	if (NULL != atriangle)
	{
		printf ("Vertices\n\n \t\tA(%d,%d)\n  \t\tB(%d,%d)\n  \t\tC(%d,%d)\n\n",
					atriangle->A->x, atriangle->A->y,
					atriangle->B->x, atriangle->B->y,
					atriangle->C->x, atriangle->C->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *result = (Point *)malloc(sizeof(Point));
	if (NULL != result)
	{
		result -> x = aPoint -> x;
		result -> y = aPoint -> y;
	}
	
	return result;
}

void destroy_triangle(triangle *atriangle)
{
	if (NULL != atriangle)
	{
		free(atriangle -> A);
		free(atriangle -> B);
		free(atriangle -> C);
		free(atriangle);
	}
}

void point_to_json(FILE *file, Point *aPoint)
{
	if (NULL == aPoint || NULL == file)
	{
		return ;
	}

	fprintf(file, "{\"x\" : %d, \"y\" : %d, \"z\"}", aPoint->x, aPoint->y);
}

void triangle_to_json(FILE *file, triangle *atriangle)
{
	if (NULL == atriangle || NULL == file)
	{
		return ;
	}

	fprintf(file, "{\n\"A\" : ");
	point_to_json(file, atriangle->A);
	
	fprintf(file, ",\n\"B\" : ");
	point_to_json(file, atriangle->B);
	
	fprintf(file, ",\n\"C\" : ");
	point_to_json(file, atriangle->C);
	
	fprintf(file, "\n}");
}
	

void triangle_entering(int *X, int *Y)
{
    printf("x= ");
    scanf("%d", X);
    printf("y= ");
    scanf("%d", Y);
}

