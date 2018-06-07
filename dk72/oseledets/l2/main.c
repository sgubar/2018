#include <stdio.h>
#include <locale.h>
#include "dk_tool.h"

int main()
{
    int size = 0, selection = 0;

    printf("Put size massive ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("invalid value, put new valid size ");
        scanf("%d", &size);
    }
    int mass[size];

    randsymbol(mass, size);

    WriteToFile(mass, size, "NotSortingValues.txt");

    printf("Chosse your way sorting: \n 1 - Bubble sort \n 2 - selection sort \n 3 - insert sort");

    TypeOfSorting(mass, size, selection);
}
