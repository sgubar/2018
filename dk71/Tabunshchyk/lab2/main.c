#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.c"

#define MAX_VALUE 10000



int main() 
{
	int menu, pos, start_t, end_t; 
	char symbol[MAX_VALUE];
	int array_of_numbers_main[MAX_VALUE];
	int sosrted_array[MAX_VALUE];
do
{

	

	printf("\nChoose ur action: \n 1.Make an array and display it \n 2.Make a Bubble Sort \n 3.Make an Insertion Sort \n 4.Make an Selection Sort \n 5.Exit\n\n\n\n" );
	scanf("%d", &menu);


	start_t = clock();
	
	switch(menu)
	{
		case 1:
	
			memcpy(array_of_numbers_main, random(), sizeof(array_of_numbers_main)); 
			
			for(pos = 0; pos < MAX_VALUE; pos++)
			{
				symbol[pos] = array_of_numbers_main[pos];
				printf("%c ", symbol[pos]);
			}
			
			break;
			
		case 2:
			
			memcpy(sosrted_array, bubble(array_of_numbers_main), sizeof(sosrted_array));
			
			for(pos = 0; pos < MAX_VALUE; pos++)
			{
				symbol[pos] = sosrted_array[pos];
				printf("%c  ", symbol[pos]);
			
			}
			
			break;
			
		case 3:
			
			memcpy(sosrted_array, insertion(array_of_numbers_main), sizeof(sosrted_array));
			
			for(pos = 0; pos < MAX_VALUE; pos++)
			{
				symbol[pos] = sosrted_array[pos];
				printf("%c  ", symbol[pos]);
			
			}
			
			break;
			
		case 4:
			
			memcpy(sosrted_array, selection(array_of_numbers_main), sizeof(sosrted_array));
			
			for(pos = 0; pos < MAX_VALUE; pos++)
			{
				symbol[pos] = sosrted_array[pos];
				printf("%c  ", symbol[pos]);
			
			}
			
			break;
			
	
		default:
			
			printf("\n u r numbnut \n");
			
			break;
	}
	
	
	end_t = clock();
	printf("\n Time: %d\n", end_t - start_t);
	



		
		
		
}
while (menu != 5);
		

	return 0;
}
