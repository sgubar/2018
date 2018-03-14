#include <stdio.h>
#include <stdlib.h>
#include "tool.h"


int main() 
{
	int a,b,c,h;
	float left,right;
	h=0;
	do
	{
		printf("\nEnter integer A - ");    
		scanf("%d",&a);
		printf("Enter integer B>0 - ");                                                                       //interview
		scanf("%d",&b);
		do
			{
				if (b<=0)
				{
					printf("ERROR! B must be higher then 0 - ");      //protection from a numbnuts
					scanf("%d",&b);	
				}
				
			}
		while (b<=0);
		printf("Enter integer C - ");
		scanf("%d",&c);	
		
		left=(leftside(a,b,c));
		right=(rightside(b));
		
		printf("\nLeft - %.2f",left);
		printf("\nRight - %.2f",right);
		printf("\nAnswer - %.2f",left+right);		
		
	
		
	}
	while (h!=1);	                                 //to continue the program forever	
	
	
	
	return 0;
}  
