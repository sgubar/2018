#include "func.h"

void printArrToFile(char *array, int size, char* name)
{

    FILE *file = fopen(name, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c ", array[i]);
    }
    fclose(file);

}

void readFromFileToArray(FILE *file, char *array)
{
    int i = 0;

    while(1)
    {
        char c = getc(file);
        if (c != EOF)
        {
            array[i] = c;
            i++;
        }
        else
        {
            return;
        }
    }
}

void shellSort(char *array, int aCount)
{
    int i,j,k;
    char t;
    for(k = aCount/2; k > 0; k /= 2)
    {
        for(i = k; i < aCount; i++)
        {
            t = array[i];
            for(j = i; j>=k; j-=k)
            {
                if(t < array[j-k])
                {
                    array[j] = array[j - k];
                }
                else
                {
                    break;
                }
            }
            array[j] = t;
        }
    }

}

int binarySearch(char soughtValue, char *anArray, int size)
{
    int leftIndex = 0;
    int rightIndex = size-1;

    while (leftIndex <= rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        if (soughtValue == anArray[middleIndex])
        {
            return 0;
        }
        else if (soughtValue < anArray[middleIndex])
        {
            rightIndex = middleIndex - 1;
        }
        else
        {
            leftIndex = middleIndex + 1;
        }
    }

    return 1;
}
