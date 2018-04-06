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
	
	for(int wtf_i = 0; wtf_i < wtf_size; wtf_i++) fprintf(f, "%c", wtf_arr[wtf_i]);
	
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


/*
void shell_sort(int *ss_arr, int ss_size)
{	
	int ss_i, ss_j, ss_k;
	
	for(ss_i = ss_size/2; ss_i >= 1; ss_i /=2)
	{
		for(ss_j = 0; ss_j + ss_i < ss_size; ss_j++)
		{
			if(ss_arr[ss_j] > ss_arr[ss_j + ss_i])	
				swap(&ss_arr[ss_j], &ss_arr[ss_j + ss_i]);
			
			for(ss_k = ss_j; ss_k >= ss_i; ss_k-=ss_i)
			{
				if(ss_arr[ss_k] < ss_arr[ss_k - ss_i]) 
					swap(&ss_arr[ss_k], &ss_arr[ss_k - ss_i]);
				else 
					break;
			}
		}
	}
}
*/

int bin_search(int *bs_arr, int bs_size, int bs_el)
{
	int bs_min = 0, bs_max = bs_size, bs_aver;
	
	if(bs_max%2 == 0) bs_aver = bs_max/2;
		else bs_aver = bs_max/2 + 1;
	

	if(bs_arr[bs_max] == bs_el || bs_arr[bs_min] == bs_el || bs_arr[bs_aver] == bs_el) return 1;
	
	while(bs_max - bs_min != 1)
	{
		
		if(bs_arr[bs_max] == bs_el || bs_arr[bs_min] == bs_el || bs_arr[bs_aver] == bs_el) return 1;
		
		if(bs_arr[bs_aver] >= bs_el) bs_max = bs_aver; 
		if(bs_arr[bs_aver] < bs_el) bs_min = bs_aver; 
		
		if((bs_max+bs_min)%2 == 0) bs_aver = (bs_max+bs_min)/2 ;
		else bs_aver = (bs_max+bs_min)/2 +1;
		
		if(bs_arr[bs_aver] == bs_el) return 1;
	}
	
	if(bs_arr[bs_aver] == bs_el) 
		return 1;
	else
		return 0;
}

void quick_sort(int *qs_arr, int first, int last)
{
	int v, left, right;
	
  left = first;
  right = last;
  
  v = qs_arr[(left + right) / 2];
  while (left <= right)
  {
    while (qs_arr[left] < v) left++;
      
    while (qs_arr[right] > v) right--;
      
    if (left <= right)
	{
        swap(&qs_arr[left], &qs_arr[right]);
        left++;
        right--;
	}
  }
  if (first < right) quick_sort(qs_arr, first, right);
    
  if (left < last) quick_sort(qs_arr, left, last);
    
}

