#include <stdio.h>
#include "circular_list.h"

int main(int argc, const char * argv[])
{
	IntList *theList = SLCreateList();
	int size = 0,N = 0;
	printf("size of list: ");
	scanf("%d",&size);
	while(N != size){
		int z;
		printf("enter the value of the %d node: ",N);
		scanf("%d",&z);
			SLAddNode(theList, SLCreateNodeWithIntValue(theList, z));
		N++;
	}
	doPrintSLList(theList, minNode(theList)->index);
	
	printf("Done.\n ");

}
