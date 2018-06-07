#include <stdio.h>

typedef struct aNode
{
    char value;
    struct aNode *next;
}Node;

void addElement(Node **theNode, char val);
void delList(Node **theNode);
void printList(Node *theNode);

void interface(void);

