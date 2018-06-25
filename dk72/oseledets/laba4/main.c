#include <stdio.h>
#include "list.h"
#include "quickSort.h"
int main() {
    int LeftPoz;
    IntList *theList = CreateIntList();
    if(theList == NULL)
    {
        return -1;
    }
    AddIntValueToList(theList, 384);
    AddIntValueToList(theList, 324);
    AddIntValueToList(theList, 374);
    AddIntValueToList(theList, 334);
    AddIntValueToList(theList, 342);
    AddIntValueToList(theList, 55);
    PrintList (theList);

    int someValue = 31,anIndex =2;
    InsertIntValueAtIndex(theList,someValue,anIndex);
    PrintList (theList);


    LeftPoz = FindMin(theList);
    printf("\nLeftPoz - %d",LeftPoz);
    quickSort(theList, LeftPoz, theList->count - 1);
    printf ("\nSorted\n");
    PrintList (theList);

    DestroyIntList(theList);
    return 0;
}
