#include <stdio.h>
#include <stdlib.h>
#include "hometask_1_func.h"

int main()
{
    int strng_vl = 0;
    int clmn_vl = 0;
    int num_of_components = 0;
    int *strng_vl_p = &strng_vl;
    int *clmn_vl_p = &clmn_vl;
    int vl_rslt = 0;
    printf("\t\t\t\t- THIS PROGRAMM WILL TRANSPOSE YOUR MATRIX -\n");
    printf("\n- Please, define number of strings in matrix by integer value ...\n- Number of strings in matrix = ");
    do
    {
        vl_rslt = 0;
        vl_rslt = scanf("%i", &strng_vl);
        fflush(stdin);
        if (vl_rslt == 1)
        {}else
        {
           printf("- Your value does not meet the condition of this programm.\n- Please try again:\n- Number of strings in matrix = ");
        }
    }while(vl_rslt != 1);
    printf("\n- Please, define number of columns in matrix by integer value ...\n- Number of columns in matrix = ");
    do
    {
        vl_rslt = 0;
        vl_rslt = scanf("%i", &clmn_vl);
        fflush(stdin);
        if (vl_rslt == 1)
        {}else
        {
           printf("- Your value does not meet the condition of this programm.\n- Please try again:\n- Number of columns in matrix = ");
        }
    }while(vl_rslt != 1);
    num_of_components = strng_vl * clmn_vl;
    int mtrx[strng_vl][clmn_vl];
    int tr_mtrx[*clmn_vl_p][*strng_vl_p];
    printf("\n- Your matrix is: [%i][%i]\n", strng_vl, clmn_vl);
    for(int i = 0; i < strng_vl; ++i)
        for(int j = 0; j < clmn_vl; ++j)
        {
            mtrx[i][j] = tr_mtrx[j][i] = ntr_vl_fnc(i, j);
        }
    printf("\n- Your matrix has the next components:\n\t");
    output_matrix(mtrx, clmn_vl, num_of_components);
    printf("\n\n- Transposing by programm matrix is: [%i][%i]\n\n- And has the next components:\n\t", clmn_vl, strng_vl);
    output_matrix(tr_mtrx, strng_vl, num_of_components);
    printf("\n");
    return 0;
}
