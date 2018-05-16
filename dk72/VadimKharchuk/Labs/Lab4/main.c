#include <stdio.h>
#include "check.h"
#include <stdlib.h>
int main() {
    CharList *firstList = CreateCharList();
    CharList *secondList = CreateCharList();
    FILE *theFile = fopen("test.txt", "r");
    check (firstList,secondList,theFile);

    DestroyCharList(firstList);
    DestroyCharList(secondList);

    fflush(theFile);
    fclose(theFile);
    return 0;
}
