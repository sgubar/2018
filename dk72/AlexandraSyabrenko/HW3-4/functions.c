#include "functions.h"
#include <stdlib.h>
#include <math.h>

float square(Circle *circle)
{
    float square = 3.14 * pow(circle->radius, 2);
    return square;
}

Circle *createCircle(Point *center , int radius)
{
    Circle *theResult = NULL;
    
    if (center != NULL && radius > 0)
    {
        theResult = (Circle *)malloc(sizeof(Circle));
        if (NULL != theResult)
        {
            theResult->center = copyPointWithPoint(center); //не простий тип данних, того ми маємо скопіювати 
            theResult->radius = radius;
        }
    }
    
    return theResult;
}

Circle *createCircle2(int x, int y, int radius)
{
    
    Point *center = NULL;
    
    
    center = (Point *)malloc(sizeof(Point));
    if (NULL != center)
    {
        center->x=x;
        center->y=y;
    }
    return createCircle(center , radius);
}

void printCircle(Circle *circle)
{
    int radius = circle->radius, x = circle->center->x, y = circle->center->y;
    printf("Radius: %d\nx: %d\ny: %d\nSquare = %.3f\n", radius, x, y, square(circle));
}

void destroyCircle(Circle *aCircle)
{
    if (NULL != aCircle)
    {
        free(aCircle->center);
        free(aCircle);
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

Circle *copyCircleWithCircle(Circle *circle)
{
    Circle* theResult = (Circle *)malloc(sizeof(Circle));
    
    if (NULL != theResult)
    {
        theResult->center = copyPointWithPoint(circle->center);
        theResult->radius = circle->radius;
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

void writeCircleToJSON(FILE *aFile, Circle *aCircle)
{
    if (NULL == aCircle || NULL == aFile)
    {
        return ;
    }
    
    fprintf(aFile, "{\n\"center\" : ");
    writePointToJSON(aFile, aCircle->center);
    
    fprintf(aFile, "{\n\"radius\" : %d", aCircle->radius);
}
