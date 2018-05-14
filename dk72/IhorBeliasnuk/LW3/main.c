#include <stdio.h>
#include "tools.h"

int main()
{
    int size = 0;
    int searchResult = 2;

    printf("Hello. Enter size of array and letter without space: ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Invalid value. Enter again: ");
        scanf("%d", &size);
    }

    char array[size];
    randomSymbolFilling(array, size);
    printArrToFile(array, size, "unsorted_array.txt");

    unsigned int sort_start_time = clock();
    quickSort(array, 0, size - 1);
    unsigned int sort_end_time = clock();
    unsigned int sort_time = sort_end_time - sort_start_time;

    printf("Sorting time : %d ms", sort_time);

    printArrToFile(array, size, "sorted_array.txt");

    char soughtLetter = getchar();


    unsigned int search_start_time =  clock();
    searchResult = binarySearch(soughtLetter, array, size);
    unsigned int search_end_time = clock();
    unsigned int search_time = search_end_time - search_start_time;

    if(searchResult == 0)
    {
        printf("\nThis letter is in this array! Searching time: %d ms", search_time);
    }
    else if(searchResult == 1)
    {
        printf("\nThere is no such letter in this array. Searching time: %d ms", search_time);
    }
    else
    {
        printf("\nsomething goes wrong...");
    }

    getchar();
    return 0;

}
