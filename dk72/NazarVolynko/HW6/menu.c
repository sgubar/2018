#include <stdio.h>
#include "spysok.h"
#include "menu.h"

int choose_check()
{
    int check;

    printf("\nAction list:\n");
    printf("Find Node-------------------1\n");
    printf("Add Node--------------------2\n");
    printf("Delete Node-----------------3\n");
    printf("Insert Node-----------------4\n");
    printf("Swap place Nodes------------5\n");
    printf("Identify size of List-------6\n");
    printf("Sort List-------------------7\n");
    printf("Print List------------------8\n");
    printf("Delete List and exit--------9\n\n");
    printf("Choose number of action: ");
    scanf("%d", &check);
    printf("\n");
    return check;
}

void find_Node(CharList *alist)
{
    int index;
    printf("Choose the INDEX of Node: ");
    scanf("%d", &index);
    printf("Needed Node:\n");
    printf("node[%d].value = %c\n", index, SLNodeAtIndex(alist, index)->value);
}

void add_Node(CharList *alist)
{
    char value;
    printf("Enter VALUE Node: ");
    scanf("%s", &value);
    CharNode *theNode = SLCreateNodeWithIntValue(value);
    SLAddNode(alist, theNode);
    printf("\nNode was added!\n");
}

void delete_Node(CharList *alist)
{
    int index;
    printf("Enter INDEX for deleting: ");
    scanf("%d", &index);
    SLRemovedNodeAtIndex(alist, index);
    printf("\nNode was deleted!\n");
}

void insert_Node(CharList *alist)
{
    int index=0;
    char value;
    printf("Enter VALUE for insert: ");
    scanf("%s", &value);
    printf("Enter INDEX for insert: ");
    scanf("%d", &index);
    printf("\n%d\n", index);
    CharNode *theNode = SLCreateNodeWithIntValue(value);
    SLInsertNodeAtIndex(alist, theNode, index);
    printf("\nNode was inserted!\n");
}

void Swap_Place(CharList *alist)
{
    int index1, index2;
    printf("Enter INDEX #1 for swapping: ");
    scanf("%d", &index1);
    printf("Enter INDEX #2 for swapping: ");
    scanf("%d", &index2);
    SLSwapNodesByIndex(alist, index1, index2);
    printf("\nNode was swapped!\n");
}

void size_List(CharList *alist)
{
    printf("number of elements(size of List): %d\n", SLCountList(alist));
}

void sort_List(CharList *alist)
{
    quickSort(alist, 0, alist->count-1);
    printf("\nList was sorted!\n");
}

void print_List(CharList *alist)
{
    doPrintSLList(alist);
    printf("\nList was printed!\n");
}

void delete_List(CharList *alist)
{
    SLFreeList(alist);
    printf("\nList was deleted!\n");
}

void The_End()
{
    printf("\nThank You!\n");

    printf("\n!!!!!!!! \\(^_^)/ !!!!!!!!\n");
}
