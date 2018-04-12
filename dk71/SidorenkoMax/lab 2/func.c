#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define N 10000


int random()
	{
		int a;
		int mass1[N];
		FILE * fp = fopen("data.txt", "w");
		for(a=0;a<N; a++)
		{
			mass1[a] = rand();
			fprintf(fp, "%d ", mass1[a]);
		}
		fclose(fp);
		return &mass1;
	}
	
int bubblesort(int *mass)
	{
		int  i, j;
		for(i = 0 ; i < N - 1; i++) { 
       		for(j = 0 ; j < N - i - 1 ; j++) {  
          		if(mass[j] > mass[j+1]) {             
            	int tmp = mass[j];
            	mass[j] = mass[j+1] ;
            	mass[j+1] = tmp; 
           		}
        	}
    	}
    	FILE * fp1 = fopen("bubblesort.txt", "w");
    	for(j=0;j<N;j++)
    		{
    			fprintf(fp1, "%d ", mass[j]);
    			if(j%10 == 0)
    				{
    					fprintf(fp1, "\n");
					}
			}
		fclose(fp1);
    	return mass;
	}
	
int insertionsSort(int *mass)
	{
	int newElement, location;
	int j;
 	for( j = 1; j < N; j++)
    {
        newElement = mass[j];
        location = j - 1;
        while(location >= 0 && mass[location] > newElement)
        {
            mass[location+1] = mass[location];
            location = location - 1;
        }
        mass[location+1] = newElement;
	}
	FILE * fp2 = fopen("insertionsSort.txt", "w");
	for(j=0;j<N;j++)
    		{
    			fprintf(fp2, "%d ", mass[j]);
    			if(j%10 == 0)
    				{
    					fprintf(fp2, "\n");
					}
			}
		fclose(fp2);
    	return mass;
	}
	
	
int selecrionsort(int *mass)
	{
	int i, j, min_idx, temp;
    for (i = 0; i < N-1; i++)
    	{
        min_idx = i;
        for (j = i+1; j < N; j++)
        	{
        		if(mass[j] < mass[min_idx])
            	min_idx = j;
        	}
        temp = mass[min_idx];
        mass[min_idx] = mass[i];
        mass[i] = temp;
        }
    FILE * fp3 = fopen("selectionsort.txt", "w");
    	for(j=0;j<N;j++)
    		{
    			fprintf(fp3, "%d ", mass[j]);
    			if(j%10 == 0)
    				{
    					fprintf(fp3, "\n");
					}
			}
		fclose(fp3);
	return mass;
 	}
