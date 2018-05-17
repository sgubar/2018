#include <stdio.h>
#include "dk_tool.h"
#include <stdlib.h>
int main()
{
    float TimeStart,TimeStop;
    int size=0;
    char *buble = loadFile("laba2.txt" , &size);

    printf("Sort!!!\n");

    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    buble_sort(buble, size);
    TimeStop = clock()/(float)CLOCKS_PER_SEC;

    printf("\nBuble Sort: %f \n", TimeStop-TimeStart);

    char * insert = loadFile("laba2.txt" , &size);

    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    insert_sort(insert, size);
    TimeStop = clock()/(float)CLOCKS_PER_SEC;

    printf("\nInsert Sort: %f \n", TimeStop-TimeStart);

    char * selection = loadFile("laba2.txt" , &size);

    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    selection_sort(selection, size);
    TimeStop = clock()/(float)CLOCKS_PER_SEC;

    printf("\nSelection Sort: %f \n", TimeStop-TimeStart);

    record_to_file(buble, size, "buble.txt");
    record_to_file(insert, size, "insert.txt");
    record_to_file(selection, size, "selection.txt");
    printf("\nView the created files!!!:)\n");

    free(buble);
    free(insert);
    free(selection);

    return 0;
}
