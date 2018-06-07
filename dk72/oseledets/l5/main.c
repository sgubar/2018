#include <stdio.h>
#include "Binare_tree.h"
int main() {
    IntTree *theTree = createIntTree();
    insertIntValueToTree(theTree,60);
    insertIntValueToTree(theTree,23);
    insertIntValueToTree(theTree,34);
    insertIntValueToTree(theTree,1412);
    insertIntValueToTree(theTree,3434);
    insertIntValueToTree(theTree,1234);
    insertIntValueToTree(theTree,6320);
    insertIntValueToTree(theTree,2321);
    insertIntValueToTree(theTree,4134);
    insertIntValueToTree(theTree,432);
    insertIntValueToTree(theTree,53334);
    insertIntValueToTree(theTree,11234);

    IntNode *SeachNode = findNodeWithValue(theTree,53334);
    printf(" value =  %d \n", SeachNode ->value );
    printTree(theTree);
    printf("\n");
    IntNode *NodeForDelete = theTree -> root;
    deleteNodeWithElement(theTree,NodeForDelete,23);
    deleteNodeWithElement(theTree,NodeForDelete,41134);
    deleteNodeWithElement(theTree,NodeForDelete,6320);
    deleteNodeWithElement(theTree,NodeForDelete,11234);
    printTree(theTree);
    destroyIntTree(theTree);
    return 0;
}
