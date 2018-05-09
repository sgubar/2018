#include "kvadratV3.h"
#include "kvAraay.h"

int main()
{
setlocale(LC_ALL, "Russian");


KvadratArray *anArray = createArray(10);
/*KvadratArray *KvadratDat = createArray(10);*/
printf("KVADRAT\n\n");
printf("Введи координаты точки A:\nx=");
Ax=vvod_numeral();
printf("x=%d\n",Ax);
printf("y=");
Ay=vvod_numeral();
printf("y=%d\n",Ay);
printf("******************\n");
printf("Введи координаты точки B:\nx=");
Bx=vvod_numeral();
printf("x=%d\n",Bx);
printf("y=");
By=vvod_numeral();
printf("******************\n");
printf("Поскольку имеем дело с квадратом,\nто кординаты точек C и D получаем исходя из координат точек А и В.\n\n");
getch(); /* Команда задержки экрана*/
system("cls");
Cx=Bx+(By-Ay);
Cy=By-(Bx-Ax);
Dx=(Ax+Cx)-Bx;
Dy=(Ay+Cy)-By;
/*    */
        Point A = {Ax,Ay};
        Point B = {Bx,By};
        Point C = {Cx,Cy};
        Point D = {Dx,Dy};
check_Kvadrat(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy); /*Проверка на квадрат*/
printf("******************************************************************************\n");

/*    */
/*Kvadrat *ABCD = creature_Kvadrat(&A, &B, &C, &D);Создание квадрата*/
/*-----------------------------------------------*/
Kvadrat *ABCD = creature_Kvadrat(&A, &B, &C, &D);
/*printf("Площадь квадрата ABCD = %f\n", S_Kvadrat(ABCD));*/
addElement(anArray, ABCD, S_Kvadrat(ABCD));

for (int i=0; i<10-1; i++){/*Довавляем в массив ещё девять записей*/
Ax=Ax+1;
Ay=Ay+0;
Bx=Bx+1;
By=By+1;
Cx=Bx+(By-Ay);
Cy=By-(Bx-Ax);
Dx=(Ax+Cx)-Bx;
Dy=(Ay+Cy)-By;
        Point A = {Ax,Ay};
        Point B = {Bx,By};
        Point C = {Cx,Cy};
        Point D = {Dx,Dy};
Kvadrat *ABCD = creature_Kvadrat(&A, &B, &C, &D);
/*printf("Площадь квадрата ABCD = %f\n", S_Kvadrat(ABCD));*/
addElement(anArray, ABCD, S_Kvadrat(ABCD));
}
outputConsoleArrayKvadrats(anArray);

FILE *file = fopen("kvadrat.json", "w");
writeArrayToJSON(file, anArray);
/*writeArrayToJSON(file, KvadratDat);*/
getch(); /* Команда задержки экрана*/

bubble(anArray);
shell(anArray);
find2(anArray);

freeArray(anArray);
/*freeArray(KvadratDat);*/
fflush(file);
fclose(file);
/*-----------------------------------------------*/
Remove_Kvadrat(ABCD);
printf("******************************************************************************\n");
printf("\nPress any key to exit...\n");
printf ("Экран не закрывается, пока не нажата любая клавиша...");
getch();	/*Экран не закрывается, пока не нажата любая клавиша*/
return 0;
}
