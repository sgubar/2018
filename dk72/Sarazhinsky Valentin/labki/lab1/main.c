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
	while(b==0){
		printf("a value B can not be 0!!!\n");
		printf("enter value B:");
		scanf("%d",&b);
	}
	printf("enter value C:");
	scanf("%d",&c);
	while(c<=0){
		printf("C must be >0 !!!\n");
		printf("enter value C:");
		scanf("%d",&c);
	}
	while((b+c)<0){
		printf("B+C must be >=0 !!!\n");
		printf("enter value C:");
		scanf("%d",&c);
	}
	float theResult=multiply(a,division(sqrt(b+c),b))+math_sum(c,a);
	printf("Q = %f \n",theResult);
	return 0;
}
