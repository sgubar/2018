#include "dk_sort.h"


void shellSort(TriangleArray *anArray, int aCount)

{

    int i,j,k;
    Triangle *t;
    for(k = aCount/2; k > 0; k /= 2)
        for(i = k; i < aCount; i++)
            {
                t = anArray->Triangles[i];
                for(j = i; j>=k; j-=k)
                {
                    if(TriangleArea(t) < TriangleArea(anArray->Triangles[j-k]))
                    {
                        anArray->Triangles[j] = anArray->Triangles[j - k];
                    }
                    else
                    {
                        break;
                    }
                }
                anArray->Triangles[j] = t;
            }
}


int binarySearch(int soughtValue, TriangleArray *anArray, int size)

{
    int leftIndex = 0;
    int rightIndex = size-1;
    while (leftIndex <= rightIndex) {
        int middleIndex = ((leftIndex + rightIndex) / 2);
        if (soughtValue == TriangleArea(anArray->Triangles[middleIndex]))
        {
            return 1;
        }
        else if (soughtValue < TriangleArea(anArray->Triangles[middleIndex]))
        {
            rightIndex = middleIndex - 1;
        }
        else
        {
            leftIndex = middleIndex + 1;
        }
    }
    return 0;
}
