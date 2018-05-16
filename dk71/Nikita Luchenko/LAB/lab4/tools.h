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
void print_list(List *thelist);
void delete_list(List *thelist);
Node *createNodeWithLetter(char letter);
void add_element(List *thelist, char letter);
int findMAX(List *thelist);
int findMIN(List *thelist);
void quickSort(List *thelist, int aLeftIndex, int aRightIndex);
int partition(List *thelist, int aLeftIndex, int aRightIndex);
void swap(List *thelist, int theLeft, int theRight);
Node *findAtIndex(List *thelist, int anIndex);
#endif

	
