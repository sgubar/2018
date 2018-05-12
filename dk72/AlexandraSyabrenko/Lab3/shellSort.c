#include <stdlib.h>
#include "shellSort.h"
#include <time.h>
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
void shellSort(char array[], int count)
{
    unsigned int start_time = (unsigned int) clock();
    int i = 0;
    int j = 0;
    int k = 1; // start h = 1
    
    //1. Calculate start value of h
    while (k <= count/3)
    {
        k = k*3 + 1; // 1, 4, 13, 40, 121, ....
    }
    
    //2. Sequental decrease h to 1
    while (k > 0)
    {
        for (j = k; j < count; j ++)
        {
            int temp = array[j];
            i = j;
            
            // the first sub-array {0, 4, 8}
            while (i > k-1 && array[i - k] >= temp)
            {
                array[i] = array[i - k];
                i -= k;
            }
            
            array[i] = temp;
        }
        
        k = (k - 1) / 3; //decrease h
    }
    unsigned int end_time = (unsigned int) clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time: %d ms\n", sort_time);
}

void printArray(char array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}

void printArrayToFile(char *array, int arrayLength)
{
    if (NULL != array)
    {
        FILE *file = fopen("/Users/alexandrasyabrenko/Documents/Programming/Lab3/Lab3/out.txt", "w");
        for (int i = 0; i < arrayLength; i++)
        {
            fprintf(file, "%c", array[i]);
        }
        fclose(file);
    }
}

int linearSearch(char array[], char lookedValue, int size)
{
    unsigned int start_time = (unsigned int) clock();
    for (int i = 0; i < size; i++)
    {
        if (array[i] == lookedValue)
        {
            printf("Looked value was found in %d position in array\n", i + 1);
            return i + 1;
        }
    }
    unsigned int end_time = (unsigned int) clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time: %d ms\n", sort_time);
    
    return -1;
}

