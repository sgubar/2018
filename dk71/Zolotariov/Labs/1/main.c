#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "dk_tool.h"



int main() {
	
	int d, a, f, c, q;
	char s[100];
	
	printf("Enter D:\n");
	while(d < 1) {
		checkD(&d);
	}
	
	printf("\nEnter A:\n");
	while(a < 1) {
		checkA(&a);
	}
	
	printf("\nEnter F in HEX system:\n");
	do{
		printf("F = ");	
		scanf("%s",&s);
		f = transfer(s);
	}
	while(f != transfer(s));
	
	printf("\nEnter C:\n");
	checkC(&c);	

	q = (a * (f - c))*d;
 
	printf("\n\nRezult:\n");
	printf("Q = %i\n", q);
}
