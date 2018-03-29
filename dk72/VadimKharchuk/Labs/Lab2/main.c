#include <stdio.h>
#include "tools.h"
#include <time.h>

int main()
{
    int SIZE;
    int Choose;
    printf("Program working only with INTEGER format"
                   "Enter SIZE of Massiv - ");
    scanf("%d",&SIZE);

    int i,a[SIZE];
    Random(a, SIZE);
    printArrToFile(a, SIZE, "unsortedARR.txt");

    printf("Plz choose you variant for Sort\n"
                   "Write '1' For Bubble sort.\n"
                   "Write '2' For Insertion sort.\n"
                   "Write '3' For Selection sort. \n"
                   "Write there :  ");
    scanf("%d",&Choose);
    while(Choose != 1 && Choose !=2 && Choose !=3)
    {
        printf("Enter value again!\n");
        scanf("%d",&Choose);
    }

    switch(Choose)
    {
        case 1:
            printf("You choose bubble sort\n");
            bubbleSort(a, SIZE);
            break;
        case 2:
            printf("You choose Insertion sort\n");
            insertionSort(a, SIZE);
            break;
        case 3:
            printf("You choose Selection sort\n");
            selectionSort(a, SIZE);
            break;

    }
    printArrToFile(a, SIZE, "sortedARR.txt");
    return 0;
}