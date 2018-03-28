#include <stdio.h>
#include "dk_rectangle.h"
#include "dk_array.h"

int main()
{


    Point A = {-1, 2};//declaring points
    Point B = {1, 2};
    Point C = {1, -1};
    Point D = {-1, -1};

    Point X = {-2, 4};//declaring points
    Point Y = {2, 4};
    Point Z = {2, -2};
    Point K = {-2, -2};

    Rectangle *example1 = createRectangle(&A, &B, &C, &D);
    Rectangle *example2 = createRectangle(&X, &Y, &Z, &K);

    RectangleArray *RectBase = createArray(2);

    addElement(RectBase, example1);
    addElement(RectBase, example2);

    FILE *file = fopen("rectbase.json", "a+");

    writeArrayToJSON(file, RectBase);

    freeArray(RectBase);
    
    fflush(file);
    
    fclose(file);
}



