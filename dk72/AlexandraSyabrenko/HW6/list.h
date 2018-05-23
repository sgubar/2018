#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    char value;
    struct node *next;
} Node;

Node *createNode(char value);

void deleteNode(Node *node);

typedef struct list
{
    Node *head;
    Node *tail;
    int count;
} List;

void deleteNode(Node *node);

void printNode(Node *node);

void deleteList(List *list);

List *createList(void);

Node *addNode(List *list, Node *newNode);

Node *getNodeAtIndex(const List *list, int index);

Node *removeNodeAtIndex(List *list, int index);

Node *insertNodeAtIndex(List *list, Node *newNode, int index);

int getLength(List *list);

void printList(const List *list);

int listCount( List *list);

void swapNodesByIndex(List *list, int left, int right);

int partitionIt(List *list, int leftIndex, int rightIndex, char pivot);

void quickSort(List *list, int leftIndex, int rightIndex);

void testList(void);

#endif /* list_h */
