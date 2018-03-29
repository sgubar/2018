//
//  dk_tool_array.h
//  dz3
//
//  Created by Vadym Vaskovets on 3/29/18.
//  Copyright © 2018 Vadym Vaskovets. All rights reserved.
//
#include <stdio.h>
#include "dk_tool.h"
#ifndef dk_tool_array
#define dk_triangle_array
	typedef struct tagtriangleArray
		{
			int number, count;
			triangle **triangles;
		}
	triangleArray;


	triangleArray *createArray(int aNumber);
	void freeArray(triangleArray *anArray);
	int addElement(triangleArray *anArray, triangle *atriangle);
	void writeArrayToJSON(FILE *aFile, triangleArray *anArray);
#endif
