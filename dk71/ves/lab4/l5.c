#include "l5.h"
#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
#include <stdlib.h>
#include <stdio.h>


void rtf(FILE *file, CharList *aList)
{
	if (file == NULL) {
		printf("ERROR\n");
		return;
	}
	char tmp;
	while (feof(file) == 0)
	{
	
		fscanf(file, "%c", &tmp);
		CharNode *aNode = SLCreateNodeWithCharValue(tmp);
		SLAddNode(aList, aNode);
	}
	return;
}

int bal_d(CharList *aList)
{
	CharNode *theNode = aList->head;
	int result = 0;
	do
	{
		if ('(' == theNode->value) result++;
		else if (')' == theNode->value) result--;
		theNode = theNode->nextNode;
		
	} while (NULL != theNode);
	if (result == 0) printf("balance save\n");
	else{
		printf("balance not save\n");
	}
}


