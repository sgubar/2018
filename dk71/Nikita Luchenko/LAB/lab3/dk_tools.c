#include "dk_tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int enter_arr_size()
{
	int size = 0;

	FILE *file = fopen("text.txt", "rb");
	if (file)
	{
 	  fseek(file, 0, SEEK_END);
 	  size = ftell(file);
 	  fclose (file);
	}
	
	if (size == 0 || size > 1000000)
	{
		printf("ERR Invalid size of array");
		return 0;
	}
	return size;
	
}


void write_to_file(char *wtf_arr, int size, char *wtf_tname)
{
	int i;
	char *wtf_name = malloc(strlen(wtf_tname));
	sprintf(wtf_name, "%s.txt", wtf_tname);
	FILE *file = fopen(wtf_name, "w");
	
	for( i = 0; i < size; i++)
	 fprintf(file, "%c\n", wtf_arr[i]);
	 
	fclose(file);
}

void read_from_file(char *rff_arr, char *rff_tname)
{
	int i=0;
	char *rff_name = malloc(strlen(rff_tname));
	sprintf(rff_name, "%s.txt", rff_tname);
	FILE *file = fopen(rff_name, "r");

	while(!feof(file))  
	{
		fscanf(file, "%c\n", &rff_arr[i]);
		i++;
	}
	fclose(file);
}
	
int line_search(char *array, char key, int size)
{
	int i;
	int pos;
    for (i = 0; i < size; i++)
    {
        if(array[i] == key)
        {
		printf("\n\n\tFIND!\n");
		pos=i;
		return pos;
		}
    }	
    return 0;
}


void swap(char *one, char *two)
{
	char three = *one;
	*one = *two;
	*two = three;
}

void quick_sort(char *array, int first, int last)
{
int mid, left, right;
	
  left = first;
  right = last;
  
  mid = array[(left + right) / 2];
  while (left <= right)
  {
    while (array[left] < mid) left++;
      
    while (array[right] > mid) right--;
      
    if (left <= right)
	{
        swap(&array[left], &array[right]);
        left++;
        right--;
	}
  }
  if (first < right) quick_sort(array, first, right);
    
  if (left < last) quick_sort(array, left, last);
    
}
