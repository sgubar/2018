#include "dk_line.h"
#include <stdlib.h>

Point *copyPointWithPoint(Point *aPoint);



Square *createSquare(Point *A, Point *B, Point *C)
{
	Square *theResult = NULL;
	
	if (NULL != A && NULL != B && NULL != C)
	{
		theResult = (Square *)malloc(sizeof(Square));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
		}
	}
	
	return theResult;
}

void destroySquare(Square *aSquare)
{
	if (NULL != aSquare)
	{
		free(aSquare->A);
		free(aSquare->B);
		free(aSquare->C);
		
		free(aSquare);
	}
}

float areaSquare(Square *aSquare)
{
	float theResult = 0.0;
	
	if (NULL != aSquare)
	{
		float dxAB = aSquare->B->x - aSquare->A->x; //2
		float dyAB = aSquare->B->y - aSquare->A->y; //0
		
		float dxBC = aSquare->C->x - aSquare->B->x; //-2
		float dyBC = aSquare->C->y - aSquare->B->y; //2
		printf("x(AB)=%d; y(AB)=%d",dxAB,dyAB);
		float dxAC = aSquare->C->x - aSquare->A->x; //0
		float dyAC = aSquare->C->y - aSquare->A->y; //2
		
		float length_AB = sqrt((dxAB*dxAB) + (dyAB*dyAB)); //2
		float length_BC = sqrt((dxBC*dxBC) + (dyBC*dyBC)); //2*sqrt(2)
		float length_AC = sqrt((dxAC*dxAC) + (dyAC*dyAC)); //2
		float scalar_product_AB_BC = (dxAB*dxBC) + (dyAB*dyBC); //-4
		float scalar_product_AB_AC = (dxAB*dxAC) + (dyAB*dyAC); //0
		float scalar_product_BC_AC = (dxAC*dxBC) + (dyBC*dyBC); //4
		if(scalar_product_AB_BC == 0.0){
			theResult = length_AB*length_BC;	
		} else if(scalar_product_AB_AC == 0.0){
			theResult = length_AB*length_AC;
		} else if(scalar_product_BC_AC == 0.0){
			theResult = length_BC*length_AC;
		} else{
			printf("ERRORthe sides are not perpendicular, the figure can not be square!");
		}
		
	}
	
	return theResult;
}

void printSquare(Square *aSquare)
{
	if (NULL != aSquare)
	{
		printf ("[Square]. A(%d,%d) - B(%d,%d) - C(%d,%d)\n",
					aSquare->A->x,aSquare->A->y,
					aSquare->B->x, aSquare->B->y,
					aSquare->C->x, aSquare->C->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	
	return theResult;
}
