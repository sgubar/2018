//
// Created by vadim on 28.03.2018.
//

#include "dk_elips.h"
#include <stdio.h>
#include "dk_eclipse_array.h"
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
