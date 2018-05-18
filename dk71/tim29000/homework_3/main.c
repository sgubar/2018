#include "dk_ellipse3.h"
#include "dk_arrellipse3.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{
    EllipseArr *mass = createArr(5);

    Point A = {-5, 0};
    Point B = {0, 2};
    Point C = {5, 0};
    Point D = {0, -2};
    Point Centre = {3,3};

    Point X = {-8, 0};
    Point Y = {0, 3};
    Point Z = {8, 0};
    Point K = {0, -3};
    Point ACentre = {0,0};

    Ellipse *one = createEllipse(&A, &B, &C, &D,&Centre);
    Ellipse *two = createEllipse(&X, &Y, &Z, &K,&ACentre);



    Eladder(mass, one);
    Eladder(mass, two);

    FILE *Filex = fopen("Elliopse.txt", "a+");

    Arr_writer(Filex, mass);

    fflush(Filex);
    fclose(Filex);

    freeArr(mass);
}
