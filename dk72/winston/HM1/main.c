#include <stdio.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"




int main ()
{
        int *a;
        int i, j, n, m;


        printf("Enter arrows: \n");
        scanf("%d", &n);
        printf("Enter columns: \n");
        scanf("%d", &m);


        yourmatr1(a, m, n);
}

