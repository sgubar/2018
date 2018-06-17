#include <stdio.h>
#include <stdlib.h>
#include "dk_lab3.h"


int main()
{
    int size = 0;
    float ssort_t, esort_t, ssearch_t, esearch_t;

    printf("   Enter size of array : ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("   Enter again: ");
        scanf("%d", &size);
    }

    char mass[size];
    randomizer(mass, size);
    WritetoFile(mass, size, "input.txt");
    ssort_t = clock()/(float)CLOCKS_PER_SEC;
    ShellSort(mass,size);
    esort_t = clock()/(float)CLOCKS_PER_SEC;
    WritetoFile(mass, size, "Sort.txt");

    int i;
    printf("\n\n   Your sorted massive : \n");
    for(i = 0; i < size; i++)
    {
        printf(" [%c] ", mass[i]);
    }
    printf("\n\n   Time of Shell sort is [%f] sec\n\n", esort_t - ssort_t);
    printf("\n\n   Size : [%d]", size);
    printf("\n\n   Enter Symbol : ");

    getchar();
    char symbol = getchar();

    int position;
    ssearch_t = clock()/(float)CLOCKS_PER_SEC;
    position = biSearch(symbol, mass, size);
    esearch_t = clock()/(float)CLOCKS_PER_SEC;
    printf("\n\n   Time of Binary search is [%f] sec\n\n", esearch_t - ssearch_t);
    printf("\n\n   Position of [%c] is (%d)\n\n", symbol, position);

    return 0;
}
