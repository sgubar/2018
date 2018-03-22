//
//  main.c
//  dz2
//
//  Created by Alexander Kovalenko on 3/15/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#include <stdio.h>
#include "dk_ellipse.h"

int main(int argc, const char * argv[])
{
	Point Cntr1 = {50,50};
	int a1 = 40;
    int b1 = 20;
	
	Ellipse *El1 = createEllipse(&Cntr1, &a1, &b1);

	printEllipse(El1);

	printf("The Square of Ellipse = %f\n", SquareEllipse(El1));
	
	destroyEllipse(El1);
	return 0;
}
