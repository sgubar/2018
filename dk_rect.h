#ifndef rect_h
#define rect_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



typedef struct pnt
{
	float x, y;
}pnt;

typedef struct r_point
{
	pnt *points[4];
	
}r_point, *ppoint ;

float p_lenght(float p_Ax, float p_Ay, float p_Bx, float p_By);

ppoint enter_data();

void print_param(ppoint par_rect);

void deleting(ppoint del_rect);

#endif