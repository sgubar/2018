#include <stdio.h>
#include <time.h>
#include "Lab_3.h"

void swap (int *element1, int *element2)
{
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void random_filling(int *array, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if ((size >= 'A' && size <= 'Z') || (size >= 'a' && size <= 'z'))
		{
			array[i] = rand()%(char)size;
		}	
	}
}

void quick_sort(int *array, int first, int last)
{
	int middle, left, right;	
  	left = first;
	right = last;

  	middle = array[(left + right) / 2];

  	while (left <= right) 
	{
    	while (array[left] < middle) left++;

 	   	while (array[right] > middle) right--;

    	if (left <= right)
		{
        	swap(&array[left], &array[right]);
        	left++;
        	right--;

		}

  	}

  if (first < right) 
  quick_sort(array, first, right);

  if (left < last) 
  quick_sort(array, left, last);

}


int binary_search(int *array, int size, int el)

{

	int min = 0, max = size, aver;

	if(max%2 == 0) aver = max/2;
	else aver = max/2 + 1;

	if(array[max] == el || array[min] == el || array[aver] == el) return 1;

	while(max - min != 1)
	{

		if(array[max] == el || array[min] == el || array[aver] == el) return 1;

		if(array[aver] >= el) max = aver; 

		if(array[aver] < el) min = aver; 

		if((max+min)%2 == 0) aver = (max+min)/2 ;
		else aver = (max+min)/2 +1;

		if(array[aver] == el) return 1;
	}

	if(array[aver] == el) 

		return 1;

	else

		return 0;

}
