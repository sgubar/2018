#include <stdio.h>
#include <time.h>
#include "ArrayFilling.h"


void random_filling(int *array, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(rand()%2 == 1) array[i] = rand()%('Z' + 1 - 'A')+'A';
		else array[i] = rand()%('z' + 1 - 'a')+'a';	
	}
}

void bubbleSort (int *array, int size)
{
    int start_time =  clock();

    int i, j;

    for (i = 1; i <= size - 1; i++)
    {
        for (j = 0; j <= size - 2; j++) {
            if (array[j] > array[j + 1])
            {
            	int temp = array[j];
    			array[j] = array[j+1];
    			array[j+1] = temp;
            }
        }
    }
    
    int end_time = clock();
    int sorting_time = (end_time) - (start_time);
    printf("Sorting time : %d ms", sorting_time);
}

void selectionSort (int *array, int size)
{
    int start_time =  clock();
    int i, j;

    for (i = 0; i < size; i++) 
	{
        int min = i;
        for (j = i+1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        int temp = array[min];
    	array[min] = array[i+1];
    	array[i+1] = temp;
    }

    int end_time = clock();
    int sorting_time = (end_time) - (start_time);
    printf("Sorting time : %d ms", sorting_time);
}

void insertionSort(int *array, int size)
{
    int start_time =  clock();
    int is_temp;
    int i;
	
	for(i = 1; i < size; i++)
	{
		int j = i;
		
		while(array[j] < array[j-1]) 
		{
			int temp = array[j];
    		array[j] = array[j-1];
    		array[j-1] = temp;
			j--;
		}
	}

    int end_time = clock();
    int sorting_time = (end_time) - (start_time);
    printf("Sorting time : %d ms", sorting_time);
}

void sorting_algoritm (int *array, int size, int choise)
{
	int i;
	switch(choise)
    {
        case 1:
            bubbleSort(array, size);
            FILE *bubble = fopen("sorted_array.txt", "w");
    		for (i = 0; i < size; i++)
    		{
        		fprintf(bubble, "%c ", array[i]);
    		}
    		fclose(bubble);
            break;
            
        case 2:
            selectionSort(array, size);
            FILE *selection = fopen("sorted_array.txt", "w");
    		for (i = 0; i < size; i++)
    		{
        		fprintf(selection, "%c ", array[i]);
    		}
    		fclose(selection);
            break;
            
        case 3:
            insertionSort(array, size);
            FILE *insertion = fopen("sorted_array.txt", "w");
    		for (i = 0; i < size; i++)
    		{
        		fprintf(insertion, "%c ", array[i]);
    		}
    		fclose(insertion);
            break;

    }

}
