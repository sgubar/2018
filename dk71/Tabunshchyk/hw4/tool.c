#include "tool.h"
#include <stdlib.h>
Point *copyPointWithPoint(Point *aPoint);

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

float flat_triangle(triangle *atriangle)
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

void print_triangle(triangle *atriangle)
{
	if (NULL != atriangle)
	{
		printf ("\tCoordinates of vertices\n\n \t\tA(%d,%d)\n  \t\tB(%d,%d)\n  \t\tC(%d,%d)\n\n",
					atriangle->A->x, atriangle->A->y,
					atriangle->B->x, atriangle->B->y,
					atriangle->C->x, atriangle->C->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *Result = (Point *)malloc(sizeof(Point));
	if (NULL != Result)
	{
		Result->x = aPoint->x;
		Result->y = aPoint->y;
	}
	
	return Result;
}

void destroy_triangle(triangle *atriangle)
{
	if (NULL != atriangle)
	{
		free(atriangle->A);
		free(atriangle->B);
		free(atriangle->C);
		free(atriangle);
	}
}

void write_point_to_JSON(FILE *before, Point *aPoint)
{
	if (NULL == aPoint || NULL == before)
	{
		return ;
	}

	fprintf(before, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void write_array_to_JSON(FILE *before, triangle *atriangle)
{
	if (NULL == atriangle || NULL == before)
	{
		return ;
	}

	fprintf(before, "{\n\"A\" : ");
	write_point_to_JSON(before, atriangle->A);
	fprintf(before, ",\n\"B\" : ");
	write_point_to_JSON(before, atriangle->B);
	fprintf(before, ",\n\"C\" : ");
	write_point_to_JSON(before, atriangle->C);
	fprintf(before, "\n}");
}
	

 void entering(int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}

