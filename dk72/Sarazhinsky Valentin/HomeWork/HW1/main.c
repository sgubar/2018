#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
 int lines,columns;
 
int main(int argc, char *argv[]){
	printf("enter the length of the lines:");
	scanf("%d",&lines);
	printf("enter the length of the columns:");
	scanf("%d",&columns);
	transponation(lines, columns);
	
	return 0;
}
