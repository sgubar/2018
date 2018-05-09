#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

#define MAX_VALUE 10000



int sort (void *a, void *b) 
{
	return ( *(int*)a - *(int*)b ); 
}


int random()
{
	int array_of_numbers[MAX_VALUE];
	int pos, letter_register;
	
	srand(time(NULL));

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
	
	}
	
	return &array_of_numbers;
}

int quick()
{
	return sort;
}

void search(int *array_of_numbers_main)
{
	int low, high, current, key;
	
	printf("\n\n\n\nWrite what are u searching: ");
	scanf("%d ", &key);
				
				
			
				
	low = 0;
	high = MAX_VALUE - 1;
				
				while(low <= high)
				{
					printf("adin");
					current = (high + low) / 2;
					if(key == array_of_numbers_main[current])
					{
						printf("\n\n\n\n%d found at location %d\nThis is done for %d\n", key, current+1);
						break; 
					}
					else 
					{
						if(key < array_of_numbers_main[current])
						{
							high = current -1;
						}
						else
						{
							low = current + 1;
						}
					}
				}
	
	if (low > high)
  	printf("\n\n\nNot found! %d isn't present in the list\nThis is done for %d\n", key);		
	
	
	
}





