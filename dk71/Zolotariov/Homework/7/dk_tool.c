#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

Node* find_minimal(Node* node);

Node* newNode(float d) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->data = d;
	return node;
}

Tree* newTree(Node* root) {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = root;
	return tree;
}

void insert(Node** node, double value) {
	if (!(*node)) {
		*node = newNode(value);
		return;
	}
	else if ((*node)->data > value) {
		insert(&(*node)->left, value);
	}
	else {
		insert(&(*node)->right, value);
	}
}

Node* extract(Node* node, double value)
{
	if (node == NULL) return node;

	if (value < node->data)
		node->left = extract(node->left, value);

	else if (value > node->data)
		node->right = extract(node->right, value);

	else
	{
		if (node->left == NULL)
		{
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			Node *temp = node->left;
			free(node);
			return temp;
		}

		Node* temp = find_minimal(node->right);

		node->data = temp->data;

		node->right = extract(node->right, temp->data);
	}
	return node;
}

Node* find(Node* node, double value) {
	if (!node) {
		printf("Empty node passed\n");
		return NULL;
	}
	if (node->data == value)
		return node;
	else if (node->data > value) {
		return find(node->left, value);
	}
	return find(node->right, value);
}

void clear(Node* node) {
	if (node != NULL)
	{
		clear(node->left);
		clear(node->right);
		free(node);
	}
}


void print(Node *root, int space)
{
	if (root == NULL)
		return;

	space += 5;

	print(root->right, space);

	printf("\n");
	int i;
	for (i = 5; i < space; i++)
		printf(" ");
	printf("%f\n", root->data);

	print(root->left, space);
	
}

Node* find_minimal(Node* node)
{
	Node* current = node;
	while (current->left)
		current = current->left;

	return current;
}
