#include "Tree.h"

int main()
{ 
	int node_1 = 1;
	int node_2 = 0;
	int node_3 = 9;
	int node_4 = 25;
	int node_5 = 4;
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
    
	DirectBypass(root);
	deleteTree(&root);
	
	printf("\n");
	system("pause");
}

