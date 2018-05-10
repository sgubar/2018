#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>

int getSymbolsAmout(FILE *file)
{
    int size = 0;
    if (file == NULL) return -1;
    
    fseek (file, 0, SEEK_END);
    size = (int) ftell(file);
    fseek (file, 0, SEEK_SET);
    return size;
}

char *getFromFileToArray(FILE *file)
{
    if (NULL == file)
    {
        printf("File does not exist");
        return NULL;
    }
    
    int arrayLength = getSymbolsAmout(file);
    
    char *array = NULL;
    array = (char*) malloc(sizeof(char) * arrayLength);
    
    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &array[i]);
        i++;
    }
    
    return array;
}

void printArrayToScreen(char *array, int arrayLength)
{
    if (NULL != array)
    {
        for (int i = 0; i < arrayLength; i++)
        {
            printf("%c ", array[i]);
        }
    }
    printf("\n");
}

void bubbleSort(char *array, int arrayLength)
{
    unsigned int start_time = (unsigned int) clock();
    for (int i = 0; i < arrayLength - 1; i++)
    {
        for (int j = 0; j < arrayLength - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                char temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    unsigned int end_time = (unsigned int) clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time: %d ms\n", sort_time);
}

void selectionSort(char *array,int arrayLength)
{
    unsigned int start_time = (unsigned int) clock();
    int x;
    for (int i = 0; i < arrayLength - 1; i++)
    {
        int k = i;
        x = array[i];
        
        for (int j = i + 1; j < arrayLength; j++)
        {
            if (array[j] < x)
            {
                k = j;
                x = array[k];
            }
        }
        array[k] = array[i];
        array[i] = x;
    }
    unsigned int end_time = (unsigned int) clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time: %d ms\n", sort_time);
}


void insertionSort(char *array,int arrayLength)
{
    int newElement, location;
    unsigned int start_time =  (unsigned int) clock();
    for (int i = 1; i < arrayLength; i++)
    {
        newElement = array[i];
        location = i - 1;
        while(location >= 0 && array[location] > newElement)
        {
            array[location+1] = array[location];
            location = location - 1;
        }
        array[location+1] = newElement;
    }
    unsigned int end_time = (unsigned int) clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time: %d ms\n", sort_time);
}

void printArrayToFile(char *array, int arrayLength)
{
    if (NULL != array)
    {
        FILE *file = fopen("/Users/alexandrasyabrenko/Documents/Programming/Lab2/Lab2/out.txt", "w");
        for (int i = 0; i < arrayLength; i++)
        {
            fprintf(file, "%c", array[i]);
        }
        fclose(file);
    }
}
