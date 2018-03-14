#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"
#include <Math.h>
int a,b,c;
int main(int argc, char *argv[]) {
	printf("enter value A:");
	scanf("%d",&a);
	printf("enter value B:");
	scanf("%d",&b);
	printf("enter value C:");
	scanf("%d",&c);
	float theResult=multiply(a,division(sqrt(b+c),b))+math_sum(c,a);
	printf("%f \n",theResult);
	return 0;
}
