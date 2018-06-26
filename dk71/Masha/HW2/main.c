#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"


int main(int argc, const char * argv[])
{
    int A_x, A_y, B_x, B_y, C_x, C_y,D_x,D_y;

    printf("Enter coordinates A and B and C and D:\n");


     printf("x(A)= ");
     scanf("%d",&A_x);
      printf("\n");
      printf("y(A)= ");
     scanf("%d",&A_y);
     printf("\n");
 printf("x(B)= ");
     scanf("%d",&B_x);
     printf("\n");
 printf("y(B)= ");
     scanf("%d",&B_y);
     printf("\n");
     printf("x(C)= ");
     scanf("%d",&C_x);
      printf("\n");
      printf("y(C)= ");
     scanf("%d",&C_y);
     printf("\n");
 printf("x(D)= ");
     scanf("%d",&D_x);
     printf("\n");
 printf("y(D)= ");
     scanf("%d",&D_y);
     printf("\n");

    Coordinate A = {A_x,A_y};
	Coordinate B = {B_x,B_y};
	Coordinate C = {C_x,C_y};
	Coordinate D = {D_x,D_y};

    if(checktherectangle(&A, &B, &C, &D)==0)
        printf("Coordinate is not right, try again\n");
    else
    {

	Point *ABCD = createRectangle(&A, &B, &C, &D);

	printRectangle(ABCD);
	printf("Ploscha ABCD = %f\n",Ploscha(ABCD));

	destroyRectangle(ABCD);

	return 0;
    }
}
