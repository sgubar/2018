#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.c"

#define MAX_VALUE 10000
  


int main() 
{
	int menu, pos, start_t, end_t; 
	int array_of_numbers_main[MAX_VALUE];
	int sosrted_array[MAX_VALUE];
	
	
	char symbol[MAX_VALUE];
	char key_char;
	
	do
	{

		printf("\nChoose ur action: \n 1.Make an array and display it \n 2.Make a Quick Sort \n 3.Make a Binary Search \n 4.Exit\n\n\n\n" );
		scanf("%d", &menu);
	
		
	
	
		
		switch(menu)
		{
			case 1:
		
				memcpy(array_of_numbers_main, random(), sizeof(array_of_numbers_main)); 
	
				FILE *default_letters = fopen("default_rand_letters.txt","w");
	
				for(pos = 0; pos < MAX_VALUE; pos++)
				{
					symbol[pos] = array_of_numbers_main[pos];
					printf("%c ", symbol[pos]);
					fprintf(default_letters,"\n%c ", symbol[pos]); 
				}
				
				fclose(default_letters);
				break;
				
			case 2:
				
				start_t = clock();
				
				qsort(array_of_numbers_main, MAX_VALUE, sizeof(int), quick());
	
				FILE *qsort_letters = fopen("sorted_letters.txt","w");
	
	  			for(pos = 0; pos < MAX_VALUE; pos++) 
				{   
					symbol[pos] = array_of_numbers_main[pos];
	   			    printf("%c ", symbol[pos]);
	   			    fprintf(qsort_letters,"\n%c ", symbol[pos]); 
	 		    }
				
				fclose(qsort_letters);
				
				end_t = clock();
				printf("\n Time: %d\n", end_t - start_t);	
				
				break;
				
			case 3:	
				
				search(array_of_numbers_main);

				break;
	
			default:
				
				printf("\n u r numbnut \n");
				
				break;
		}
		
		
		
		
	}
	while (menu != 4);

	return 0;
}
