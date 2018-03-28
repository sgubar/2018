#include "dk_arr_rect.h"

prect_arr create_arr(int ca_size)
{
	rect_arr *ca_rect =  malloc(sizeof(rect_arr));
	ca_rect->cell = malloc(sizeof(r_point)*ca_size);
	ca_rect->square = malloc(sizeof(float)*ca_size);
	ca_rect->size = ca_size;
	
	return ca_rect;
}


void delete_arr(rect_arr *dela_rect)
{
	for(dela_rect->count = 0; dela_rect->count < dela_rect->size; dela_rect->count++)
	{

			deleting(dela_rect->cell[dela_rect->count]);

	}
	free(dela_rect->cell);
	free(dela_rect);
	printf("\nArray has deleted succesfull!:)\n");
}


void write_figure_in_JSON(prect_arr wfij_rect, FILE* wfij_f, int wfij_nf)
{
	
	fprintf(wfij_f, "\n				{");
	
	for(int wfij_i = 0; wfij_i < 4; wfij_i++)
	{
		fprintf(wfij_f, "\n						\"%dth\" : ", wfij_i);
		fprintf(wfij_f, "{\"x\" : %.1f, \"y\" : %.1f},", wfij_rect->cell[wfij_nf]->points[wfij_i]->x, wfij_rect->cell[wfij_nf]->points[wfij_i]->y);
	}
	
	fprintf(wfij_f, "\n						\"square\" : %.1f", wfij_rect->square[wfij_nf]);
	
	fprintf(wfij_f, "\n				},\n");
}


void write_in_JSON(prect_arr wij_rect, char* wij_tname)
{
	char* wij_name = malloc(strlen(wij_tname)+5);
	sprintf(wij_name, "%s.txt", wij_tname);
	
	FILE* wij_f = fopen(wij_name, "w");
	
	fprintf(wij_f, "{\n		\"number\" : %d,\n		\"count\" : %d,\n		\"rectangles\" :\n		[", wij_rect->size, wij_rect->count);
	
	for(int wij_i = 0; wij_i < wij_rect->size; wij_i++)
	{ 
		write_figure_in_JSON(wij_rect, wij_f, wij_i);
	}
	
	fprintf(wij_f, "\n		]\n}");
	fclose(wij_f);
}


float calc_square(ppoint ppar_rect)
{
	float AB, BC;
	
	AB = p_lenght(ret_point(ppar_rect,0,'x'), ret_point(ppar_rect,0,'y'), ret_point(ppar_rect,1,'x'), ret_point(ppar_rect,1,'y'));
	BC = p_lenght(ret_point(ppar_rect,1,'x'), ret_point(ppar_rect,1,'y'), ret_point(ppar_rect,2,'x'), ret_point(ppar_rect,2,'y'));
	
	return AB*BC;
}


void insertion_sort(prect_arr is_rect)
{
	float stemp;
	ppoint ctemp;
	
	for(int is_i = 1; is_i < is_rect->size; is_i++)
	{
		int is_j = is_i;
		
		while(is_rect->square[is_j] < is_rect->square[is_j-1]) 
		{
			stemp = is_rect->square[is_j];
			is_rect->square[is_j] = is_rect->square[is_j-1];
			is_rect->square[is_j-1] = stemp;
			
			ctemp = is_rect->cell[is_j];
			is_rect->cell[is_j] = is_rect->cell[is_j-1];
			is_rect->cell[is_j-1] = ctemp;
			
			is_j--;
		}
	}
}
