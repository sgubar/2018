#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "hometask_1.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    int strng_vl = 0;
    int clmn_vl = 0;
    int vl_rslt = 0;
    printf("\t\t\t\t- ДАННАЯ ПРОГРАММА ТРАНСПОНИРУЕТ ВВЕДЕННУЮ ВАМИ МАТРИЦУ -\n");
    printf("\n- Определите количество строк в матрице целочисленным значением ...\n- Количество строк = ");
    do
    {
        vl_rslt = 0;
        vl_rslt = scanf("%i", &strng_vl);
        fflush(stdin);
        if (vl_rslt == 1)
        {}else
        {
           printf("- Введенное вами значение не соответствует условию программы.\n- Повторите попытку:\nКоличество строк = ");
        }
    }while(vl_rslt != 1);
    printf("\n- Определите количество столбцов в матрице целочисленным значением ...\n- Количество столбцов = ");
    do
    {
        vl_rslt = 0;
        vl_rslt = scanf("%i", &clmn_vl);
        fflush(stdin);
        if (vl_rslt == 1)
        {}else
        {
           printf("Введенное вами значение не соответствует условию программы.\nПовторите попытку:\nКоличество строк = ");
        }
    }while(vl_rslt != 1);
    int mtrx[strng_vl][clmn_vl];
    int tr_mtrx[clmn_vl][strng_vl];
    printf("\nВаша матрица имеет виhometask_1.hд: [%i][%i]\n", strng_vl, clmn_vl);
    for(int i = 0; i < int ntr_vl_fnc(int strng, int clmn)
{
    int ntr_vl = 0;
    int vl_rslt = 0;
            do
            {
                printf("\nВведите целочисленное значение для компонента [%i][%i]\n", strng, clmn);
                printf("[%i][%i] = ");
                vl_rslt = scanf("%i", &ntr_vl);
                fflush(stdin);
                if (vl_rslt == 1)
                {}else
                {
                    printf("\nВведенное вами значение не соответствует условию программы.\nПовторите попытку.\n");
                }
            }while(vl_rslt != 1);
        return ntr_vl;
}
strng_vl; ++i)
        for(int j = 0; j < clmn_vl; ++j)
        {
            mtrx[i][j] = tr_mtrx[j][i] = ntr_vl_fnc(i, j);
        }
    printf("\nУказанная вами матрица состоит из следующих компонентов:");
    for(int i = 0; i < strng_vl; ++i)
    {
        printf("\n\n\t");
        for(int j = 0; j < clmn_vl; ++j)
        {
            printf("%i   ", mtrx[i][j]);
        }
    }
    printf("\n\n- Транспонированная программой матрица имеет вид: [%i][%i]\n\n- И состоит из следующих компонентов:", clmn_vl, strng_vl);
    for(int i = 0; i < clmn_vl; ++i)
    {
        printf("\n\n\t");
        for(int j = 0; j < strng_vl; ++j)
        {
            printf("%i   ", tr_mtrx[i][j]);
        }
    }
    printf("\n");
}
