#include <stdio.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"




int main ()
{
        int *c;
        int *b;
        int *a;
        int i, j, n, m, l, o, h, t;


        printf("Enter arrows: \n");
        scanf("%d", &n);
        printf("Enter columns: \n");
        scanf("%d", &m);


        yourmatr1(a, m, n);

        printf("Enter arrows: \n");
        scanf("%d", &l);
        printf("Enter columns: \n");
        scanf("%d", &o);


        yourmatr2(b, l, o);

        printf("\n\n    The result of subtraction matrix:\n");

        yourmatr3(c, h, t);
}
