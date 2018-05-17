#include <stdio.h>
#include "list.h"

int main()
{
    int check=0,i,j,k,p;
    char value;

    CharList *theList = SLCreateList();

    loadFile ("lab_4.txt", theList);

    printf("Start!\n\n");

    printf("List in its original form:\n");
    doPrintSLList(theList);

    for(i=0; i<SLCountList(theList); i++)
    {
        if(check==2) break;
        check=0;
        value = SLNodeAtIndex(theList, i)->value;
        for(j=0; j<SLCountList(theList); j++)
        {
            if(value==SLNodeAtIndex(theList, j)->value)
            {
                check++;
            }
            if(check==2)break;
        }
    }

    p=(j-i)/2;

    for(k=0; k<p; k++)
    {
        j--;
        SLSwapNodesByIndex(theList, i, j);
        i++;
    }

    printf("\nList in its modified form:\n");

    doPrintSLList(theList);

    printf("\nThe End!!!\n");

    SLFreeList(theList);

    return 0;
}
