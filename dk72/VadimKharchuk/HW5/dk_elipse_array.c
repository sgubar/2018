#include "dk_elips.h"
#include <stdio.h>
#include "dk_elipse_array.h"
#include <malloc.h>


ElipsArray *createArray(int aNumber)
{
    ElipsArray *theResult = NULL;

    if (aNumber > 0)
    {
        theResult = (ElipsArray *)malloc(sizeof(ElipsArray));

        if (NULL != theResult)
        {
            theResult->Elipses = (Elips **)malloc(sizeof(Elips *)*aNumber);

            if (NULL != theResult->Elipses)
            {
                theResult->number = aNumber;
                theResult->count = 0;
                theResult->Arrea = 0;
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

void freeArray(ElipsArray *anArray)
{
    if (NULL != anArray)
    {
        for (int i = 0; i < anArray->count; i ++)
        {
            destroyElips(anArray->Elipses[i]);
        }

        free(anArray->Elipses);
        free(anArray);
    }
}

int addElement(ElipsArray *anArray, Elips *aElips)
{
    int theResult = -1;

    if (NULL != anArray && NULL != aElips && anArray->count < anArray->number)
    {
        anArray->Elipses[anArray->count] = createElips(aElips ->A , aElips ->B, aElips ->C, aElips ->D,aElips ->middle);
        anArray -> Elipses[anArray -> count] -> Arrea = ElipsArea(aElips);
        theResult = anArray->count;
        anArray->count ++;
    }

    return theResult;
}

void writeArrayToJSON(FILE *aFile, ElipsArray *anArray)
{
    if (NULL == anArray || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
            anArray->number, anArray->count);
    fprintf(aFile, "\"elipses\" : \n[\n");

    for (int i = 0; i < anArray->count; i ++)
    {

        writeElipsToJSON(aFile, anArray->Elipses[i]);

        if (i < anArray->count - 1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }

    fprintf(aFile, "],\n}");

}


void insertionSort(ElipsArray *anArray)
{

    Elips *ElTemp;
    for(int i = 1 ; i < anArray -> count; i++)
    {
        int j = i;
        /*   printf("\nin For Arr j : %d" ,anArray -> Elipses[j] -> A -> x);
           printf("\n in ForArr j - 1 : %d" ,anArray -> Elipses[j-1] -> A -> y);
           printf("\n in ForArr j : %f",anArray -> Elipses[j] ->Arrea);
   */
        while (anArray -> Elipses[j] ->Arrea < anArray -> Elipses[j-1] ->Arrea)
        {
            ElTemp = anArray -> Elipses[j];
            anArray -> Elipses[j] = anArray -> Elipses [j - 1];
            anArray -> Elipses[j - 1] = ElTemp;

            j--;
        }
    }
}
void shell_sort(ElipsArray *anArray)
{
    int i, j, k;
    Elips *ElTemp;
    for(i = (anArray -> count)/2; i >= 1; i /= 2)
    {
        for(j = 0; (j + i) < anArray->count; j++)
        {
            if(anArray -> Elipses[j] ->Arrea > anArray -> Elipses[j + 1] -> Arrea)
            {
                ElTemp = anArray->Elipses[j];
                anArray->Elipses[j] = anArray->Elipses[j + i];
                anArray->Elipses[j + i] = ElTemp;
            }

            for(k = j; k >= i; k-= i)
            {
                if( anArray->Elipses[k] < anArray->Elipses[k - i])
                {
                    ElTemp = anArray->Elipses[k];
                    anArray->Elipses[k] = anArray->Elipses[k - i];
                    anArray->Elipses[k - i] = ElTemp;
                }
                else
                    break;
            }
        }
    }
}

void lineSeach (ElipsArray *anArray, float WhatFind)
{
    if (NULL == anArray)
    {
        return ;
    }
    else {
    for (int i = 0; i < anArray -> count; i++)
    {
        if(WhatFind == anArray ->Elipses[i] -> Arrea)
        {
            printf("Elips with that arrea had number %d",i);
        }
    }   
  }
}
