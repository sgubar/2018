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


    printf("Enter 1 for selection sort, 2 for insertion sort, 3 for bubble sort\n");
    int select = 0;
    scanf("%d", &select);
    while(select != 1 && select != 2 && select != 3)
    {
        printf("Incorrect choice. Try again");
        scanf("%d", &select);
    }

    int start_time;
    int end_time;
    int sort_time;

    switch (select)
    {
        case 1:
            start_time =  clock();

            selectionSort(test, size);

            end_time = clock();
            sort_time = end_time - start_time;
            printf("Sorting time : %d ms", sort_time);
            break;
        case 2:
            start_time =  clock();

            insertionSort(test, size);

            end_time = clock();
            sort_time = end_time - start_time;
            printf("Sorting time : %d ms", sort_time);
            break;

        case 3:
            start_time =  clock();

            bubbleSort(test, size);

            end_time = clock();
            sort_time = end_time - start_time;
            printf("Sorting time : %d ms", sort_time);
            break;
    }

    printArrToFile(test, sizeof(test), "output.txt");
    return 0;
}
