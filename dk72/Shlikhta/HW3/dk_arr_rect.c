#include "dk_arr_rect.h"

prect_arr create_arr(int ca_size)
{
	rect_arr *ca_rect =  malloc(sizeof(rect_arr));
	
	ca_rect->cell = malloc(sizeof(r_point)*ca_size);
	ca_rect->size = ca_size;
	
	ca_rect->free_cell = malloc(sizeof(int)*ca_size);
	
	for(ca_rect->count = 0; ca_rect->count < ca_size; ca_rect->count++) ca_rect->free_cell[ca_rect->count] = 1;
	ca_rect->count = 0;	
	
	return ca_rect;
}

int num_of_act()
{
	int fnoa;
	printf("\n\n**Choose a number of action\n1 - write element to free cell\n2 - write element to my cell\n3 - write array to JSON\n4 - delete array\n");
	printf("Action number ");
	scanf("%d", &fnoa);
	
	while(fnoa < 1 || fnoa > 4)
	{
		printf("ERR Invalid number of action. Choose new :(\n");
		scanf("%d", &fnoa);
		printf("Action number ");
	}
	
	return fnoa;
}

int fnum_of_cell(int foc_max)
{
	int fnoc;
	printf("Enter a number of cell: ");
	scanf("%d", &fnoc);
	
	while(fnoc < 0 || fnoc > foc_max)
	{
		printf("#ERR Invalid number of cell\n");
		printf("Enter a number of cell: ");
		scanf("%d", &fnoc);
	}
	return fnoc;
}


void delete_arr(rect_arr *dela_rect)
{
	for(dela_rect->count = 0; dela_rect->count < dela_rect->size; dela_rect->count++)
	{
		if(dela_rect->free_cell[dela_rect->count] != 1)
		{
			deleting(dela_rect->cell[dela_rect->count]);
			dela_rect->free_cell[dela_rect->count] = 1;
		}
	}
	free(dela_rect->cell);
	free(dela_rect);
	printf("\nArray has deleted succesfull!:)\n");
}


void write_figure_in_JSON(ppoint wfij_rect, FILE* wfij_f)
{
	
	fprintf(wfij_f, "\n				{");
	
	for(int wfij_i = 0; wfij_i < 4; wfij_i++)
	{
		fprintf(wfij_f, "\n						\"%dth\" : ", wfij_i);
		fprintf(wfij_f, "{\"x\" : %.1f, \"y\" : %.1f},", wfij_rect->points[wfij_i]->x, wfij_rect->points[wfij_i]->y);
	}
	
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
		if(wij_rect->free_cell[wij_i] != 1) write_figure_in_JSON(wij_rect->cell[wij_i], wij_f);
	}
	
	fprintf(wij_f, "\n		]\n}");
	fclose(wij_f);
}


