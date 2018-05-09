#include "kvAraay.h"

KvadratArray *createArray(int N)
{
    KvadratArray *arResult = NULL;

    if (N > 0)
    {
arResult = (KvadratArray *)malloc(sizeof(KvadratArray));

        if (NULL != arResult)
        {
arResult->kvadrats = (Kvadrat **)malloc(sizeof(Kvadrat *)*N);
arResult->S = malloc(sizeof(float)*N);
            if (NULL != arResult->kvadrats)
            {
                arResult->num = N;
                arResult->count = 0;
            }
            else
            {
                free(arResult);
                arResult = NULL;
            }
        }
    }

    return arResult;
}
/*-----------------------------------------------*/

void freeArray(KvadratArray *anArray)
{
    if (NULL != anArray)
    {
        for (int i = 0; i < anArray->count; i ++)
        {
            Remove_Kvadrat(anArray->kvadrats[i]);
        }

        free(anArray->kvadrats);
        free(anArray);
    }
}
/*-----------------------------------------------*/

int addElement(KvadratArray *anArray, Kvadrat *aKvadrat, float S)
{
int arResult = -1;
if (NULL != anArray && NULL != aKvadrat && anArray->count < anArray->num)
    {
anArray->kvadrats[anArray->count] = creature_Kvadrat(aKvadrat->A, aKvadrat->B, aKvadrat->C, aKvadrat->D);
anArray->S[anArray->count]=S;
/*printf("S======================%f\n", anArray->S[anArray->count]);*/
arResult = anArray->count;
anArray->count ++;
    }
    return arResult;
}
/*-----------------------------------------------*/


void writePointToJSON(FILE *aFile, Point *aPoint)
{
    if (NULL == aPoint || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}
/*-----------------------------------------------*/


void writeKvadratToJSON(FILE *aFile, Kvadrat *aKvadrat)
{
    if (NULL == aKvadrat|| NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\t\"A\" : ");
    writePointToJSON(aFile, aKvadrat->A);
    fprintf(aFile, ", \n\t\"B\" : ");
    writePointToJSON(aFile, aKvadrat->B);
    fprintf(aFile, ", \n\t\"C\" : ");
    writePointToJSON(aFile, aKvadrat->C);
    fprintf(aFile, ", \n\t\"D\" : ");
    writePointToJSON(aFile, aKvadrat->D);
    fprintf(aFile, ", \n\t\"Area\" : %f,", S_Kvadrat(aKvadrat));
    fprintf(aFile, "\n}");
}
/*-----------------------------------------------*/


void writeArrayToJSON(FILE *aFile, KvadratArray *anArray)
{
    if (NULL == anArray || NULL == aFile)
    {
        return ;
    }

fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n", anArray->num, anArray->count);
fprintf(aFile, "\"kvadrats\" : \n[\n");

    for (int i = 0; i < anArray->count; i ++)
    {
        writeKvadratToJSON(aFile, anArray->kvadrats[i]);

        if (i < anArray->count - 1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }

    fprintf(aFile, "],\n}");
}
