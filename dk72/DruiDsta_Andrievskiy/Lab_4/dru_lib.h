#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


void readFileToList(FILE *file,CharList *theList);
CharNode *createCharNodeWithValue(char anCharValue);
void TLPrintList(CharList *aList);
void TLAddCharValueToList(CharList *aList, char anCharValue);
void TLDestroyCharList(CharList *aList);
CharList *TLCreateCharList();


