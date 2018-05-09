#ifndef KVADRATV3_H_INCLUDED
#define KVADRATV3_H_INCLUDED
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
int vvod_numeral();


/*Cоздание структуры для координат точек с тэгом-этикеткой - "tagPoint",  */
typedef struct tagPoint
{
int x;
int y;
}Point;

/* Описание Квадрата Kvadrat */
typedef struct tagSide
{
Point *A;
Point *B;
Point *C;
Point *D;
}Kvadrat;

/*Декларация функций*/
Point *point_to_point(Point *pPoint);
Kvadrat *creature_Kvadrat(Point *A, Point *B, Point *C, Point *D);

int check_Kvadrat(int, int, int, int, int, int, int, int);
void Remove_Kvadrat(Kvadrat *aKvadrat);
float S_Kvadrat(Kvadrat *aKvadrat);
void output_console_Kvadrat(Kvadrat *aKvadrat);


#endif // KVADRATV3_H_INCLUDED
