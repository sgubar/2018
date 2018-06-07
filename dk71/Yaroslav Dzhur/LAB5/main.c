#include <stdio.h>
#include "Binare_tree.h"
int main() {
    FloatTree *theTree = createFloatTree();
    insertFloatValueToTree(theTree,40.3);
    insertFloatValueToTree(theTree,22.4);
    insertFloatValueToTree(theTree,45);
    insertFloatValueToTree(theTree,112.1);
    insertFloatValueToTree(theTree,3.14);
    insertFloatValueToTree(theTree,233.5);

    FloatNode *SeachNode = findNodeWithValue(theTree,40.3);
    printf(" value =  %f \n", SeachNode ->value );
    printTree(theTree);
    printf("\n");
    FloatNode *NodeForDelete = theTree -> root;
    deleteNodeWithElement(theTree,NodeForDelete,22.4);
    printTree(theTree);
    destroyFloatTree(theTree);
    return 0;
}
