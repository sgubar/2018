//
// Created by dima on 18.05.18.
//

#include "dk_tool.h"


void randomSymbolFilling(char *array, int size)
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

void printArrToFile(char *array, int size, char* name)
{

    FILE *file = fopen(name, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c ", array[i]);
    }
    fclose(file);

}

int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex;

    while (1)
    {
        // search the bigest element
        while (anArray[++theLeft] < aPivot);

        // search the lowest element
        while (theRight > 0 && anArray[--theRight] > aPivot);

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            int theTmp = anArray[theLeft];
            anArray[theLeft] = anArray[theRight];
            anArray[theRight] = theTmp;
        }
    }

    //lets to swap elements
    int theTmp = anArray[theLeft];
    anArray[theLeft] = anArray[aRightIndex];
    anArray[aRightIndex] = theTmp;

    return theLeft; // return break position
}

void quickSort(char *anArray, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; // the array size equals to 1 - the array is fully sorted
    }

    int thePivot = anArray[aRightIndex];
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

int linearSearch(char anArray[], char aSymbol, int size)
{
    int rightIndex = size - 1;
    for(int i = 0; i < rightIndex; i++)
    {
        if(anArray[i] == aSymbol)
        {
            return 0;
        }
    }

    return 1;
}
