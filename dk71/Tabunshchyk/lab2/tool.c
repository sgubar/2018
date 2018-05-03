#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

#define MAX_VALUE 10000



int random()
{
	int array_of_numbers[MAX_VALUE];
	int pos, letter_register;
	char symbol[MAX_VALUE];
	
	srand(time(NULL));

	
	FILE *default_letters = fopen("default_rand_letters.txt","w");
	
	for(pos = 0; pos < MAX_VALUE; pos++)
	{	
		
		letter_register = rand() % 2 + 1;
		
		switch(letter_register)
		{
			
			case 1:
				array_of_numbers[pos] = rand() % 26 + 65; 
				break;
			
			case 2:
				array_of_numbers[pos] = rand() % 26 + 97; 
				break;
			
			default: 
				break;
		}
	
 
		
		symbol[pos] = array_of_numbers[pos];
		fprintf(default_letters,"\n%c ", symbol[pos]); 
		printf("%c ", symbol[pos]);
	}
	
	
	fclose(default_letters);
	
	
	return &array_of_numbers;
}



int bubble(int *array_of_numbers_main)
{
	int  i, pos;
	int check;
	char symbol[MAX_VALUE];
	for(i = 0; i < MAX_VALUE - 1; i++) 
	{ 
   	for(pos = 0; pos < MAX_VALUE - i - 1; pos++) 
	   {  
		if(array_of_numbers_main[pos] > array_of_numbers_main[pos+1]) 
			{             
			check = array_of_numbers_main[pos];
   			array_of_numbers_main[pos] = array_of_numbers_main[pos+1];
			array_of_numbers_main[pos+1] = check; 
   			}
		}
    }
    
    FILE *bubble = fopen("bubble_sorted.txt", "w");
    
    for(pos = 0; pos < MAX_VALUE; pos++)
    {
    	symbol[pos] = array_of_numbers_main[pos];
    	fprintf(bubble, "\n%c ", symbol[pos]);
    
	}
	
	fclose(bubble);
	
		
   	return array_of_numbers_main;
}



int insertion(int *array_of_numbers_main)
	{
		int newElement, location;
		int pos;
		char symbol[MAX_VALUE];
 		for( pos = 1; pos < MAX_VALUE; pos++)
  	  	{
 	       newElement = array_of_numbers_main[pos];
 	       location = pos - 1;
 	       while(location >= 0 && array_of_numbers_main[location] > newElement)
 	       {
 	           array_of_numbers_main[location+1] = array_of_numbers_main[location];
 	           location = location - 1;
 	       }
 	       array_of_numbers_main[location+1] = newElement;
		}
		
		FILE *insertion = fopen("insertion_sorted.txt", "w");
		for(pos = 0; pos < MAX_VALUE; pos++)
 	   	{
    			symbol[pos] = array_of_numbers_main[pos];
    			fprintf(bubble, "\n%c ", symbol[pos]);
		}
		fclose(insertion);
		
    	return array_of_numbers_main;
	}
	
	
	
int selection(int *array_of_numbers_main)
	{
		int i, pos, min_idx, temp;
		char symbol[MAX_VALUE];
  	 	for (i = 0; i < MAX_VALUE - 1; i++)
   		{
    	    min_idx = i;
    	    for (pos = i + 1; pos < MAX_VALUE; pos++)
    	    {
    	    		if(array_of_numbers_main[pos] < array_of_numbers_main[min_idx])
    	        	min_idx = pos;
    	    }
     	   temp = array_of_numbers_main[min_idx];
     	   array_of_numbers_main[min_idx] = array_of_numbers_main[i];
    	    array_of_numbers_main[i] = temp;
     	}
    	FILE *selection = fopen("selection_sort.txt", "w");
    	for(pos = 0; pos < MAX_VALUE; pos++)
    		{
    			symbol[pos] = array_of_numbers_main[pos];
    			fprintf(selection, "\n%c ", symbol[pos]);
			}
			fclose(selection);
		return array_of_numbers_main;
 	}	
