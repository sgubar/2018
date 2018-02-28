#include "dk_tool.h"

int main()
{
    int (*Yfactorial)(int)=&factorial;

    int chislo_A,chislo_B,chislo_C,chisloKintseve;

    do
    {
        printf("Vedit chislo A(A>0): ");
        scanf("%d",&chislo_A);
        printf("\n");
        if(chislo_A<0)
        {
        printf("Pomylka! Vedit chislo A sche raz!");
        printf("\n\n");
        }

    }while(chislo_A<0);

    do
    {
        printf("Vedit chislo B(B!=0): ");
        scanf("%d",&chislo_B);
        printf("\n");
        if(chislo_B==0)
        {
             printf("Pomylka! Vedit chislo B sche raz!");
             printf("\n\n");
        }

        if(chislo_B!=0)
           {
               do
               {
                   printf("Vedit chislo C(B+C>0): ");
                   scanf("%d",&chislo_C);
                   printf("\n");
                    if(chislo_B+chislo_C<0)
                       {
                          printf("Pomylka! Vedit chislo B sche raz!");
                          printf("\n\n");
                       }
               }while(chislo_B+chislo_C<0);
           }
           if(chislo_B+chislo_C<0)
        {
             printf("Pomylka! Vedit chislo C sche raz!");
             printf("\n\n");
        }

    }while(chislo_B==0);

    printf("\nRezultat: ");
    chisloKintseve=functsiaSumy(chislo_A,chislo_C , Yfactorial)+chislo_A*sqrt(chislo_B+chislo_C)/chislo_B;
    printf("%d",chisloKintseve);
    printf("\n");
    return 0;
}
