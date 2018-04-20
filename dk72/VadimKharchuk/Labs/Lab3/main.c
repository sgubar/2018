#include <stdio.h>
#include "dktools.h"
int main() {
    remove("Finded.txt");

    long SIZE;
    int WhatFind;
    printf("Enter SIZE of Massiv - ");

    SIZE = ValueCheck();
    int i, a[SIZE];

    Random(a, SIZE);
    printArrToFile(a, SIZE, "UNsortedARR.txt");

    unsigned int start_time =  clock();
    quickSort(a, 0, SIZE - 1);
    printArrToFile(a, SIZE, "sortedARR.txt");
    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("Sorting time : %d ms\n", sort_time);

    printf("Write what number need a find");
    WhatFind = ValueCheck();
    Seach(a,WhatFind,SIZE);


    return 0;
}
