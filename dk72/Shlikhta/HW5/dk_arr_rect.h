#ifndef dk_arr_rect_h
#define dk_arr_rect_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct pnt
{
	float x, y;
}pnt;

typedef struct r_point
{
	pnt* points[4];
	
}r_point, *ppoint ;

typedef struct rect_arr
{
	int size;
	int count;
	
	ppoint *cell;
}rect_arr, *prect_arr;


void print_coord_point(ppoint pn_rect, int pn_point);

void enter_coord_point(ppoint en_rect, int en_point);

float p_lenght(float p_Ax, float p_Ay, float p_Bx, float p_By);

float ret_point(ppoint r_rect, int rpoint, char rtoc);

float ret_square(ppoint rs_rect);

float length_of_side(ppoint los_rect, int num_of_side);

ppoint enter_data();

void print_param(ppoint par_rect);

prect_arr create_arr(int ca_size);

void deleting(ppoint del_rect);

void delete_arr(rect_arr *da_rect);

void write_figure_in_JSON(prect_arr wfij_rect, FILE* wfij_f, int wfij_nf);

void write_in_JSON(prect_arr wij_rect, char* wij_tname);

void insertion_sort(prect_arr is_rect);

void shell_sort(prect_arr ss_rect);

int bin_search(prect_arr bs_arr, int bs_sq);

#endif