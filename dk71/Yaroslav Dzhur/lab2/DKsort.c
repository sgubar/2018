#include <stdlib.h>
#include <locale.h>
#include "DKsort.h"


void randsymbol(int *arr, int size)
{
    srand(time(NULL));
    int isLower;
    int i;
    for( i = 0; i < size; i++)
    {

            arr[i] = rand() % 93 + 33;

    }
}

void sortingtype( int *arr, int size, int selection)
{
  scanf("%d", &selection);
 while(selection != 1 && selection != 2 && selection != 3)
    {
        printf("Некоректне значення, спробуйте ще раз: ");
        scanf("%d", &selection);
    }
      switch(selection)
    {
        case 1:
            Bubsort(arr, size);
            infile(arr, size, "Відсортовані дані.txt");
            break;
        case 2:
            Selsort(arr, size);
            infile(arr, size, "Відсортовані дані.txt");
            break;
        case 3:
            Inssort(arr, size);
            infile(arr, size, "Відсортовані дані.txt");
            break;
    }
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void infile(int *arr, int size, char* name) {
    int i;
    FILE *file = fopen(name, "w");
    for ( i = 0; i < size; i++)
    {
        fprintf(file, "%c ", arr[i]);
    }
    fclose(file);
}
void Selsort(int *arr, int size)
{
 int i;
    for ( i = 0; i < size; i++) {
        int trp = i;
         int j;
        for ( j = i+1; j < size; j++)
        {
            if (arr[j] < arr[trp])
                trp = j;
        }
        swap(&arr[trp], &arr[i]);
    }
}

void Bubsort(int *arr, int size)
{
    int i, j;
    for (i = 1; i <= size - 1; i++)
    {
        for (j = 0; j <= size - 2; j++) {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void Inssort(int *arr, int size)
{
    int i;
    for ( i = 1; i <= size - 1; i++)
    {
        int x = arr[i];

        int j = i;
        while (j > 0 && arr[j - 1] > x)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
    }
}
