#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int search = 0;
	Node *root = NULL;
 	insert(&root, 10);
    insert(&root, 12);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 4);
	printf("GG\n");
	printTree(root, "root", 0);
	printf("\n");
	scanf("%d", &search);
	deleteValue(root, 7);
	printTree(root, "root", 0);
	printf("parent of %d is %d\n", search, getNodeByValue(root, search)->parent->data);
	deleteTree(&root);
	printf("GG \n");
	return 0;
}
