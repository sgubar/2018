#include <stdio.h>
#include "tree.h"
int main() {
	int n,i,b,s,x;
	FloatTree *theTree = createFloatTree();
	printf("Enter the size of tree: ");
	scanf("%d",&n);
	for(i = 0 ; i < n ; i ++){
	printf("Enter the value of the %d branch ", i);
	scanf("%d",&b);	
	insertFloatValueToTree(theTree,b);
	}
    
	printf("enter the item to search :");
	scanf("%d",&s);
    FloatNode *SeachNode = findNodeWithValue(theTree,s);
    printf(" an element with value %d exists ... \n", SeachNode->value );
    printTree(theTree);
    printf("\n");
    FloatNode *NodeForDelete = theTree -> root;
    printf("enter the value of the element you want to delete: ");
    scanf("%d",&x);
    deleteNodeWithElement(theTree,NodeForDelete,x);
    printTree(theTree);
    destroyFloatTree(theTree);
    return 0;
}
