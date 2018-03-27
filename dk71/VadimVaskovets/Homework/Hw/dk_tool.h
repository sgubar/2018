//
//  dk_tool.h
//  dz2
//
//  Created by Vadym Vaskovets on 3/27/18.
//  Copyright © 2018 Vadym Vaskovets. All rights reserved.
//
#include <stdio.h>
#ifndef dk_tool
	#define dk_triangle

typedef struct tagPoint
	{
		int x;
		int y;
	}
		Point;

typedef struct tagtriangle
	{
		Point *A;
		Point *B;
		Point *C;
	}
		triangle;

triangle *create_triangle(Point *A, Point *B, Point *C);
void destroy_triangle(triangle *atriangle);
float flat_triangle(triangle *atriangle);
void print_triangle(triangle *atriangle);

	#endif 
