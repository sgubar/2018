#define dz2_h

#include <stdio.h>

// описание точки
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// описание линии
typedef struct tagLine
{
	Point *A;
	Point *B;
}Line;

//описание трапеции
typedef struct tagTrapeze
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Trapeze;

// интерфейс
Line *createLine(Point *A, Point *B);
void destroyLine(Line *aLine);
double areaTrapeze(Trapeze *aTrapeze);
float lenghLine(Line *aLine);
void printLine(Line *aLine);
void printTrapeze(Trapeze *aTrapeze);
void destroyTrapeze(Trapeze *aTrapeze);
Trapeze *createTrapeze(Point *A, Point *B, Point *C, Point *D);


