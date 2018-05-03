#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "functions2.h"
#include "sorting.h"
int main()
{
    ArrayCircles *array = createArray(8);
    
    for (int i = 0; i < 8; i++)
    {
        Circle *circle = createCircle2(i, i + 2, 20 - i);
        printCircle(circle);
        
        addElement(array, circle);
    }
    
    Circle *circle = createCircle2(3, 3, 3);
    addElementByIndex(array, circle, 1);
    
    sort(array);
    
    FILE *theFile = fopen("/Users/alexandrasyabrenko/Documents/Programming/HW3/test.json", "a+");
    
    writeArrayToJSON(theFile, array);
    
    fflush(theFile);
    fclose(theFile);
    
    
    freeArray(array);
}
