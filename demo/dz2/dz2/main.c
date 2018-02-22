//
//  main.c
//  dz2
//
//  Created by Slava Gubar on 2/15/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "dk_line.h"

int main(int argc, const char * argv[])
{
	Point A = {2,3};
	Point B = {4,6};
	
	Line *AB = createLine(&A, &B);

	printLine(AB);

	printf("The length of Line AB = %f\n", lenghLine(AB));
	
	// insert code here...
	printf("Hello, World!\n");

	destroyLine(AB);
	return 0;
}
