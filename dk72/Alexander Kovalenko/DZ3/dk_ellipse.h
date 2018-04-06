//
//  dk_ellipse.h
//  dz3
//
//  Created by Alexander Kovalenko on 2/15/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#ifndef dk_ellipse_h
#define dk_ellipse_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagEllipse
{
	Point *O;
	int a;
    int b;
}Ellipse;

// Init interface
Ellipse *createEllipse(Point *Centre, int *a, int *b);
void destroyEllipse(Ellipse *aEllipse);

float SquareEllipse(Ellipse *aEllipse);
void printEllipse(Ellipse *aEllipse);
void writeEllipseToJSON(FILE *aFile, Ellipse *aEllipse);

#endif /* dk_ellipse_h */
