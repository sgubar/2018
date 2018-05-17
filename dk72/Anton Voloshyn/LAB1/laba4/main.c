#include <stdio.h>
#include "dk_tool.h"

int main()
{
    CharList *theList = SLCreateList();

    loadFile ("lab_4.txt", theList);

    printf("Start!\n");

    printf("\nList in direct order:\n");
    doPrintSLList(theList);
    printf("\nList in the reverse order:\n");
    doPrintSLList_Conversely(theList);
    printf("\nList in direct order:\n");
    doPrintSLList(theList);
    printf("\nList in the reverse order:\n");
    doPrintSLList_Conversely(theList);

    printf("\nThe End!!!\n");

    SLFreeList(theList);

    return 0;
}
