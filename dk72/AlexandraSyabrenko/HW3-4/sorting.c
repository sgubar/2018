#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "functions2.h"

void sort(ArrayCircles *anArray)
{
    for (int i = 0; i < anArray->number - 1; i++)
    {
        for (int j = 0; j < anArray->number - i - 1; j++)
        {
            if (anArray->circles[j]->radius > anArray->circles[j + 1]->radius)
            {
                swap(anArray, j, j + 1);
            }
        }
    }
}

void swap(ArrayCircles *anArray, int a, int b)
{
    Circle* temp = NULL;
    temp = copyCircleWithCircle(anArray->circles[a]);
    anArray->circles[a] = copyCircleWithCircle(anArray->circles[b]);
    anArray->circles[b] = copyCircleWithCircle(temp);
}
