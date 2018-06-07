#include "dk_tool.h"

int main() {
	Node* root = newNode(10);
	Tree* tree = newTree(root);
	insert(&root, 12);
	insert(&root, 11);
	insert(&root, 16);
	insert(&root, 9);
	insert(&root, -3);
	insert(&root, 51);
	insert(&root, 2);
	insert(&root, 34);
	insert(&root, 4);
	insert(&root, 0);
	print(root, 4);
	printf("\n\n\n\n");
	extract(root, 12);
	print(root, 4);
	print_postorder(root);
	clear(root);
    return 0;
}

