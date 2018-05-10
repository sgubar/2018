#ifndef tools
#define tools
#include <stdio.h>


typedef struct intNode Node;

typedef struct intNode
{
  char letter;
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
void size_list(List *thelist);
void print_list(List *thelist);
void delete_list(List *thelist);
Node *createNodeWithLetter(char letter);
void add_element(List *thelist, char letter);
void delete_element(List *thelist, int index);
void qsort_list(List *thelist, int first, int last);
void insert_element(List *thelist, int index, char letter);
Node *NodeAtIndex(List *thelist, int index);
void swap(List *thelist, int theLeft, int theRight);
int partition(List *thelist, int first, int last);
void qsort_list(List *thelist, int first, int last);


#endif

	

