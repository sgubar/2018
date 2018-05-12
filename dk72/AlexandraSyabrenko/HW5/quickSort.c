#include "quickSort.h"
#include "functions2.h"
#include "functions.h"

static void swap(ArrayCircles *anArray, int a, int b);

int partitionIt(ArrayCircles *array, int leftIndex, int rightIndex, int pivot) //розділення
{
    int left = leftIndex;
    int right = rightIndex;

    while (left < right)
    {
        while (array->circles[left]->radius < pivot)
            left++;

        while (right > 0 && array->circles[right]->radius > pivot)
            right--;

        if (left < right)
        {
            swap(array, left, right);

            left++;
            right--;
        }
    }
    return left;
}

void quickSort(ArrayCircles *array, int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int pivot = array->circles[rightIndex]->radius;
        int partition =  partitionIt(array, leftIndex, rightIndex, pivot);

        quickSort(array, leftIndex, partition - 1);
        quickSort(array, partition, rightIndex);
    }
}

void swap(ArrayCircles *array, int a, int b)
{
    Circle* temp = NULL;
    temp = copyCircleWithCircle(array->circles[a]);
    array->circles[a] = copyCircleWithCircle(array->circles[b]);
    array->circles[b] = copyCircleWithCircle(temp);
}


int linearSearch(ArrayCircles *array, int radius)
{
    for (int i = 0; i < array->count; i++)
    {
        if (array->circles[i]->radius == radius)
            return i + 1;
    }
    return -1;
}
