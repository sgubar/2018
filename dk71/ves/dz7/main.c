#include "Tree.h"
int main()
{ 
	int node_1 = 4;
	int node_2 = 0;
	int node_3 = 9;
	int node_4 = 25;
	int node_5 = 1;
	int node_6 = 3;
	int node_7 = 7;

	Node *root = NULL;

    insert(&root, node_1);
    insert(&root, node_2);
    insert(&root, node_3);
    insert(&root, node_4);
    insert(&root, node_5);
    insert(&root, node_6);
    insert(&root, node_7);

	printTree(root, "root", 0);
	
    printf("max = %d\n", getMaxNode(root)->a);
    printf("min = %d\n", getMinNode(root)->a);
    
    deleteValue(root, node_1);
    printf("after delete node:\n");
    printTree(root, "root", 0);
   
    printf("Bypass:\n");
	DirectBypass(root);
	
    deleteTree(&root);
    
	printf("\n");
	system("pause");
}

