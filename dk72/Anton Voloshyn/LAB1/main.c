#include <stdio.h>

#include "dk_tool.h"               


int main(int argc,char* argv[])

{

int A, B, C;  
float Q = 0;                     

printf("Enter your value A :\n");
	while(scanf("%d", &A)!=1) {
		while(getchar()!='\n');
		printf("You entered not a value. Enter your value again! \n");   		// Check your mind, for stupidity for value A
		}

printf("Enter your value B :\n");
	while(scanf("%d", &B)!=1) {
		while(getchar()!='\n');
		printf("You entered not a value. Enter your value again! \n");			// Check your mind, for stupidity again for value B
		}

printf("Enter your value C :\n");
	while(scanf("%d", &C)== 0) {
		while(getchar()!='\n');
		printf("You entered not a value. Enter your value again! \n");			// Check your mind, for stupidity again for value C
		}
		while ((100 - B - C) == 0)
		{
			printf ("Denominator can't be 0'");
			return 0;
		}
	Q =(float) (A + B + C)/(100 - B - C) + SecondFromSumm(A);   
               
	printf("\n Your Q = %.2f\n", Q);     
	return 0;
}




















