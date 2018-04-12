#ifndef __R3ARRAY
#define __R3ARRAY

#include "right_triangle.h"





typedef struct rtr_array{
	int len;
	int cur;
	prtriangle2d array;
}rtriangle_array;


rtriangle_array* new_rtriangle_array(int number);
int free_rtriangle_array(rtriangle_array* array);
int addto_rtriangle_array(rtriangle_array* array, prtriangle2d tri);
char* point_to_json(ppoint2d point);
char* rtri_to_json(prtriangle2d tri);
char* tarray_to_json(rtriangle_array* in);
//void quicksort(prtriangle2d in, int first, int last);
void quick_sort(prtriangle2d qs_arr, int first, int last);


#endif


















