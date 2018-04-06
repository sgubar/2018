//
//  main.c
//  dz2
//
//  Created by Alexander Kovalenko on 3/15/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#include <stdio.h>
#include "dk_ellipse_array.h"

int main(int argc, const char * argv[])
{
	EllipseArray *theArray = createArray(5);
    Point Cntr1 = {50,50};
	int a1 = 40;
    int b1 = 20;
	
	Ellipse *El1 = createEllipse(&Cntr1, &a1, &b1);

    addElement(theArray, El1);
	
	a1 = 50;
	b1 = 30;
	
    El1 = createEllipse(&Cntr1, &a1, &b1);
	
    addElement(theArray, El1);
	
	FILE *theFile = fopen("test.json", "a+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArray(theArray);
	
	
	return 0;
}
