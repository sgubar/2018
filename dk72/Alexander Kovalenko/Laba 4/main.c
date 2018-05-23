#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
#include <ctype.h>

int main()
{
	Node *theNode = NULL;
	FILE *afile = fopen("txt.txt","r");
	
	if(afile != NULL)
	{
		char symbol;
		while((symbol = fgetc(afile)) != EOF)
		{
			if(isalpha(symbol))
			{
				while(isalpha(symbol) && symbol != '\n' && symbol != EOF)
				{
					addElement(&theNode, symbol);
					symbol = fgetc(afile);
			   	}
				
				if(theNode != NULL)
			   	{
					printList(theNode);
					delList(&theNode);
				}
			}
			printf("%c", symbol);
		}
		fclose(afile);
	}
	else
	{
		printf("No file\n");
		return 1;
	}
	
	return 0;
} 
