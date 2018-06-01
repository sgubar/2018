#ifndef func_h
#define func_h

 
#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))
 
typedef struct  Node
	{
		int data;	   
	    struct Node *left;
	    struct Node *right;
	    struct Node *parent;
	} Node;

Node* getFreeNode(int *value, Node *parent);
void insert(Node **head, int value);
void printTree(Node *root, const char *dir, int level);
void deleteTree(Node **root);
Node *getNodeByValue(Node *root, int value);
void removeNodeByPtr(Node *target);
void deleteValue(Node *root, int value);
Node* findMaxNode(Node *root);
Node* findMinNode(Node *root);


#endif
