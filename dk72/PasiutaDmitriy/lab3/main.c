#include <stdio.h>

#include <stdio.h>
#include "dk_tool.h"

int main() {
    int size = 0;
    int searchResult = 2;

    printf("Enter size of array");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Invalid value. Enter again: ");
        scanf("%d", &size);
    }

    char array[size];
    randomSymbolFilling(array, size);
    printArrToFile(array, size, "unsorted_array.txt");

    int sort_start_time = clock();
    quickSort(array, 0, size - 1);
    int sort_end_time = clock();
    int sort_time = sort_end_time - sort_start_time;

    printf("Sorting time : %d ms", sort_time);

    printArrToFile(array, size, "sorted_array.txt");

    char soughtLetter = getchar();


    int search_start_time =  clock();
    searchResult = linearSearch(array, soughtLetter, size);
    int search_end_time = clock();
    int search_time = search_end_time - search_start_time;

    if(searchResult == 0)
    {
        printf("\nLetter in array Searching time: %d ms", search_time);
    }
    else if(searchResult == 1)
    {
        printf("\nNo letter in array. Searching time: %d ms", search_time);
    }

    getchar();
    return 0;
}
