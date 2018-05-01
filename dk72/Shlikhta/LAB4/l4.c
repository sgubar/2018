#include "l4.h"

void add_an_data_to_file(char *aadtf_name, int aadtf_amount)
{
	FILE *f = fopen(aadtf_name, "w");
		for(int i = 0; i < aadtf_amount - 1; i++)
		{
			float k, t;
			
			k = rand()%128 - 64;
			t = rand()%20 - 10;
			k += t/100;
		
			fprintf(f, "%.1f\n", k);
		}
		
		fclose(f);
}

void print_data_from_file(char *pdff_name)
{
	FILE *pdff_file = fopen(pdff_name, "r");

	float pdff_tmp;
	
	
	while(!feof(pdff_file))
	{
		fscanf(pdff_file, "%f", &pdff_tmp);	
		printf("%.1f\n", pdff_tmp);
	}
	fclose(pdff_file);
}

void distribution_of_data_in_file(char *dodif_name, plist dodif_list_b, plist dodif_list_d, plist dodif_list_a, float dodif_min, float dodif_max)
{
	FILE *dodif_file = fopen(dodif_name, "r");
	
	float dodif_tmp;
	
	while(!feof(dodif_file))
	{
		fscanf(dodif_file, "%f", &dodif_tmp);
		
		if(dodif_tmp < dodif_min)
			add_el(dodif_list_b, dodif_tmp);
		
		if(dodif_tmp >= dodif_min && dodif_tmp <= dodif_max)
			add_el(dodif_list_d, dodif_tmp);
		
		if(dodif_tmp > dodif_max)
			add_el(dodif_list_a, dodif_tmp);
	}
	
	fclose(dodif_file);
}

int enter_a_number_of_elements()
{
	int eanoe_num_of_el;
	
	printf("Enter a number of elements which you want to see in file: ");
	scanf("%d", &eanoe_num_of_el);
	
	while(eanoe_num_of_el < 1)
	{
		printf(">>>Invalid number of elements<<<\nPlease try again\n");
		printf("Enter a number of elements which you want to see in file: ");
		scanf("%d", &eanoe_num_of_el);
	}
	return eanoe_num_of_el;
}