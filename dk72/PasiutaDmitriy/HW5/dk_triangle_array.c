//
// Created by dima on 17.05.18.
//

#include "dk_triangle_array.h"
#include <stdlib.h>

// init/dealloc
TriangleArray *createArray(int aNumber)
{
    TriangleArray *theResult = NULL;

    if (aNumber > 0)
    {
        theResult = (TriangleArray *)malloc(sizeof(TriangleArray));

        if (NULL != theResult)
        {
            theResult->triangles = (Triangle **)malloc(sizeof(Triangle *)*aNumber);

            if (NULL != theResult->triangles)
            {
                theResult->number = aNumber;
                theResult->count = 0;
            }
            else
            {
                free(theResult);
                theResult = NULL;
            }
        }
    }

    return theResult;
}

void freeArray(TriangleArray *anArray)
{
    if (NULL != anArray)
    {
        for (int i = 0; i < anArray->count; i ++)
        {
            destroyTriangle(anArray->triangles[i]);
        }

        free(anArray->triangles);
        free(anArray);
    }
}

//interface
//returns index of added element OR -1 if fail
int addElement(TriangleArray *anArray, Triangle *atriangle)//add massive which I wrote in end
{
    int theResult = -1;

    if (NULL != anArray && NULL != atriangle &&
        anArray->count < anArray->number)
    {
        anArray->triangles[anArray->count] =
                createTriangle(atriangle->A, atriangle->B, atriangle->C);

        theResult = anArray->count;
        anArray->count ++;
    }

    return theResult;
}

void writeArrayToJSON(FILE *aFile, TriangleArray *anArray)
{
    if (NULL == anArray || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
            anArray->number, anArray->count);
    fprintf(aFile, "\"triangles\" : \n[\n");

    for (int i = 0; i < anArray->count; i ++)//add on place which index I pointed ,if want 1 massive ,will be 1,if 5 will be 5
    {
        writeTriangleToJSON(aFile, anArray->triangles[i]);

        if (i < anArray->count - 1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }

    fprintf(aFile, "],\n}");
}

int partitionIt(TriangleArray *anArray, int aLeftIndex, int aRightIndex, float aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex;

    while (1)
    {
        // search the bigest element
        while (flatTriangle(anArray->triangles[++theLeft]) < aPivot);

        // search the lowest element
        while (theRight > 0 && flatTriangle(anArray->triangles[--theRight]) > aPivot);

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            Triangle theTmp = *anArray->triangles[theLeft];
            *anArray->triangles[theLeft] = *anArray->triangles[theRight];
            *anArray->triangles[theRight] = theTmp;
        }
    }

    //lets to swap elements
    Triangle theTmp = *anArray->triangles[theLeft];
    *anArray->triangles[theLeft] = *anArray->triangles[aRightIndex];
    *anArray->triangles[aRightIndex] = theTmp;

    return theLeft; // return break position

}


void quickSort(TriangleArray *anArray, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0) {
        return; // the array size equals to 1 - the array is fully sorted
    }

    float thePivot = flatTriangle(anArray->triangles[aRightIndex]);
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);

}

int linearSearch(TriangleArray *anArray, float value, int size)
{
    int rightIndex = size - 1;

    for(int i = 0; i < rightIndex; i++)
    {
        if(flatTriangle(anArray->triangles[i]) == value)

        {
            return 0;
        }
    }

    return 1;
}

