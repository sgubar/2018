#include "dk_ellipse4.h"
#include <stdio.h>
#include "dk_arrellipse4.h"
#include <malloc.h>



void freeArr(EllipseArr *aArr)
{
    if (NULL != aArr)
    {
        for (int i = 0; i < aArr->Count; i ++)
        {
            destroyEllipse(aArr->Ellipses[i]);
        }

        free(aArr->Ellipses);
        free(aArr);
    }
}

EllipseArr *createArr(int Val)
{
    EllipseArr *result = NULL;

    if (Val > 0)
    {
        result = (EllipseArr *)malloc(sizeof(EllipseArr));

        if (NULL != result)
        {
            result->Ellipses = (Ellipse **)malloc(sizeof(Ellipse *)*Val);

            if (NULL != result->Ellipses)
            {
                result->number = Val;
                result->Count = 0;
                result->Area = 0;
            }
            else
            {
                free(result);
                result = NULL;
            }
        }
    }

    return result;
}

int Eladder(EllipseArr *aArr, Ellipse *eEllipse)
{
    int result = -1;

    if (NULL != aArr && NULL != eEllipse &&
        aArr->Count < aArr->number)
    {
        aArr->Ellipses[aArr->Count] = createEllipse(eEllipse->A , eEllipse ->B, eEllipse ->C, eEllipse ->D,eEllipse ->Centre);
        aArr->Ellipses[aArr->Count]->Area = Ellipse_Area(eEllipse);
        result = aArr->Count;
        aArr->Count ++;
    }

    return result;
}

void Arr_writer(FILE *eFile, EllipseArr *aArr)
{
    if (NULL == aArr || NULL == eFile)
    {
        return ;
    }

    fprintf(eFile, "{\nnumber : %d,\nCount : %d,\n",aArr->number, aArr->Count);
    fprintf(eFile, "ELLIPSES : \n\n");
    int i;
    for (i = 0; i < aArr->Count; i ++)
    {
        writeEllipse(eFile, aArr->Ellipses[i]);

        if (i < aArr->Count - 1)
        {
            fprintf(eFile, "");
        }
        fprintf(eFile, "\n");
    }

    fprintf(eFile, "\n");
}
void SelectSort(EllipseArr *Sel_mass, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        int key = i;
        int j;
        for (j = i+1; j < size; j++)
        {
            Ellipse *fone = Sel_mass->Ellipses[j];
            Ellipse *sone = Sel_mass->Ellipses[key];
            if (Ellipse_Area(fone) < Ellipse_Area(sone))
                key = j;
        }
        swap(Sel_mass->Ellipses[key], Sel_mass->Ellipses[i]);
    }
}

void swap (Ellipse *Elli, Ellipse *pse)
{
   Ellipse temp = *Elli;
    *Elli = *pse;
    *pse = temp;
}
