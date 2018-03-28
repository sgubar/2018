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
	int *free_cell;	
	
	ppoint *cell;
}rect_arr, *prect_arr;


prect_arr create_arr(int ca_size);

int num_of_act();

int fnum_of_cell(int foc_max);

void delete_arr(prect_arr dela_rect);

void write_in_JSON(prect_arr wij_rect, char* wij_tname);

#endif