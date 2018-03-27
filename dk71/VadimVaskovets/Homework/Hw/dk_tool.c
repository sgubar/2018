//
//  dk_tool.c
//  dz2
//
//  Created by Vadym Vaskovets on 3/27/18.
//  Copyright © 2018 Vadym Vaskovets. All rights reserved.
//
#include "dk_tool.h"
#include <stdlib.h>

Point *copyPointWithPoint(Point *aPoint);

triangle *create_triangle(Point *A, Point *B, Point *C)
	{
	triangle *Result = NULL;
	
	if (NULL != A && NULL != B && NULL != C)
		{
			Result = (triangle *)malloc(sizeof(triangle));
			if (NULL != Result)
			{
				Result->A = copyPointWithPoint(A);
				Result->B = copyPointWithPoint(B);
				Result->C = copyPointWithPoint(C);
			}
		}
	
		return Result;
	}

float flat_triangle(triangle *atriangle)
	{
		float Result = 0.0;
	
		if (NULL != atriangle)
		{
			float X = (atriangle->A->x - atriangle->C->x);
			float Y = (atriangle->B->y - atriangle->C->y);
			float Z = (atriangle->B->x - atriangle->C->x);
			float D = (atriangle->A->y - atriangle->C->y);
			Result = abs(((X*Y) - (Z*D))/2);
		}
		return Result;
	}

void print_triangle(triangle *atriangle)
	{
		if (NULL != atriangle)
		{
			printf ("\tÊîîðäèíàòû òî÷åê:\n\n \tA(%d,%d)\n  \tB(%d,%d)\n  \tC(%d,%d)\n\n",
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
