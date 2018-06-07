#include <stdlib.h>
#include <locale.h>
#include "dk_tool.h"


void randsymbol(int *mass, int size)
{
    srand(time(NULL));
    int isLower;
    int i;
    for( i = 0; i < size; i++)
    {

            mass[i] = rand() % 93 + 33;

    }
}

void TypeOfSorting( int *mass, int size, int selection)
{
  scanf("%d", &selection);
 while(selection != 1 && selection != 2 && selection != 3)
    {
        printf("incorrect value, choose 1 of selection ");
        scanf("%d", &selection);
    }
      switch(selection)
    {
        case 1:
            BubbleSort(mass, size);
            WriteToFile(mass, size, "SortValues.txt");
            break;
        case 2:
            SelectionSort(mass, size);
            WriteToFile(mass, size, "SortValues.txt");
            break;
        case 3:
            InsertSort(mass, size);
            WriteToFile(mass, size, "SortValues.txt");
            break;
    }
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void WriteToFile(int *mass, int size, char* name) {
    int i;
    FILE *file = fopen(name, "w");
    for ( i = 0; i < size; i++)
    {
        fprintf(file, "%c ", mass[i]);
    }
    fclose(file);
}
void SelectionSort(int *mass, int size)
{
 int i;
 int j;
    for ( i = 0; i < size; i++) {
        int trp = i;

        for ( j = i+1; j < size; j++)
        {
            if (mass[j] < mass[trp])
                trp = j;
        }
        swap(&mass[trp], &mass[i]);
    }
}

void BubbleSort(int *mass, int size)
{
    int i, j;
    for (i = 1; i <= size - 1; i++)
    {
        for (j = 0; j <= size - 2; j++) {
            if (mass[j] > mass[j + 1])
            {
                swap(&mass[j], &mass[j + 1]);
            }
        }
    }
}
void InsertSort(int *mass, int size)
{
    int i;
    for ( i = 1; i <= size - 1; i++)
    {
        int x = mass[i];

        int j = i;
        while (j > 0 && mass[j - 1] > x)
        {
            mass[j] = mass[j - 1];
            j--;
        }
        mass[j] = x;
    }
}
