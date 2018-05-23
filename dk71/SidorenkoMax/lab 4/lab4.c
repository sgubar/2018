#include "func.h"
#include "lab4.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


void ReadFromFile(FILE *file, CharList *aList)
	{
		if (file == NULL)
			{
				printf("Error with File");
				return;
			}
		char symbol;
		while (feof(file) == 0)
			{
				fscanf(file, "%c", &symbol);
				CharNode *aNode = ListValue(aList, symbol);
			}
	}
	
int AmountBrackets(CharList *theList)
	{
		CharNode *theNode = theList->head;
		int Result = 0;
		do{
			if( theNode->value == '(')Result++;
			if( theNode->value == ')')Result++;
			if( theNode->value == '{')Result++;
			if( theNode->value == '}')Result++;
			theNode = theNode->next;
			
		} while ( NULL != theNode );
		printf("\n\n\n\nResult = %d", Result-1);
	}
