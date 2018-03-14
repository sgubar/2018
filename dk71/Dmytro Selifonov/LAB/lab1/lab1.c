#include <stdio.h>
#include <stdlib.h>
#include "math1.h"


int main(int argc, char *argv[]) 
{
	int a,b,c,result;
	do{
		printf("vvedit A = ");
		scanf("%d",&a);
	}while(a<1);
	printf("vvedit C = ");
	scanf("%d",&c);
	b=read_hex();
	result=suma(a,b,c);
	printf("result = %d\n",result);

	
	return 0;
}
