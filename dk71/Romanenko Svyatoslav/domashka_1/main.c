#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "dz_1.h"

int main()
{
    int strng_vl = 0;
    int clmn_vl = 0;
    int num_of_components = 0;
    int *mtrx = NULL;
    int *tr_mtrx = NULL;
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
           printf("-Vasha tsinnist ne vyhidna tym, khto korystuyetsya podiyamy.\n- Bud laska sprobuite che raz:\n- kilkist ryadkiv u matrice = ");
        }
    }while(vl_rslt != 1);
    printf("\n- Bud laska, vysnachte kilkist stovptciv u matrice za cilum znachenyam ...\n- ʳ������ �������� � ������� = ");
    do
    {
        vl_rslt = 0;
        vl_rslt = scanf("%i", &clmn_vl);
        fflush(stdin);
        if (vl_rslt == 1)
        {}else
        {
           printf("- Vasha tsinnist ne vyhidna tym, khto korystuyetsya podiyamy.\n- Bud laska sprobuite che raz:\n- kilkist ryadkiv u matrice = ");
        }
    }while(vl_rslt != 1);
    num_of_components = strng_vl * clmn_vl;
    tr_mtrx = (int*)malloc(strng_vl * clmn_vl * sizeof(int));
    mtrx = (int*)malloc(strng_vl * clmn_vl * sizeof(int));
    printf("\n- Your matrix is: [%i][%i]\n", strng_vl, clmn_vl);
    for(int i = 0; i < strng_vl; ++i)
         for(int j = 0; j < clmn_vl; ++j)
        {
            *(mtrx + i * clmn_vl + j) = ntr_vl_fnc(i, j);
            *(tr_mtrx + j * strng_vl + i) = *(mtrx + i * clmn_vl + j);
        }
    printf("\n- Vasha matrica �� nastupni komponenty:\n\t");
    output_matrix(mtrx, clmn_vl, num_of_components);
    printf("\n\n- Peredachya za programou matrica - zhe: [%i][%i]\n\n- I mae nastupni komponenty:\n\t", clmn_vl, strng_vl);
    output_matrix(tr_mtrx, strng_vl, num_of_components);
    printf("\n");
    return 0;
}
