#include <stdio.h>
#include "tool.h"

int main(void)
{
    CharList *theList=CreateCharList();
    if (NULL==theList)
    {
        return -1;
    }
    addCharElementToList(theList, 'g');
    addCharElementToList(theList, 'E');
    addCharElementToList(theList, 'm');
    addCharElementToList(theList, 'v');
    addCharElementToList(theList, '2');
    addCharElementToList(theList, 'L');
    addCharElementToList(theList, '7');
    addCharElementToList(theList, 'F');
    addCharElementToList(theList, 'a');
    printf("\nList size: %d\n", theList->count);
    PrintList(theList);
    
    int index;
    char vstavka;
    
    printf("\nEnter element value in char type - ");
    scanf("%c", &vstavka);
    printf("\nEnter index value - ");
    scanf("%d", &index);
    
    InsertCharElementAtIndex(theList, vstavka, index);
    printf("\nInserting enement %c wirh index %i\n",vstavka,index);
    PrintList(theList);
    
    printf("\nqSort\n");
    quickSort(theList, 0, theList->count-1);
    PrintList(theList);
    
    
    printf("\nDeleting element with index %i\n",index);
    DeleteCharElementAtIndex(theList, index);
    PrintList(theList);
    
    DestroyCharList(theList);
    printf("\nList deleted\n");
}
