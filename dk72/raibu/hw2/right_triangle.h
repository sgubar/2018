#ifndef _R3ANGLE
#define _R3ANGLE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <regex.h>

typedef struct p2d{
	double x,y;
}point2d, *ppoint2d;

typedef struct rt2d{
	ppoint2d points[3];
}rtriangle2d, *prtriangle2d;

typedef enum{
	VALID,
	INVALID
}params_check;

prtriangle2d new_rtriangle2d_arr(ppoint2d* arr);
prtriangle2d new_rtriangle2d_points(ppoint2d p0, ppoint2d p1, ppoint2d p2);
prtriangle2d new_rtriangle2d_coords(double x0, double y0, double x1, double y1, double x2, double y2);
void print_rtriangle(prtriangle2d in);
params_check validate(prtriangle2d triangle);
void triangle_free(prtriangle2d in);

void get_double(double* arg);
prtriangle2d enter_params();





#endif







