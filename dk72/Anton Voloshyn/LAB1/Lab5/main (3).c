#include <stdio.h>
#include "Binare_tree.h"
int main() {
    FloatTree *theTree = createFloatTree();
    insertFloatValueToTree(theTree,40.3);
    insertFloatValueToTree(theTree,23.4);
    insertFloatValueToTree(theTree,44);
    insertFloatValueToTree(theTree,112.1);
    insertFloatValueToTree(theTree,3.434);
    insertFloatValueToTree(theTree,234.5);

    FloatNode *SeachNode = findNodeWithValue(theTree,40.3);
    printf(" value =  %f \n", SeachNode ->value );
    printTree(theTree);
    printf("\n");
    FloatNode *NodeForDelete = theTree -> root;
    deleteNodeWithElement(theTree,NodeForDelete,23.4);
    printTree(theTree);
    destroyFloatTree(theTree);
    return 0;
}
