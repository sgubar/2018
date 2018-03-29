//
// Created by Ihor on 28.03.2018.
//


#include <stdlib.h>
#include "tools.h"

void swap (int *element1Ptr, int *element2Ptr)
{
    int temp = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = temp;
}

void selectionSort(int *array, int size)
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

void bubbleSort(int *array, int size)
{
    unsigned int start_time =  clock();

    int pass, cur;

    for (pass = 1; pass <= size - 1; pass++)
    {
        for (cur = 0; cur <= size - 2; cur++) {
            if (array[cur] > array[cur + 1])
            {
                swap(&array[cur], &array[cur + 1]);
            }
        }
    }

    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time : %d ms", sort_time);
}

void insertionSort(int *array, int size)
{
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

void printArrToFile(int *array, int size, char* name) {

    FILE *file = fopen(name, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c ", array[i]);
    }
    fclose(file);

}

void randomSymbolFilling(int *array, int size)
{
    srand(time(NULL));
    int isLower;
    for(int i = 0; i < size; i++)
    {
        isLower = rand() % 2;
        if(isLower == 1)
        {
            array[i] = rand() % 25 + 65;
        }
        else
        {
            array[i] = rand() % 25 + 97;
        }
    }

}
