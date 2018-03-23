#include "l2.h"

inline void swap(int *s_a, int *s_b)
{
	int s_c = *s_a;
	*s_a = *s_b;
	*s_b = s_c;
}

int enter_arr_size()
{
	int ea_size;
	printf("Enter a size of array: ");
	scanf("%d", &ea_size);
	printf("You have entered: %d\n", ea_size);
	
	while(ea_size <= 0 || ea_size > 2000000000)
	{
		printf("ERR Invalid size of array:(\nEnter new: ");
		scanf("%d", &ea_size);
		printf("You have entered: %d\n", ea_size);
	}
	return ea_size;
}

void ent_data_to_arr(int *edta_arr, int edta_size)
{
	for(int edta_i = 0; edta_i < edta_size; edta_i++)
	{
		if(rand()%2 == 1) edta_arr[edta_i] = rand()%('Z' + 1 - 'A')+'A';
		else edta_arr[edta_i] = rand()%('z' + 1 - 'a')+'a';	
	}
}

void write_to_file(int *wtf_arr, int wtf_size, char *wtf_tname)
{
	char *wtf_name = malloc(strlen(wtf_tname)+5);
	sprintf(wtf_name, "%s.txt", wtf_tname);
	FILE *f = fopen(wtf_name, "w");
	
	for(int wtf_i = 0; wtf_i < wtf_size; wtf_i++) fprintf(f, "%c\n", wtf_arr[wtf_i]);
	
	fclose(f);
}

void read_from_file(char *rff_tname)
{
	char *rff_name = malloc(strlen(rff_tname)+5);
	sprintf(rff_name, "%s.txt", rff_tname);
	FILE *f = fopen(rff_name, "r");
	char *k;
	
	while(!feof(f))
 		{
 			int res = fscanf(f,"%c", &k);
 			if (res == EOF) break;
 			printf("%c",k);
 		}
		fclose(f);	
}

int find_min(int *fm_arr, int fm_min_broad, int fm_max_broad)
{
	int fm_min = fm_arr[fm_min_broad], fm_ind_min = fm_min_broad;
	
	for(int fm_i = fm_min_broad; fm_i < fm_max_broad; fm_i++) 
		if(fm_min > fm_arr[fm_i])
		{ 
			fm_ind_min = fm_i; 
			fm_min = fm_arr[fm_i]; 
		}
	
	return fm_ind_min;
}

int find_max(int *fm_arr, int fm_min_broad, int fm_max_broad)
{
	int fm_max = fm_arr[fm_min_broad], fm_ind_max = fm_min_broad;
	
	for(int fm_i = fm_min_broad; fm_i < fm_max_broad; fm_i++) 
		if(fm_max < fm_arr[fm_i])
		{ 
			fm_ind_max = fm_i; 
			fm_max = fm_arr[fm_i]; 
		}
	
	return fm_ind_max;
}

void chousen_sort(int *cs_arr, int cs_size)
{
	for(int cs_i = 0; cs_i < cs_size; cs_i++) 
		swap(&cs_arr[find_min(cs_arr, cs_i, cs_size)],&cs_arr[cs_i]);	
}

void bubble_sort(int *bs_arr, int bs_size)
{
	for(int bs_i = 0; bs_i < bs_size-1; bs_i++)
	{
		for(int bs_j = 0; bs_j < bs_size-1 ; bs_j++)
			if(bs_arr[bs_j] > bs_arr[bs_j+1]) swap(&bs_arr[bs_j], &bs_arr[bs_j+1]);
	}
}

void insertion_sort(int *is_arr, int is_size)
{
	int is_temp;
	
	for(int is_i = 1; is_i < is_size; is_i++)
	{
		int is_j = is_i;
		
		while(is_arr[is_j] < is_arr[is_j-1]) 
		{
			swap(&is_arr[is_j],&is_arr[is_j-1]);
			is_j--;
		}
	}
}
