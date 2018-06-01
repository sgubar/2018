
#ifndef dk_triangle2
#define dk_triangle2

#include <stdio.h>
// Point description
typedef struct tagPoint
{
    int x;
    int y;
}Point;

// Triangle description
typedef struct tagTriangle
{
    Point *A;
    Point *B;
    Point *C;
}Triangle;

// Init interface
Triangle *createTriangle(Point *A, Point *B , Point *C);
void destroyTriangle(Triangle *aTriangle);

float flatTriangle(Triangle *aTriangle);
void writeTriangleToJSON(FILE *aFile, Triangle *atriangle);




#endif
