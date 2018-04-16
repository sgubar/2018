#include "kvadratV3.h"
int vvod_numeral()
{
int n;
int res;
do {
res = scanf("%d", &n);
while (getchar() != '\n');
if (res == 1)
    {
   printf("%s", "Есть цифра!\n");
return n;
}
else printf("%s", "Это не цифра:\n"); }
while (res != 1);
return 0;
}



Kvadrat *creature_Kvadrat(Point *A, Point *B, Point *C, Point *D)
{
    Kvadrat *Result = NULL;

    if (NULL != A && NULL != B && NULL != C && NULL != D)
        {
        Result = (Kvadrat *)malloc(sizeof(Kvadrat));
            if (NULL != Result)
            {
           Result->A = point_to_point(A);
           Result->B = point_to_point(B);
           Result->C = point_to_point(C);
           Result->D = point_to_point(D);
            }
        }
return Result;
}
int check_Kvadrat(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy)
{
float L_AB;
float L_BC;
float L_CD;
float L_DA;
L_AB=sqrt(pow(Ax-Bx,2)+pow(Ay-By,2));
L_BC=sqrt(pow(Bx-Cx,2)+pow(By-Cy,2));
L_CD=sqrt(pow(Cx-Dx,2)+pow(Cy-Dy,2));
L_DA=sqrt(pow(Dx-Ax,2)+pow(Dy-Ay,2));
/*printf("Длина стороны АВ=L_AB==%f\n",L_AB);*/
/*printf("Длина стороны АВ=L_AB==%f\n",L_BC);*/
/*printf("Длина стороны АВ=L_AB==%f\n",L_CD);*/
/*printf("Длина стороны АВ=L_AB==%f\n",L_DA);*/
float diagonal_AC;
float diagonal_BD;
diagonal_AC=sqrt(pow(Ax-Cx,2)+pow(Ay-Cy,2));
diagonal_BD=sqrt(pow(Bx-Dx,2)+pow(By-Dy,2));
/*printf("Диагональ АС=diagonal_AC==%f\n",diagonal_AC);*/
/*printf("Диагональ BD=diagonal_BD==%f\n",diagonal_BD);*/
printf("******************************************************************************\n");
if ((L_AB=L_BC)&&(L_AB=L_CD)&&(L_AB=L_DA)&&(diagonal_AC=diagonal_BD))
{
    printf("Стороны фигурыи равны между собой, диагонали тоже\nзначит фигура эта есть КВАДРАТ\n");
}

return 0;
}

void Remove_Kvadrat(Kvadrat *aKvadrat)
{
    if (NULL != aKvadrat)
    {
        free(aKvadrat->A);
        free(aKvadrat->B);
        free(aKvadrat->C);
        free(aKvadrat->D);
        free(aKvadrat);
    }
}

float S_Kvadrat(Kvadrat *aKvadrat)/*Площадь квадрата*/
{
float Result = 0.0;
if (NULL != aKvadrat)
{
/*Ещё раз вычислим длину любой стороны Квадрата и вычислим площадь*/
float Dx = (aKvadrat->A->x - aKvadrat->B->x);
float Dy = (aKvadrat->A->y - aKvadrat->B->y);
Result = sqrt(Dx*Dx + Dy*Dy);
Result=pow(Result,2);
}
return Result;
}

void output_console_Kvadrat(Kvadrat *aKvadrat)
{
    if (NULL != aKvadrat)
    {
        printf ("Координаты КВАДРАТА. A(%d,%d) - B(%d,%d) - C(%d,%d)- D(%d,%d)\n\n",
                        aKvadrat->A->x, aKvadrat->A->y, aKvadrat->B->x,
                        aKvadrat->B->y, aKvadrat->C->x, aKvadrat->C->y,
                        aKvadrat->D->x, aKvadrat->D->y);
    }
}

Point *point_to_point(Point *pPoint)
{

                Point *Result = (Point *)malloc(sizeof(Point));
                if (NULL != Result)
                {
                    Result->x = pPoint->x;
                    Result->y = pPoint->y;
                }
return Result;
}
