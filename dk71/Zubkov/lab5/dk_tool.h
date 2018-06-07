#include <stdio.h>

struct tree
{
	struct tree *left;
	struct tree *right;
	double data;
};

typedef struct tree Tree;


void AddNode(Tree **myTree, double value);
void PrintElements(Tree *myNode);
void DeleteElements(Tree *myNode);
Tree *Search(Tree **myTree, double value);
void interface(void);


