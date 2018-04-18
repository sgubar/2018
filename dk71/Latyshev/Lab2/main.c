#include <stdio.h>

#include "DKsort.h"



int main() 

{

    int size = 0, selection = 0;

    

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

    

    printf("Choose sorting algorithm:\n 1 - bubble\n 2 - selection sort\n 3 - inserting sort\nEnter here: ");

    three_type_sort( array, size, selection);

}
