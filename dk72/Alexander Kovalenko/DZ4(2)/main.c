//
//  main.c
//  dz2
//
//  Created by Alexander Kovalenko on 3/15/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "dk_ellipse_array.h"
#include "SimpleSort.h"

int main(int argc, const char * argv[])
{
	EllipseArray *theArray = createArray(5);
    int SquareEllipseArray[5];
    Point Cntr1 = {50,50};
	int a1 = 40;
    int b1 = 20;
	
	Ellipse El1 = {&Cntr1, a1, b1};

    addElement(theArray, &El1);
    	
	a1 = 50;
	b1 = 30;
	
    El1.O = &Cntr1;
    El1.a = a1;
    El1.b = b1;
	
    addElement(theArray, &El1);
    
    
    El1.a = 15;
    El1.b = 10;
	
    addElement(theArray, &El1);
    
    El1.a = 70;
    El1.b = 50;
	
    addElement(theArray, &El1);
    
    
    El1.a = 12;
    El1.b = 5;
	
    addElement(theArray, &El1);
    
	FILE *theFile = fopen("test.json", "a+");
    writeArrayToJSON(theFile, theArray);

    int i;
	for (i=0; i < theArray->count; i++)
      {
        SquareEllipseArray[i]=round(SquareEllipse(theArray->ellipses[i]));  
      }
      
    for (i=0; i < theArray->count; i++)
      {
        printf("\n EllipseSquare[%d] = %d\n", i, SquareEllipseArray[i]);  
      }
    
	bubbleSort(SquareEllipseArray, theArray->count);
    
    printf("\n\nSorted\n");
	
    for (i=0; i < theArray->count; i++)
      {
        printf("\n EllipseSquare[%d] = %d\n", i, SquareEllipseArray[i]);  
      }

	fflush(theFile);
	fclose(theFile);
	
    freeArray(theArray);
   
	return 0;
}
