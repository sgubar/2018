#include <stdio.h>
#include "tool.h"
#include <conio.h>

#define MAX_VALUE 10



int main()
{
	int array[MAX_VALUE];
	int pos, i;
	char symbol[MAX_VALUE];
	
	

	
	
	memcpy(array, random(), sizeof(array)); 
	
	FILE *laba = fopen("lab.txt","w");
	
	for(pos = 0; pos < MAX_VALUE; pos++)
	{
		symbol[pos] = array[pos];
		printf("%c", symbol[pos]);
		fprintf(laba,"%c", symbol[pos]); 
	}

	fclose(laba);
	
	
	
	CharList *theList = SLCreateList();
	
	loadFile ("lab.txt", theList);

    printf("\n=>\n");
    doPrintSLList(theList);
    
    printf("\n<=\n");
    doPrintSLList_Conversely(theList);
    
    printf("\n=>\n");
    doPrintSLList(theList);
    
    printf("\n<=\n");
    doPrintSLList_Conversely(theList);


    SLFreeList(theList);




    return 0;
}
