#include <stdio.h>
#include "sorting.h"
#include <stdlib.h>
int main()
{
    FILE *file = fopen("/Users/alexandrasyabrenko/Documents/Programming/Lab2/Lab2/test.txt", "r");
    int arrayLength = getSymbolsAmout(file);
    char *array = getFromFileToArray(file);

    printf("Unsorted array: \n");
printArrayToScreen(array, arrayLength);
    printf("Choose sorting algorithm:\n 1 - bubble\n 2 - selection sort\n 3 - inserting sort\nEnter here: ");
    
    int numberOfAlgorithm = 0;
    scanf("%d", &numberOfAlgorithm);
    while(numberOfAlgorithm != 1 && numberOfAlgorithm != 2 && numberOfAlgorithm != 3)
    {
        printf("Incorrect value. Enter again: ");
        scanf("%d", &numberOfAlgorithm);
    }
    
    switch(numberOfAlgorithm)
    {
        case 1:
            bubbleSort(array, arrayLength);
            printArrayToFile(array, arrayLength);
            break;
        case 2:
            selectionSort(array, arrayLength);
            printArrayToFile(array, arrayLength);
            break;
        case 3:
            insertionSort(array, arrayLength);
             printArrayToFile(array, arrayLength);
            break;
    }
    printf("Sorted array: \n");
    printArrayToScreen(array, arrayLength);

    fclose(file);
    free(array);
    return 0;
}
