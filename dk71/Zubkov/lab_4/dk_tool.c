#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
#include <ctype.h>
#define LENNAME 255
void addElement(Node **theNode, char val)
{
	Node *aNode = (Node *) malloc(sizeof(Node));
	aNode->value = val;
	aNode->next = (*theNode);
	(*theNode) = aNode;
	aNode = NULL;
}

void delList(Node **theNode)
{
	if(theNode != NULL)
	{
		Node *del = NULL;
		while((*theNode)->next)
		{
	    	del = *theNode;
	    	*theNode = (*theNode)->next;
	    	free(del);
	    }
		free(*theNode);
		*theNode = NULL;
	}
}

void printList(Node *aNode)
{
	if(aNode)
	{
		while(aNode)
		{
	    	printf("%c", aNode->value);
	    	aNode = aNode->next;
	    }
	}
} 
void revers(FILE *afile, Node *theNode) {
	
		char text;
		while((text = fgetc(afile)) != EOF)
		{
			if(isalpha(text))
			{
				while(isalpha(text) && text != '\n' && text != EOF)
				{
					addElement(&theNode, text);
					text = fgetc(afile);
			   	}
				
				if(theNode != NULL)
			   	{
					printList(theNode);
					delList(&theNode);
				}
			}
			printf("%c", text);
		}
		fclose(afile);
	
	
}
void getFile(FILE *afile, Node *theNode) {
	int finish = 0;
	do {

		printf("\n Введите название файла: ");
		puts( "Введите имя файла" );
    	char fSrcName[ LENNAME ];
    	gets( fSrcName );
 
		
		FILE *afile = fopen(fSrcName,"r");
		if(fSrcName && afile != NULL)
		{
		finish = 1;
		revers(afile,theNode);	
		}
		else
		{
			printf("Файл не найден\n");
			
		}
	} while(finish == 0);
}
void interface(void) {
	int finish = 0;

	int var = 0;
	Node *theNode = NULL;
	FILE *afile = NULL;
	while(finish != 1) 
	{ 	
		printf("\nМеню: ");
		printf("\n1. Считать данные; ");
		printf("\n2. Выход;\n");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		
		getFile(afile,theNode);
	

    
  		 break; 
  		 
		case 2:
			finish = 1;
  		 break;
		default:
 
  		break;
		} 	
	}
	

}
