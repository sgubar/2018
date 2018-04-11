#include "dk_arr_rect.h"


void print_coord_point(ppoint pn_rect, int pn_point) 												//print coordinates of figure in format: (x,y)
{
	printf("(%.2f,%.2f)  \n", pn_rect->points[pn_point]->x, pn_rect->points[pn_point]->y);
}

void enter_coord_point(ppoint en_rect, int en_point) 												//get coordinates of figure in format: x y
{
	scanf("%f %f", &en_rect->points[en_point]->x, &en_rect->points[en_point]->y);
}

float p_lenght(float p_Ax, float p_Ay, float p_Bx, float p_By) 										//return the length of side of figure
{
	return sqrt((p_Bx-p_Ax)*(p_Bx-p_Ax)+(p_By-p_Ay)*(p_By-p_Ay));
};

float ret_point(ppoint r_rect, int rpoint, char rtoc)
{
	if(rtoc == 'x') return r_rect->points[rpoint]->x;
	else return r_rect->points[rpoint]->y;
}

float ret_square(ppoint rs_rect)
{	
	return p_lenght(ret_point(rs_rect,0,'x'), ret_point(rs_rect,0,'y'), ret_point(rs_rect,1,'x'), ret_point(rs_rect,1,'y'))*
		p_lenght(ret_point(rs_rect,1,'x'), ret_point(rs_rect,1,'y'), ret_point(rs_rect,2,'x'), ret_point(rs_rect,2,'y'));
}
/*
	2
   ____
 1|____|3
	4
*/
float length_of_side(ppoint los_rect, int num_of_side)
{
	if(num_of_side == 1 || num_of_side == 3)
		return p_lenght(ret_point(los_rect,0,'x'), ret_point(los_rect,0,'y'), ret_point(los_rect,1,'x'), ret_point(los_rect,1,'y'));
	else if(num_of_side == 2 || num_of_side == 4)
		return p_lenght(ret_point(los_rect,1,'x'), ret_point(los_rect,1,'y'), ret_point(los_rect,2,'x'), ret_point(los_rect,2,'y'));
	else
		return -1;
}


ppoint enter_data() 																				//get coordinates of figures and check it for right
{
	
	ppoint ed_rect = malloc(sizeof(r_point));
	
	for(int i = 0; i < 4;i++) ed_rect->points[i] = malloc(sizeof(pnt));
	
	printf("Enter a coordinates of rectangle: \n");
	
	for(int i = 0; i < 4; i++)
	{
		printf("%dth ", i);
		enter_coord_point(ed_rect, i);
	}
																									//checking for a right entering temp_rect->points[0]->x
	while(p_lenght(ret_point(ed_rect,0,'x'), ret_point(ed_rect,0,'y'), ret_point(ed_rect,2,'x'), ret_point(ed_rect,2,'y')) 
				!= p_lenght(ret_point(ed_rect,1,'x'), ret_point(ed_rect,1,'y'), ret_point(ed_rect,3,'x'), ret_point(ed_rect,3,'y')))
	{
		printf("ERR((( ->Invalid coordinates<-\nEnter a coordinates of rectangle: \n");
	
		for(int i = 0; i < 4; i++)
		{
			printf("%dth ", i);
			enter_coord_point(ed_rect, i);
		}	
	}
	
	printf("\nThe rectangle is right))\n\n");
	
	return ed_rect;
};


void print_param(ppoint par_rect)
{	
	printf("Parameters of rectangle:\n");
	
	printf("    ****Coordinates****\n");
	
	for(int i = 0; i < 4; i++) 
	{
		printf("%dth = ", i);
		print_coord_point(par_rect, i);
	}

	printf("\n   ****Length of sides****\nAB = CD = %.2f\nBC = AD = %.2f\n\n", length_of_side(par_rect, 1), length_of_side(par_rect, 2));
	
	printf("   ****Square****\nS = %.2f sq. un.\n", ret_square(par_rect));
	
};

prect_arr create_arr(int ca_size)
{
	prect_arr ca_rect =  malloc(sizeof(rect_arr));
	ca_rect->cell = malloc(sizeof(r_point)*ca_size);
	ca_rect->size = ca_size;
	
	return ca_rect;
}

void deleting(ppoint del_rect)
{
	for(int i = 0; i < 4; ++i) free(del_rect->points[i]); 
	
	free(del_rect);
}

void delete_arr(rect_arr *da_rect)
{
	for(int dda_i = 0; dda_i < da_rect->count; dda_i++)
		deleting(da_rect->cell[dda_i]);
		
	free(da_rect->cell);
	free(da_rect);
	printf("\nArray has deleted successful!:)\n");
}


void write_figure_in_JSON(prect_arr wfij_rect, FILE* wfij_f, int wfij_nf)
{
	
	fprintf(wfij_f, "\n						{");
	
	for(int wfij_i = 0; wfij_i < 4; wfij_i++)
	{
		fprintf(wfij_f, "\n								\"%dth\" : ", wfij_i);
		fprintf(wfij_f, "{\"x\" : %.1f, \"y\" : %.1f},", ret_point(wfij_rect->cell[wfij_nf], wfij_i, 'x'), ret_point(wfij_rect->cell[wfij_nf], wfij_i, 'y'));
	}
	
	fprintf(wfij_f, "\n								\"square\" : %.1f", ret_square(wfij_rect->cell[wfij_nf]));
	
	fprintf(wfij_f, "\n						},\n");
}


void write_in_JSON(prect_arr wij_rect, char* wij_tname)
{
	char* wij_name = malloc(strlen(wij_tname)+5);
	sprintf(wij_name, "%s.txt", wij_tname);
	
	FILE* wij_f = fopen(wij_name, "w");
	
	fprintf(wij_f, "{\n		\"number\" : %d,\n		\"count\" : %d,\n		\"cell\" :\n		[", wij_rect->size, wij_rect->count);
	
	for(int wij_i = 0; wij_i < wij_rect->count; wij_i++)
	{ 
		fprintf(wij_f, "\n						\"points\" : ", wij_i);
		write_figure_in_JSON(wij_rect, wij_f, wij_i);
	}
	
	fprintf(wij_f, "\n		]\n}");
	fclose(wij_f);
}

void insertion_sort(prect_arr is_rect)
{
	ppoint ctemp;
	
	for(int is_i = 0; is_i < is_rect->size; is_i++)
	{
		int is_j = is_i;
		
		while(ret_square(is_rect->cell[is_j]) < ret_square(is_rect->cell[is_j-1])) 
		{
			ctemp = is_rect->cell[is_j];
			is_rect->cell[is_j] = is_rect->cell[is_j-1];
			is_rect->cell[is_j-1] = ctemp;
			
			is_j--;
		}
	}
}

void shell_sort(prect_arr ss_rect)
{	
	int ss_i, ss_j, ss_k;
	
	ppoint ss_temp;

	for(ss_i = (ss_rect->size)/2; ss_i >= 1; ss_i /= 2)
	{
		for(ss_j = 0; (ss_j + ss_i) < ss_rect->count; ss_j++)
		{
			if(ret_square(ss_rect->cell[ss_j]) > ret_square(ss_rect->cell[ss_j + ss_i]))	
			{
				ss_temp = ss_rect->cell[ss_j];
				ss_rect->cell[ss_j] = ss_rect->cell[ss_j + ss_i];
				ss_rect->cell[ss_j + ss_i] = ss_temp;
			}
			
			for(ss_k = ss_j; ss_k >= ss_i; ss_k-=ss_i)
			{
				if(ret_square(ss_rect->cell[ss_k]) < ret_square(ss_rect->cell[ss_k - ss_i])) 
				{
					ss_temp = ss_rect->cell[ss_k];
					ss_rect->cell[ss_k] = ss_rect->cell[ss_k - ss_i];
					ss_rect->cell[ss_k - ss_i] = ss_temp;	
				}
				else 
					break;
			}
		}
	}
}

int bin_search(prect_arr bs_arr, int bs_sq)
{
	int bs_min = 0, bs_max = bs_arr->count-1, bs_aver;
	
	if(bs_max%2 == 0) bs_aver = bs_max/2;
		else bs_aver = bs_max/2 + 1;
	
	do
	{
		if(ret_square(bs_arr->cell[bs_max]) == bs_sq){ print_param(bs_arr->cell[bs_max]); return 1;}
			if(ret_square(bs_arr->cell[bs_min]) == bs_sq){  print_param(bs_arr->cell[bs_min]); return 1;} 
				if(ret_square(bs_arr->cell[bs_aver]) == bs_sq){ print_param(bs_arr->cell[bs_aver]); return 1;}
		
		if(ret_square(bs_arr->cell[bs_aver]) >= bs_sq) bs_max = bs_aver; 
			if(ret_square(bs_arr->cell[bs_aver]) < bs_sq) bs_min = bs_aver; 
		
		if((bs_max+bs_min)%2 == 0) bs_aver = (bs_max+bs_min)/2 ;
		else bs_aver = (bs_max+bs_min)/2 +1;
		
		if(ret_square(bs_arr->cell[bs_aver]) == bs_sq){ print_param(bs_arr->cell[bs_aver]); return 1;}
		
	}while(bs_max - bs_min > 1);
	
	if(ret_square(bs_arr->cell[bs_aver]) == bs_sq) 
		{print_param(bs_arr->cell[bs_aver]); return 1;}
	else
		{printf("I'm sorry but, I cannot find element which you need:(\nPlease try again.\n"); return 0;}
}