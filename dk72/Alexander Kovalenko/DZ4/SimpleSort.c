//
//  SimpleSort.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "SimpleSort.h"
#include "dk_ellipse_array.h"

void swapElements(EllipseArray *anEllipseArray, int anArray[], int l, int m)
{
    int theTmp;
    theTmp=anEllipseArray->ellipses[l]->O->x;
    anEllipseArray->ellipses[l]->O->x=anEllipseArray->ellipses[m]->O->x;
    anEllipseArray->ellipses[m]->O->x=theTmp;
    
    theTmp=anEllipseArray->ellipses[l]->O->y;
    anEllipseArray->ellipses[l]->O->y=anEllipseArray->ellipses[m]->O->y;
    anEllipseArray->ellipses[m]->O->y=theTmp;
    
    theTmp=anEllipseArray->ellipses[l]->a;
    anEllipseArray->ellipses[l]->a=anEllipseArray->ellipses[m]->a;
    anEllipseArray->ellipses[m]->a=theTmp;
    
    theTmp=anEllipseArray->ellipses[l]->b;
    anEllipseArray->ellipses[l]->b=anEllipseArray->ellipses[m]->b;
    anEllipseArray->ellipses[m]->b=theTmp;
    
}


void bubbleSort(EllipseArray *anEllipseArray, int anArray[], int aSize)
{
	for (int theOut = aSize - 1; theOut >= 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
                swapElements(anEllipseArray, anArray, theIn, theIn+1);
			}
		}
	}
}

void selectionSort(int anArray[], int aSize)
{
	for (int theOut = 0; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (int theIn = theOut + 1; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
	
		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}

void insertionSort(int anArray[], int aSize)
{
	for (int theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}
	
		anArray[theIn] = theTmp;
	}
}
