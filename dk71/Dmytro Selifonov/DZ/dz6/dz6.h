#ifndef dz6_c
#define dz6_c
#include <stdio.h>
#include <stdlib.h>


typedef struct __tagFloatNode FloatNode;

struct __tagFloatNode
{
	float value;
	FloatNode *prev;
	FloatNode *next;
};

// List description
typedef struct __tagFloatList
{
	FloatNode *head;
	FloatNode *tail;
	int count;
}FloatList;

FloatNode *createFloatNodeWithValue(float anFloatValue);
int TLInsertFloatValueAtIndex(FloatList *aList, float anFloatValue, int anIndex);
void TLPrintList(FloatList *aList);
float TLFloatValueAtIndex(FloatList *aList, int anIndex);
int TLAddFloatValueToList(FloatList *aList, float anFloatValue);
void TLDestroyFloatList(FloatList *aList);
FloatList *TLCreateFloatList();


#endif
