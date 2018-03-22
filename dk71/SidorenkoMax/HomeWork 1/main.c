#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main() {
	int a,d,l,result;
	int longG;
	char s[100];
	char g[100];
	printf("Your text: \n");
	gets(s);
	int longS = strlen(s);
	do{
			printf("Your key \n");
			gets(g);
			longG = strlen(g);	
	}while(longG > longS);
	result = func(s,g);
	printf("Result: %d", result);
}
