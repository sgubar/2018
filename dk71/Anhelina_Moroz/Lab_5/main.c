#include <stdio.h>
#include "tree.h"

int main()
{
    double value;

    DoubleTree *aTree = create_DoubleTree();

    printf("Start!!!\n");

    insert_DoubleNodeToTree(aTree, 11.23);
    insert_DoubleNodeToTree(aTree, 19.42);
    insert_DoubleNodeToTree(aTree, 17.05);
    insert_DoubleNodeToTree(aTree, 25.57);
    insert_DoubleNodeToTree(aTree, 81.71);
    insert_DoubleNodeToTree(aTree, 99.99);
    insert_DoubleNodeToTree(aTree, 67.12);

    printf("\nTree:\n");
    print_Tree(aTree);

    printf("\n\nEnter VALUE for insert: ");
    scanf("%lf", &value);
    insert_DoubleNodeToTree(aTree, value);

    printf("\nNumber of elements(size of Tree): %d\n", count_NodesInTree(aTree));

    printf("\nTree:\n");
    print_Tree(aTree);

    printf("\n\nEnter the value of Node to find: ");
    scanf("%lf", &value);
    find_NodeWithDoubleValue(aTree, value);


     do
    {
        printf("\n\nEnter the value of Node for deleting: ");
        scanf("%lf", &value);
        if(value == aTree -> root->value)
        {
            printf("\nError ! Enter again! (root=value)!\n");
        }
    }while(value == aTree -> root->value);

    delete_NodeWithDoubleValue(aTree, aTree -> root, value);

    printf("\nTree:\n");
    print_Tree(aTree);

    destroy_DoubleTree(aTree);

    printf("\n\nThe End!\n");

    return 0;
}
