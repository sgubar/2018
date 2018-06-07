#include "dk_triangle.h"

Triangle *createTriangle(Point *A, Point *B, Point *C) //function which returns pointer to Triangle created on given points
{
    Triangle *theResult = NULL; //declaring resulting pointer, its points to nowhere now

    if(A != NULL && B != NULL && C != NULL) //validations of pointers
    {
        if(A->x == C->x && C->y == B->y) //checking for the correctness of the figure
        {
            theResult = ( Triangle* )malloc(sizeof(Triangle));//allocating memory for the size of the structure with the data

            if(theResult != NULL)//checking for proper allocation of memory
             {
                theResult->A = copyPointWithPoint(A);
                theResult->B = copyPointWithPoint(B);
                theResult->C = copyPointWithPoint(C);
            }
        }

    }

    return theResult;
}

void destroyTriangle(Triangle *aTriangle)
{
    if(aTriangle != NULL)//validation of the pointer
    {
        free(aTriangle->A);//freeing the memory occupied by each point
        free(aTriangle->B);
        free(aTriangle->C);

        free(aTriangle);//freeing memory occupied by whole structure
    }
}

int TriangleArea(Triangle *aTriangle)
{
    int theResult = 0;

    if(aTriangle != NULL)//validation of pointer
    {
        int aSide = (int)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2)+pow(aTriangle->A->y - aTriangle->C->y ,2));
        int bSide = (int)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2)+pow(aTriangle->B->y - aTriangle->C->y ,2));
        theResult = aSide * bSide;//calculation of area of Triangle
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

void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle)
{
    if (NULL == aTriangle|| NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\t\"A\" : ");
    writePointToJSON(aFile, aTriangle->A);
    fprintf(aFile, ", \n\t\"B\" : ");
    writePointToJSON(aFile, aTriangle->B);
    fprintf(aFile, ", \n\t\"C\" : ");
    writePointToJSON(aFile, aTriangle->C);
    fprintf(aFile, "\n}");
}

