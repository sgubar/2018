#ifndef DK_TOOL_H
#define DK_TOOL_H

typedef struct Node Node;

struct Node {
	double data;
	Node* left;
	Node* right;
};

typedef struct {
	Node* root;
} Tree;

Node* newNode(float d);
Tree* newTree(Node* root);
void insert(Node** node, double value);
Node* extract(Node* node, double value);
Node* find(Node* node, double value);
void clear(Node* node);
void print(Node* node, int space);
#endif
