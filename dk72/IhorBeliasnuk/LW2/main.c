#include <stdio.h>
#include "tools.h"

int main()
{
    int size = 0, selector = 0;
    
    printf("Hello. Enter size of array: ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Invalid value. Enter again: ");
        scanf("%d", &size);
    }

    int array[size];
    randomSymbolFilling(array, size);
    printArrToFile(array, size, "unsorted_array.txt");
    
    printf("Choose sorting algorithm:\n 1 - bubble\n 2 - selection sort\n 3 - inserting sort\nEnter here: ");
    scanf("%d", &selector);
    while(selector != 1 && selector != 2 && selector != 3)
    {
        printf("Invalid value. Enter again: ");
        scanf("%d", &selector);
    }
    
    switch(selector)
    {
        case 1:
            bubbleSort(array, size);
            printArrToFile(array, size, "sorted_array.txt");
            break;
        case 2:
            selectionSort(array, size);
            printArrToFile(array, size, "sorted_array.txt");
            break;
        case 3:
            insertionSort(array, size);
            printArrToFile(array, size, "sorted_array.txt");
            break;

    }

}
