#ifndef dk_line_h
#define dk_line_h

typedef struct tagPoint
{
	int x;
	int y;
	
}Point;

typedef struct tagTriangle
{
	Point *A;
	Point *B;
	Point *C;
}Triangle;


Triangle *createTriangle(Point *A, Point *B, Point *C);
void destroyTriangle(Triangle *aTriangle);
float squareTriangle(Triangle *aTriangle);
void printTriangle(Triangle *aTriangle);


#endif
