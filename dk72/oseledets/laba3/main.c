#include <stdio.h>
#include <time.h>
#include "func.h"

int main() {
    FILE *file = fopen("test.txt", "r");
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char test[size];
    readFromFileToArray(file, test);


    printf("Enter symbol for search\n");
    char search;
    scanf("%c", &search);


    int start_time;
    int end_time;
    int sort_time;



    start_time =  clock();

    shellSort(test, size);

    end_time = clock();
    sort_time = end_time - start_time;
    printf("Sorting time : %d ms\n", sort_time);

    start_time =  clock();

    int res = binarySearch(search ,test, size);

    end_time = clock();
    sort_time = end_time - start_time;
    printf("Searching time : %d ms\n", sort_time);

    if(!res)
    {
        printf("Symbol is in array\n");
    } else {
        printf("This symbol is not in array\n");
    }



    printArrToFile(test, sizeof(test), "output.txt");
    return 0;
}
