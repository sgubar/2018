//
// Created by dima on 17.05.18.
//

#ifndef HW4_DK_TRIANGLE_ARRAY_H
#define HW4_DK_TRIANGLE_ARRAY_H



#include <stdio.h>
#include "dk_tool.h"

typedef struct tagTriangleArray
{
    int number;
    int count;
    Triangle **triangles;
}TriangleArray;

/*
{
	"number" : (int),
	"count" : (int),
	"lines" :
	[
 		 {
 			"A" : {"x" : (int), "y" : (int)},
		 	"B" : {"x" : (int), "y" : (int)}
		 },
 },
 		{},
 		....
	]
}
*/

// init/dealloc
TriangleArray *createArray(int aNumber);
void freeArray(TriangleArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(TriangleArray *anArray, Triangle *atriangle);
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray);
void insertion_sort(TriangleArray *anArray);
void quickSort(TriangleArray *anArray, int aLeftIndex, int aRightIndex);
int linearSearch(TriangleArray *anArray, float value, int size);

#endif //HW4_DK_TRIANGLE_ARRAY_H
