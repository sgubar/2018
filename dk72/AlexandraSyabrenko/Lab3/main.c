#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "shellSort.h"
#include <time.h>

int main() {
    FILE *file = fopen("/Users/alexandrasyabrenko/Documents/Programming/Lab3/Lab3/test.txt", "r");
    int arrayLength = getSymbolsAmout(file);
    char *array = getFromFileToArray(file);
    
    printf("Your unsorted array: \n");
    printArray(array, arrayLength);
    shellSort(array, arrayLength);
    
    printf("Your sorted array: \n");
    printArray(array, arrayLength);
    
    printArrayToFile(array, arrayLength);
    
    linearSearch(array, 'd', arrayLength);
    
    fclose(file);
    free(array);
    return 0;
}
