#include "dk_tool.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void Random(int *array, long size) {
	setlocale(LC_ALL, "RUS");
    register int i;
    for(i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
    }

}

long ValueCheck() {

    long value;
    while (  scanf("%ld",&value) == 0 )
    {
        printf("\tВы уверены что ввели правильные значения? Проверьте их: ");
        while(getchar()!='\n');
    }
    return value;
}

void quickSort(int arr[], int left, int right) {

    int i = left, j = right;
    int tmp;
    int center = arr[(left + right) / 2];
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
    unsigned int start_time =  clock();
    FILE *file = fopen("Finded.txt", "a+");
    fprintf(file, "Вы искали %d, Это число имеет адрес:\n ",WhatFind);
    for(int i = 0; i < SIZE; i++)
    {
        if(array[i] == WhatFind)
        {
            fprintf(file, " Массив[%d]\n",i);
        }

    }
    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("Время сортировки : %d ms\n", sort_time);
    fclose(file);
}
