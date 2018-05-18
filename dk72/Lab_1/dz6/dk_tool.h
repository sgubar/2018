#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>

typedef struct intNode Node;

typedef struct intNode
{
  char value;
  Node *prev;
  Node *next;
}Node;

typedef struct intList
{	
  int size;
  Node *first;
  Node *last;
}List;

List *create_list();
void size_list(List *alist);
void delete_list(List *alist);
Node *createNodeWithLetter(char letter);
void add_element(List *alist, char letter);
void delete_element(List *alist, int index);
void qsort_list(List *alist, int first, int last);
void insert_element(List *alist, int index, char letter);
Node *NodeAtIndex(List *alist, int index);
void swap(List *alist, int theLeft, int theRight);
int partition(List *alist, int first, int last);


#endif
