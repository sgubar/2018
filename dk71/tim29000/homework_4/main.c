#include "dk_ellipse4.h"
#include "dk_arrellipse4.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{
    EllipseArr *mass = createArr(5);

    Point A = {-5, 0};
    Point B = {0, 2};
    Point C = {5, 0};
    Point D = {0, -2};
    Point ACentre = {3,3};

    Point X = {-8, 0};
    Point Y = {0, 3};
    Point Z = {8, 0};
    Point K = {0, -3};
    Point BCentre = {0,0};

    Point a = {-6, 0};
    Point b = {0, 2};
    Point c = {6, 0};
    Point d = {0, -2};
    Point CCentre = {0,0};

    Point E = {-5, 0};
    Point F = {0, 6};
    Point G = {5, 0};
    Point H = {0, -6};
    Point DCentre = {0,0};

    Ellipse *one = createEllipse(&A, &B, &C, &D,&ACentre);
    Ellipse *two = createEllipse(&E, &F, &G, &H,&DCentre);
    Ellipse *three = createEllipse(&X, &Y, &Z, &K,&BCentre);
    Ellipse *four = createEllipse(&a, &b, &c, &d, &CCentre);



    Eladder(mass, one);
    Eladder(mass, two);
    Eladder(mass, three);
    Eladder(mass, four);

    FILE *Filex = fopen("Elliopse.txt", "a+");
    FILE *SelectFile = fopen("Select.txt", "a+");

    Arr_writer(Filex, mass);
    int size = 4;
    SelectSort(mass, size);
    Arr_writer(SelectFile, mass);

    fflush(Filex);
    fclose(Filex);

    fflush(SelectFile);
    fclose(SelectFile);

    freeArr(mass);
}
