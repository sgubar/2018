//
// Created by vadim on 17.05.2018.
//

#include "sort.h"
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

void lineSeach (ElipsArray *anArray, float WhatFind) {
    if (NULL == anArray) {
        return;
    } else {
        for (int i = 0; i < anArray->count; i++) {
            if (WhatFind == anArray->Elipses[i]->Arrea) {
                printf("Elips with that arrea had number %d", i);
            }
            else
                printf("No match");
        }
    }
}
