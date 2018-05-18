#include <stdio.h>
#include "dk_sort.h"

int main()
{
float TimeStart,TimeStop;
int size=0, number;
char letter;
char *Quick_sort = loadFile("lab_3.txt" , &size);

printf("Sort!!!\n");

TimeStart = clock()/(float)CLOCKS_PER_SEC;
quickSort(Quick_sort, 0, size-1);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nQuick Sort: %f \n", TimeStop-TimeStart);

printf("\nSorting is complete\n");

printf("\nEnter the letter to search: ");
scanf("%c",&letter);

TimeStart = clock()/(float)CLOCKS_PER_SEC;
number = binarysearch(letter, Quick_sort, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

if(number==-1)
{
    printf("\nThe array does not contain the required letter!\n");
}
else
{
    printf("\nThe required letter in the array is under number: %d \n", number);
}

printf("\nBinary search: %f secund!\n", TimeStop-TimeStart);

record_to_file(Quick_sort, size, "Quick_Sort.txt");

printf("\nView the created files!!!:)\n");

free(Quick_sort);

return 0;
}
