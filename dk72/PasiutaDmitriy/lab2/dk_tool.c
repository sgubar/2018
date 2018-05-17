//
// Created by dima on 17.05.18.
//

#include "dk_tool.h"
#include"dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create(char*path)
{
    FILE *f=fopen("f.txt", "w" );
    if(f!=NULL)
    {
        printf( "the file was created\n" );
        fprintf(f,"hello my friend");
    }
    fclose(f);
}

int amOfCInF(int sizeOfArr)
{
    FILE *f=fopen("f.txt", "r");
    if (f != NULL)
    {
        fseek (f, 0, SEEK_END);
        sizeOfArr = ftell (f);


        fseek (f, 1, SEEK_END);
        fprintf(f,"\0");


        fseek (f, 0, SEEK_SET);
    }
    return sizeOfArr;
}
void bubleSort(char* arr,int sizeOfArr)
{
    for(int k = 0; k < sizeOfArr - 1; k++)
    {
        int swaps = 0;
        for(int i = 0; i < sizeOfArr - 1 - k; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                swaps++;
            }
        }
        if(!swaps)
            break;
    }

}
void selectionSort(char*anArray, int aSize)
{
    for (int theOut = 0; theOut < aSize - 1; theOut ++)
    {
        int theMinIndex = theOut;

        for (int theIn = theOut + 1; theIn < aSize; theIn ++)
        {
            if (anArray[theIn] < anArray[theMinIndex])
            {
                theMinIndex = theIn;
            }
        }

        int theTmp = anArray[theOut];
        anArray[theOut] = anArray[theMinIndex];
        anArray[theMinIndex] = theTmp;
    }
}
void insertionSort(char*anArray, int aSize)
{
    for (int theOut = 1; theOut < aSize; theOut ++)
    {
        int theTmp = anArray[theOut];
        int theIn = theOut;

        while (theIn > 0 && anArray[theIn - 1] >= theTmp)
        {
            anArray[theIn] = anArray[theIn - 1];
            theIn;
        }

        anArray[theIn] = theTmp;
    }
}
