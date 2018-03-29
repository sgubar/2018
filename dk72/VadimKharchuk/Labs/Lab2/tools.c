#include <stdlib.h>
#include "tools.h"
#include <time.h>

void swap (int *element1Ptr, int *element2Ptr)
{
    int temp = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = temp;
}

void selectionSort(int array[], long size)
{
    unsigned int start_time =  clock();
    for (int i = 0; i < size; i++) {
        int lover = i;
        for (int j = i+1; j < size; j++)
        {
            if (array[j] < array[lover])
                lover = j;
        }
        swap(&array[lover], &array[i]);
    }
    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time : %d ms", sort_time);
}

void bubbleSort(int *array, long size) {
    int pass, j;
    unsigned int start_time =  clock();
    for (pass = 1; pass <= size - 1; pass++) {
        for (j = 0; j <= size - 2; j++) {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time : %d ms", sort_time);
}

void insertionSort(int array[], long size)
{
    double diff_t;
    unsigned int start_time =  clock();
    for (int i = 1; i <= size - 1; i++)
    {
        int x = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > x)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = x;
    }
    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time : %d ms", sort_time);
}

void printArrToFile(int array[], long size, char* name) {
    FILE *file = fopen(name, "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
        if (i % 50 == 0 && i != 0) {
            fprintf(file, "\n");
        }
    }
}

void Random(int *array, long size) {
    register int i;
    srand(time(NULL));
    for(i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
    }
}

long ValueCheck() {

    long value;
    while (  scanf("%ld",&value) == 0 )
    {
        printf("\tAre you sure used correct values? Check it, and try aggain: ");
        while(getchar()!='\n');
    }
    return value;
}
