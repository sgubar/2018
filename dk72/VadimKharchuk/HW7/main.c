#include <stdio.h>
#include "Binare_tree.h"
int main() 
{
    IntTree *theTree = createIntTree();
    insertIntValueToTree(theTree,40);
    insertIntValueToTree(theTree,23);
    insertIntValueToTree(theTree,44);
    insertIntValueToTree(theTree,112);
    insertIntValueToTree(theTree,3);
    insertIntValueToTree(theTree,234);

    IntNode *SeachNode = findNodeWithValue(theTree,40);
    printf(" value =  %d \n", SeachNode ->value );
    printTree(theTree);
    printf("\n");
    IntNode *NodeForDelete = theTree -> root;
    deleteNodeWithElement(theTree,NodeForDelete,23);
    printTree(theTree);
    destroyIntTree(theTree);
    return 0;
}
