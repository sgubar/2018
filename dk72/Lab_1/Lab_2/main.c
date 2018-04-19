#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ArrayFilling.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int size = 100;
	int array[size];
	int choise;
	int i;
	
	printf("Enter size of array: ");
    scanf("%d", &size);	
    random_filling(array, size); //Filling array by random symbols
    
    FILE *file = fopen("array.txt", "w"); // Creating file "array.txt"
    for (i = 0; i < size; i++)
    {
        fprintf(file, "%c ", array[i]); //Writing array of symbols the file
    }
    fclose(file); // Closing file
    
    printf("Choose sorting algorithm:\n 1 - bubble\n 2 - selection sort\n 3 - inserting sort\n ");
    scanf("%d", &choise);
    sorting_algoritm(array, size, choise); // Type of sorting algoritm
    
	
	getch();
	return 0;
}
