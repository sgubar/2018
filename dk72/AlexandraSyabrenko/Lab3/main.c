#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "shellSort.h"

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
    
    unsigned int start_time = (unsigned int) clock();
    linearSearch(array, 'd', arrayLength);
    unsigned int end_time = (unsigned int) clock();
    unsigned int sort_time = end_time - start_time;
    
    printf("Sorting time: %d ms\n", sort_time);
    
    fclose(file);
    free(array);
    return 0;
}
