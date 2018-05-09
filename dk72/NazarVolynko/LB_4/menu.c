#include <stdio.h>
#include "spysok.h"
#include "work_with_file.h"
#include "menu.h"

void Start_of_work(CharList *Before_Range, CharList *IN_Range, CharList *After_Range)
{
    char minimum, maximum;

    printf("Before starting work with the lists, "
           "the program must fill them with the data from the file!");

    Enter_range(&minimum, &maximum);

    loadFile ("lab_4.txt", Before_Range, IN_Range, After_Range, minimum, maximum);

    printf("\nInformation from the files was saved in the lists!\n");

    printf("\nList with symbols before range:\n");
    doPrintSLList(Before_Range);

    printf("\nList with symbols in range:\n");
    doPrintSLList(IN_Range);

    printf("\nList with symbols after range:\n");
    doPrintSLList(After_Range);

    system ("PAUSE");
}

int Choose_theList()
{
    int check_for_list=0;
    printf("\nChoose a list for work with :\n");
    printf("List before Range----------------1\n");
    printf("List in Range--------------------2\n");
    printf("List after Range-----------------3\n");
    printf("Delete Lists and exit------------0\n\n");
    printf("Chosen action: ");
    scanf("%d", &check_for_list);

    return check_for_list;
}

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
    printf("Print List------------------8\n\n");
    printf("Choose number of action: ");
    scanf("%d", &check);
    printf("\n");
    return check;
}

void Work_with_list(CharList *theList, int check)
{
    switch(check)
	    {
            case 1:

            find_Node(theList);
            system ("PAUSE");

            break;

            case 2:

            add_Node(theList);
            system ("PAUSE");

            break;

            case 3:

            delete_Node(theList);
            system ("PAUSE");

            break;

            case 4:

            insert_Node(theList);
            system ("PAUSE");

            break;

            case 5:

            Swap_Place(theList);
            system ("PAUSE");

            break;

            case 6:

            size_List(theList);
            system ("PAUSE");

            break;

            case 7:

            sort_List(theList);
            system ("PAUSE");

            break;

            case 8:

            print_List(theList);
            system ("PAUSE");

            break;

	    }
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
    CharNode *theNode = SLCreateNodeWithCharValue(value);
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
    CharNode *theNode = SLCreateNodeWithCharValue(value);
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

void delete_Lists(CharList *Before_Range, CharList *IN_Range, CharList *After_Range)
{
    SLFreeList(Before_Range);
    SLFreeList(IN_Range);
    SLFreeList(After_Range);
    printf("\nLists was deleted!\n");
}

void The_End()
{
    printf("\nThank You!\n");

    printf("\n!!!!!!!! \\(^_^)/ !!!!!!!!\n");
}
