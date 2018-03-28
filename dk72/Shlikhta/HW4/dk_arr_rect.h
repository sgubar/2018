#ifndef dk_arr_rect_h
#define dk_arr_rect_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "dk_rect.h"

typedef struct rect_arr
{
	int size;
	int count;
	float *square;
	
	ppoint *cell;
}rect_arr, *prect_arr;


prect_arr create_arr(int ca_size);

float calc_square(ppoint ppr_rect);

void delete_arr(prect_arr dela_rect);

void write_in_JSON(prect_arr wij_rect, char* wij_tname);

void insertion_sort(prect_arr is_rect);

#endif