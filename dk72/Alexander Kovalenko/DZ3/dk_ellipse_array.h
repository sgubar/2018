//
//  dk_ellipse_array.h
//  dz3
//
//  Created by Alexander Kovalenko on 4/03/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#ifndef dk_ellipse_array_h
#define dk_ellipse_array_h

#include <stdio.h>
#include "dk_ellipse.h"

// EllipseArray description
typedef struct tagEllipseArray
{
	int number;
	int count;
    Ellipse **ellipses;
}EllipseArray;


// Init/Dealloc 
EllipseArray *createArray(int aNumber);
void freeArray(EllipseArray *anArray);

// interface
// returns index of added element OR -1 if fail
int addElement(EllipseArray *anArray, Ellipse *aEllipse);
void writeArrayToJSON(FILE *aFile, EllipseArray *anArray);

#endif /* dk_ellipse_array_h */
