#include <stdio.h>
#include "tree.h"

int main()
{
    char value;
    CharTree *aTree = create_CharTree();

    printf("Start!!!\n");

    insert_CharNodeToTree(aTree, 'A');
    insert_CharNodeToTree(aTree, 'B');
    insert_CharNodeToTree(aTree, 'C');
    insert_CharNodeToTree(aTree, 'D');
    insert_CharNodeToTree(aTree, 'F');
    insert_CharNodeToTree(aTree, 'G');
    insert_CharNodeToTree(aTree, 'H');

    printf("\nTree:\n");
    print_Tree(aTree);

    printf("\n\nEnter VALUE for insert: ");
    value = getche();
    insert_CharNodeToTree(aTree, value);

    printf("\nNumber of elements(size of Tree): %d\n", count_NodesInTree(aTree));

    printf("\nTree:\n");
    print_Tree(aTree);

    printf("\n\nEnter the value of Node to find: ");
    value = getche();
    find_NodeWithCharValue(aTree, value);


     do
    {
        printf("\n\nEnter the value of Node for deleting: ");
        value = getche();
        if(value == aTree -> root->value)
        {
            printf("\nError ! Enter again! (root=value)!\n");
        }
    }while(value == aTree -> root->value);

    delete_NodeWithCharValue(aTree, aTree -> root, value);

    printf("\nTree:\n");
    print_Tree(aTree);

    destroy_CharTree(aTree);

    printf("\n\nThe End!\n");

    return 0;
}
