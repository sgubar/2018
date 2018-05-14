//
// Created by Ihor on 12.03.2018.
//

#include "dk_rectangle.h"

Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D) //function which returns pointer to rectangle created on given points
{
    Rectangle *theResult = NULL; //declaring resulting pointer, its points to nowhere now

    if(A != NULL && B != NULL && C != NULL && D != NULL) //validations of pointers
    {
        if(A->y == B->y && C->y == D->y && A->x == D->x && B->x == C->x) //checking for the correctness of the figure
        {
            theResult = ( Rectangle* )malloc(sizeof(Rectangle));//allocating memory for the size of the structure with the data

            if(theResult != NULL)//checking for proper allocation of memory
             {
                theResult->A = copyPointWithPoint(A);
                theResult->B = copyPointWithPoint(B);
                theResult->C = copyPointWithPoint(C);
                theResult->D = copyPointWithPoint(D);
            }
        }

    }

    return theResult;
}

void destroyRectangle(Rectangle *aRectangle)
{
    if(aRectangle != NULL)//validation of the pointer
    {
        free(aRectangle->A);//freeing the memory occupied by each point
        free(aRectangle->B);
        free(aRectangle->C);
        free(aRectangle->D);

        free(aRectangle);//freeing memory occupied by whole structure
    }
}

int rectangleArea(Rectangle *aRectangle)
{
    int theResult = 0;

    if(aRectangle != NULL)//validation of pointer
    {
        int aSide = (int)sqrt(pow(aRectangle->B->x - aRectangle->A->x, 2)+pow(aRectangle->B->y - aRectangle->A->y ,2));
        int bSide = (int)sqrt(pow(aRectangle->D->x - aRectangle->A->x, 2)+pow(aRectangle->D->y - aRectangle->A->y ,2));
        theResult = aSide * bSide;//calculation of area of rectangle
    }

    return theResult;
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

void writePointToJSON(FILE *aFile, Point *aPoint)
{
    if (NULL == aPoint || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeRectangleToJSON(FILE *aFile, Rectangle *aRectangle)
{
    if (NULL == aRectangle|| NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\t\"A\" : ");
    writePointToJSON(aFile, aRectangle->A);
    fprintf(aFile, ", \n\t\"B\" : ");
    writePointToJSON(aFile, aRectangle->B);
    fprintf(aFile, ", \n\t\"C\" : ");
    writePointToJSON(aFile, aRectangle->C);
    fprintf(aFile, ", \n\t\"D\" : ");
    writePointToJSON(aFile, aRectangle->D);
    fprintf(aFile, "\n}");
}

