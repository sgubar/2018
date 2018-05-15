#include <stdio.h>
#include "check.h"
#include <stdlib.h>
int main() {
    IntList *firstList = CreateIntList();
    IntList *secondList = CreateIntList();
    FILE *theFile = fopen("test.txt", "r");
    check (firstList,secondList,theFile);


    fflush(theFile);
    fclose(theFile);
    return 0;
}
