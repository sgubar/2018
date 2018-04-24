#include <stdio.h>
#include "DKsort.h"


int main() 

{

   
    int size = 0;
    int search, A;


    printf("Hello my friend \nEnter size of array please : ");

    scanf("%d", &size);

    while(size <= 0)

    {


        printf("Invalid value. Enter again: ");


        scanf("%d", &size);


    }


    int array[size];

    
    random_letter(array, size);

    Rec_To_File(array, size, "unsorted.txt");


    quick_sort(array, 0, size-1);

    Rec_To_File(array, size, "sorted.txt");
printf("Enter a large or small letter of the alphabet to search\n\nprint the result of search\n\n 1 - element has found\n 0 - element hasn't found");
   while(1)

	{

	printf("\n\nyou can try more\n");

		scanf("%s", &search);

		A = binary_search(array, size, search);	

		printf(" %d\n", A);

	}

	return 0;

}

