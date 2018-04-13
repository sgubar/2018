#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "hometask_1.h"

int ntr_vl_fnc(int strng, int clmn)
{
    int ntr_vl = 0;
    int vl_rslt = 0;
            do
            {
                printf("\n- Please enter an integer value for component [%i][%i]\n", strng, clmn);
                printf("[%i][%i] = ");
                vl_rslt = scanf("%i", &ntr_vl);
                fflush(stdin);
                if (vl_rslt == 1)
                {}else
                {
                    printf("\n- Your value does not meet the condition of this programm.\n- Please try again.\n");
                }
            }while(vl_rslt != 1);
        return ntr_vl;
}

void output_matrix(int matrix[], int strngs, int num_comp)
{
    for(int i = 0; i < num_comp; ++i)
    {
        if(i != 0 && i % strngs == 0)
            printf("\n\n\t");
        printf("%i\t", matrix[i]);
    }
}
