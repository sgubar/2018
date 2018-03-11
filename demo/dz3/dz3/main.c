//
//  main.c
//  dz3
//
//  Created by Slava Gubar on 3/1/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "dk_line_array.h"

int main(int argc, const char * argv[])
{
	LineArray *theArray = createArray(5);
	
	Point A = {2,3};
	Point B = {4,5};
	Line AB = {&A, &B};
	
	addElement(theArray, &AB);
	
	A.y = 6;
	B.x = 6;
	
	addElement(theArray, &AB);
	
	FILE *theFile = fopen("/Users/sl/Desktop/test.json", "a+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArray(theArray);
	
	// insert code here...
	printf("Hello, World!\n");
	return 0;
}
