//
//  main.c
//  HW5
//
//  Created by Alexandra Syabrenko on 12.05.18.
//  Copyright © 2018 Alexandra Syabrenko. All rights reserved.
//

#include <stdio.h>
#include "quickSort.h"
#include "functions2.h"
#include "functions.h"

int main()
{
    int size = 8;
    ArrayCircles *array = createArray(size);
    
    for (int i = 0; i < size; i++)
    {
        Circle *circle = createCircle2(i, i + 2, 20 - i);
        addElement(array, circle);
    }
    
    quickSort(array, 0, 7);
    
    for (int i = 0; i < size; i++)
    {
        printCircle(array->circles[i]);
    }
    
    int radius = 14;
    int resultOfSearching = linearSearch(array, radius);
    if (resultOfSearching != -1)
    {
        printf("The circle with specified radius is situated on the %d position in our array :)\n", resultOfSearching);
    }
    else
    {
        printf("The circle with specified radius was not found :(\n");
    }
    return 0;
}
