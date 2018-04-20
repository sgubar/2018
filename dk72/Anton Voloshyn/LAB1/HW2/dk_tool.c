#include "dk_tool.h"
	
Triangle *createTriangle(Point *A, Point *B, Point *C)  		
{
    Triangle *theResult = NULL; 								

    if(A != NULL && B != NULL && C != NULL) 					
	{			
     if(abs(A->y) == abs(C->y) && abs(C->x) == abs(B->x)) 		//Check if correct of our figure
        {
            theResult = ( Triangle* )malloc(sizeof(Triangle));  //Allocating memory

            if(theResult != NULL)								
            {
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
            }
        }

    }
    return theResult;
}

void destroyTriangle(Triangle *aTriangle)
{
    if(aTriangle != NULL)			//Checking for valid point
    {
        free(aTriangle->A);			//We are freeing memory
        free(aTriangle->B);
        free(aTriangle->C);
        free(aTriangle);		
    }
}

int AreaOfTriangle(Triangle *aTriangle)
{
    int theResult = 0;

    if(aTriangle != NULL)
    {
        int FirstSide = (float)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        int SecondSide = (float)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));
        
        
		
		
		theResult = (FirstSide * SecondSide) / 2;								//calculation of area of triangle
    }

    return theResult;
}
