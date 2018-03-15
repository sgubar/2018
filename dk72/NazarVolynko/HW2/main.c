#include "dk_kvadrat.h"

int main(int argc, const char * argv[])
{
    int A_x, A_y, B_x, B_y, C_x, C_y,D_x,D_y;
    printf("KVADRAT\n\n");
    printf("Vedit koordunaty tochky A:\nx=");
    scanf("%d",&A_x);
    printf("y=");
    scanf("%d",&A_y);

    printf("Vedit koordunaty tochky B:\nx=");
    scanf("%d",&B_x);
    printf("y=");
    scanf("%d",&B_y);

	printf("Vedit koordunaty tochky C:\n");
	do
    {
        printf("x=");
        scanf("%d",&C_x);
        printf("y=");
        scanf("%d",&C_y);
        if(pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(C_x-B_x,2)+pow(C_y-B_y,2)!=pow(A_x-C_x,2)+pow(A_y-C_y,2)||
           pow(A_x-B_x,2)+pow(A_y-B_y,2)!=pow(C_x-B_x,2)+pow(C_y-B_y,2))
        {
            printf("Pomylka! Nevirni koordynaty tochky C. Vedit sche raz!");
        }
        printf("\n");

    }while( pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(C_x-B_x,2)+pow(C_y-B_y,2)!=pow(A_x-C_x,2)+pow(A_y-C_y,2) ||
            pow(A_x-B_x,2)+pow(A_y-B_y,2)!=pow(C_x-B_x,2)+pow(C_y-B_y,2));


    D_x=(A_x+C_x)-B_x;
    D_y=(A_y+C_y)-B_y;

	Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {D_x,D_y};

	Kvadrat *ABCD = createKvadrat(&A, &B, &C, &D);

	printKvadrat(ABCD);

	printf("Ploscha ABCD = %f\n", ploschaKvadrat(ABCD));

	destroyKvadrat(ABCD);

	return 0;
}
