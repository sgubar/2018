#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

	
void random(int *randomArray)
	{
		srand(time(NULL));
		int i = 0;
		for ( i = 0; i < N; i ++)
			{
				randomArray[i] = rand();
			}

	}


	
void writeRandom(int *randomArray)
	{	
		int i = 0;
		FILE *f = fopen("test.txt", "w");
		for ( i = 1; i < N + 1; i ++ )
			{
				fprintf(f, "%d ", randomArray[i]);
				if ( i != 0 && i % 10 == 0)
					{
						fprintf(f, "\n");
					}
			}
		fclose(f);
	}		
	
	
void swap(int *a, int *b)
	{
	    int t = *a;
	    *a = *b;
	    *b = t;
	}
	
int partition (int arr[], int low, int high)
	{	
		int j;
	    int pivot = arr[high];   
	    int i = (low - 1);  
	 
	    for ( j = low; j <= high- 1; j++)
	    {

	        if (arr[j] <= pivot)              // here
	        {
	            i++;    
	            swap(&arr[i], &arr[j]);
	        }
	    }
	    swap(&arr[i + 1], &arr[high]);
	    return (i + 1);
	}

void quickSort(int arr[], int low, int high)
	{
	    if (low < high)
	    {
	        /* pi is partitioning index, arr[p] is now
	           at right place */
	        int pi = partition(arr, low, high);
	 
	        // Separately sort elements before
	        // partition and after partition
	        quickSort(arr, low, pi - 1);
	        quickSort(arr, pi + 1, high);
	    }
	}
 
	
	
	
void writeQuickSort(int *randomArray)
	{	
		int i = 0;
		FILE *f = fopen("QuickSort.txt", "w");
		for ( i = 1; i < N + 1; i ++ )
			{
				fprintf(f, "%d ", randomArray[i - 1]);
				if (  i % 10 == 0)
					{
						fprintf(f, "\n");
					}  
			}
		fclose(f);
	}
	
unsigned line_find(int anArray[], int aKey)
	{
		unsigned i;
		unsigned theResult = N;
		
		for (i = 0; i < N; i++)
		{
			if (anArray[i] == aKey)
			{
				theResult = 1;
				break;
			}
			else theResult = 0;
		}
		
		return theResult;
	}

