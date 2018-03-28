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


void write_to_file(int *wtf_arr, int size, char *wtf_tname)
{
	int i;
	char *wtf_name = malloc(strlen(wtf_tname)+5);
	sprintf(wtf_name, "%s.txt", wtf_tname);
	FILE *file = fopen(wtf_name, "w");
	
	for( i = 0; i < size; i++)
	 fprintf(file, "%c\n", wtf_arr[i]);
	
	fclose(file);
}

void read_from_file(int *rff_arr, char *rff_tname)
{
	int i=0;
	char *rff_name = malloc(strlen(rff_tname)+5);
	sprintf(rff_name, "%s.txt", rff_tname);
	FILE *file = fopen(rff_name, "r");

	while(!feof(file))  
	{
		fscanf(file, "%c\n", &rff_arr[i]);
		i++;
	}
	fclose(file);
}
	
void bubbleSort(int *array, int aSize)
{
	int theOut;
	int theIn;
	for (theOut = aSize - 1; theOut > 1; theOut --)
	{
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (array[theIn] > array[theIn + 1])
			{
				int theTmp = array[theIn];
				array[theIn] = array[theIn + 1];
				array[theIn + 1] = theTmp;
			}
		}
	}
}


void selectionSort(int *array, int aSize)
{
	int theOut;
	int theIn;
	for (theOut = 0; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn < aSize; theIn ++)
		{
			if (array[theIn] < array[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
	
		int theTmp = array[theOut];
		array[theOut] = array[theMinIndex];
		array[theMinIndex] = theTmp;
	}
}

void insertionSort(int *array, int aSize)
{
	int theOut;
	for (theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = array[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && array[theIn - 1] >= theTmp)
		{
			array[theIn] = array[theIn - 1];
			-- theIn;
		}
	
		array[theIn] = theTmp;
	}
}
