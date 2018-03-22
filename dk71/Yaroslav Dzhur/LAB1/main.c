#include <stdio.h>
#include <conio.h>
#include "dk_tool.h"               //pidklyuchennya biblioteky


int main(int argc,char* argv[])

{

int A, B, C;                       //inicializaciya zminnyh

float Q = 0;
float FV = 0;
do
{

	 printf("Enter A : "); 
    while (!scanf("%d", &A)) { 
        while (getchar() != '\n'); 
        printf("Incorrect\nTry again: "); 
    } 
    
	 printf("Enter B : "); 
    while (!scanf("%d", &B)) { 
        while (getchar() != '\n'); 
        printf("Incorrect\nTry again: "); 
    }
    
    	 printf("Enter C : "); 
    while (!scanf("%d", &C)) { 
        while (getchar() != '\n'); 
        printf("Incorrect\nTry again: "); 
    }
} while (0 == P1(A,B,C, &FV));


Q =(float) FV + P2(A);                           //otrymannya vidpovidi

printf("\nYour answer is %.2f\n", Q);                   //vyvedennya vidpovidi
system("PAUSE");
return 0;
}




















