//
// Created by Ihor on 15.05.2018.
//

#include "dk_sort.h"

void selectionSort(RectangleArray *array, int size)
{
    for (int i = 0; i < size; i++) {
        int lover = i;
        for (int j = i+1; j < size; j++)
        {
            Rectangle *firstOne = array->rectangles[j];
            Rectangle *secondOne = array->rectangles[lover];
            if (rectangleArea(firstOne) < rectangleArea(secondOne))
                lover = j;
        }
        swap(array->rectangles[lover], array->rectangles[i]);
    }
}

void swap (Rectangle *element1Ptr, Rectangle *element2Ptr)
{
    Rectangle temp = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = temp;
}

void shellSort(RectangleArray *anArray, int aCount)
{
    int i,j,k;
    Rectangle *t;
    for(k = aCount/2; k > 0; k /= 2)
        for(i = k; i < aCount; i++)
            {
                t = anArray->rectangles[i];
                for(j = i; j>=k; j-=k)
                {
                    if(rectangleArea(t) < rectangleArea(anArray->rectangles[j-k]))
                    {
                        anArray->rectangles[j] = anArray->rectangles[j - k];
                    }
                    else
                    {
                        break;
                    }
                }
                anArray->rectangles[j] = t;
            }

}

int binarySearch(int soughtValue, RectangleArray *anArray, int size)
{
    int leftIndex = 0;
    int rightIndex = size-1;

    while (leftIndex <= rightIndex) {
        int middleIndex = ((leftIndex + rightIndex) / 2);

        if (soughtValue == rectangleArea(anArray->rectangles[middleIndex]))
        {
            return 0;
        }
        else if (soughtValue < rectangleArea(anArray->rectangles[middleIndex]))
        {
            rightIndex = middleIndex - 1;
        }
        else
        {
            leftIndex = middleIndex + 1;
        }
    }

    return 1;
}
