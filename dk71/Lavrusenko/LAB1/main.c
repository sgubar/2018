
#include "functions.h"

int main(){
	
char *sring1[0];
char *sring2[0];
char *sring3[0];	
int a,b,c;
double result;

do {
printf("\nEnter only digits, except '0'\n ");
printf("Enter value\n");
printf("a= ");
scanf("%s",&sring1[0]);
}
while(convert(&sring1)==0);
	
a=convert(&sring1);				
			 
do {
printf("\nEnter only digits, except '0'\n ");
printf("Enter value\n");
printf("b= ");
scanf("%s",&sring2[0]);}
while(convert(&sring2)==0);

b=convert(&sring2);	
				
do {
printf("\nEnter only digits, except '0'\n ");
printf("Enter value\n");
printf("c= ");
scanf("%s",&sring3[0]);}
while(convert(&sring3)==0);

c=convert(&sring3);	
	
result = plus(a,b,c) + sum(a,c);
	printf("Q = %f",result);
	
}
