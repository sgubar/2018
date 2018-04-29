#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Lab_3.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int size = 10000;
	int array[size];
	int search, i;
	float start = clock();
	
	printf("Your array was filled by random symbols: \n");
    //scanf("%d", &size);	
    random_filling(array, size); //Filling array by random symbols
    
    //Writing array of unsorted symbols to file
    FILE *unsorted = fopen("unsorted_array.txt", "w"); // Creating file "array.txt"
    for (i = 0; i < size; i++)
    {
        fprintf(unsorted, "%c ", array[i]); 
    }
    fclose(unsorted); // Closing file
    
    //Quick sorting
    quick_sort(array, 0, size-1); 
    printf("Time of sorting is %f/sec\n", (clock() - start)); //time of sorting
    
    //Writing array of sorted symbols to file
    FILE *sorted = fopen("sorted_array.txt", "w"); 
    for (i = 0; i < size; i++)
    {
        fprintf(sorted, "%c ", array[i]); 
    }
    fclose(sorted); 
    
    //Binary search
    printf("Enter data for search "); //entering a data for search
	scanf("%s", &search);
	
	start = clock();
	
	binary_search(array, size, search);	// data searching
	printf("%d\n", binary_search(array, size, search));//print the result of search 1 - element has found 0 - element hasn't found
	printf("Time of binary search is %f \n", (clock() - start)); //printing a time of making sorting

	getch();
	return 0;
}
