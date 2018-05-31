#include <stdio.h>
#include "dz_7.h"
int main() {
	int n,i;
	float b,s,x;
	IntTree *theTree = createIntTree();
	printf("Enter the size of tree: ");
	scanf("%d",&n);
	for(i = 0 ; i < n ; i ++){
	printf("Enter the value of the %d branch ", i);
	scanf("%f",&b);	
	insertIntValueToTree(theTree,b);
	}
    
	printf("enter the item to search :");
	scanf("%f",&s);
    IntNode *SeachNode = findNodeWithValue(theTree,s);
    printf(" an element with value %f exists ... \n", SeachNode->value );
    printTree(theTree);
    printf("\n");
    IntNode *NodeForDelete = theTree -> root;
    printf("enter the value of the element you want to delete: ");
    scanf("%f",&x);
    deleteNodeWithElement(theTree,NodeForDelete,x);
    printTree(theTree);
    destroyIntTree(theTree);
    return 0;
}
