
#ifndef circle

#define circle





#include <stdio.h>

#include <math.h>









typedef struct tagPoint



{



	int x;

	

	int y;



}Point;





typedef struct tagCircle



{



     Point *Center;
     Point *Radius;


} Circle;







Circle *createCircle(Point *Center , Point *Radius);



void FreeCircle(Circle *aCircle);



void WritePointToJSON(FILE *aFile, Point *aPoint);



float SquareCircle(Circle *aCircle);



void printCircle(Circle *aCircle);



Point *copyPointWithPoint(Point *aPoint);



void writeCircletToJSON(FILE *aFile, Circle *aCircle);









#endif
