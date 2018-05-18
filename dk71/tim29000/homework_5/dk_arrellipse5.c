#include "dk_ellipse5.h"
#include <stdio.h>
#include "dk_arrellipse5.h"
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

void ShellSort(EllipseArr *mass)
{
   int i, j, step;
    int *buf;
    for (step = mass->Count / 2; step > 0; step /= 2)
        {
        for (i = step; i < mass->Count; i++)
        {
            buf = mass->Ellipses[i];
            for (j = i; j >= step; j -= step)
            {
                if (Ellipse_Area(buf) < Ellipse_Area(mass->Ellipses[j - step]))
                {
			        mass->Ellipses[j] = mass->Ellipses[j - step];
                }
                else
                    {
                    break;
                    }

            mass->Ellipses[j - step] = buf;
        }
}
}
}

void LineSearch (EllipseArr *mass, float Lineup)
{
    if (NULL == mass)
    {
        return ;
    }
    else {
    for (int i = 0; i < mass -> Count; i++)
    {
        if(Lineup == mass ->Ellipses[i] -> Area)
        {
            printf("Ellipse with that area has number : %d",i);
        }
    }
  }
}
