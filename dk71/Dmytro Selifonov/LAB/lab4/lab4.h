#ifndef lab4_c
#define lab4_c
#include <stdio.h>
#include <stdlib.h>


typedef struct __tagCharNode CharNode;

struct __tagCharNode
{
	char value;
	CharNode *prev;
	CharNode *next;
};

// List description
typedef struct __tagCharList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;

void TLPrintFromTheEnd(CharList *theList);
void readFileToList(FILE *file,CharList *theList);
CharNode *createCharNodeWithValue(char anCharValue);
int TLInsertCharValueAtIndex(CharList *aList, char anCharValue, int anIndex);
void TLPrintList(CharList *aList);
char TLCharValueAtIndex(CharList *aList, int anIndex);
int TLAddCharValueToList(CharList *aList, char anCharValue);
void TLDestroyCharList(CharList *aList);
CharList *TLCreateCharList();


#endif
