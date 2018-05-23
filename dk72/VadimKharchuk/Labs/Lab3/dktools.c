//
// Created by vadim on 20.04.2018.

#include "dktools.h"
#include <stdlib.h>
#include <time.h>
void Random(int *array, long size) {
    register int i;
  // srand(time(NULL));
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

void quickSort(int arr[], int left, int right) {

    int i = left, j = right;
    int tmp;
    int center = arr[(left + right) / 2];
    /* partition */
    while (i <= j) {
        while (arr[i] < center)
            i++;
        while (arr[j] > center)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
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

void Seach(int array[], int WhatFind, long SIZE)
{
    FILE *file = fopen("Finded.txt", "a+");
    fprintf(file, "You Seach %d, This number had address:\n ",WhatFind);
    for(int i = 0; i < SIZE; i++)
    {
        if(array[i] == WhatFind)
        {
            fprintf(file, " array[%d]\n",i);
        }

    }
    fclose(file);
}
