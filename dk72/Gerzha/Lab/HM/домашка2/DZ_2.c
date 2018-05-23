#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "DZ_2.h"

struct tag_circle *createCircle(void)
{
	struct tag_circle *Circle = (struct tag_circle *) malloc(sizeof(struct tag_circle));
	Circle->radius = createLine();
	Circle->center = Circle->radius->point_A;
	if(Circle != NULL && Circle->radius != NULL)
    {
    	Circle->Area = 0;
        return Circle;
    }else
    {
    	printf("\n\n\n\t- Error -\n\n\t- No memory for circle.");
    	exit(EXIT_FAILURE);
    }
}

struct tag_line *createLine(void)
{
	struct tag_line *Line = (struct tag_line *)malloc(sizeof(struct tag_line));
	Line->point_A = createPoint();
	Line->point_B = createPoint();
	if(Line != NULL && Line->point_A != NULL && Line->point_B != NULL)
    {
        return Line;
    }else
    {
    	printf("\n\n\n\t- Error -\n\n\t- No memory for line.");
    	exit(EXIT_FAILURE);
    }
}

struct tag_point *createPoint(void)
{
	struct tag_point *Point = (struct tag_point *)malloc(sizeof(struct tag_point));
	Point->dot_x = (int *)malloc(sizeof(int));
	Point->dot_y = (int *)malloc(sizeof(int));
	if(Point != NULL && Point->dot_x != NULL && Point->dot_y != NULL)
    {
      	return Point;
    }else
    {
    	printf("\n\n\n\t- Error -\n\n\t- No memory for point.");
    	exit(EXIT_FAILURE);
    }
}

void destroyCircle(struct tag_circle *Circle)
{
	destroyLine(Circle->radius);
    free(Circle);
}

void destroyLine(struct tag_line *Line)
{
	destroyPoint(Line->point_A);
	destroyPoint(Line->point_B);
	free(Line);
}

void destroyPoint(struct tag_point *Point)
{
	free(Point->dot_x);
	free(Point->dot_y);
	free(Point);
}

int checkValidity(void)
{
	int value = 0;
	int result = scanf("%i", &value);
	while(result != 1)
	{
		fflush(stdin);
		printf("\n\t- Incorrect value ...\n\t- Value: ");
		result = scanf("%i", &value);
	}
	return value;
}

void printCircle(struct tag_circle *Circle)
{
	printf("\n\n\n\t- Center point: X - [%i]; Y - [%i]\n\n\t- Point on circle: X - [%i]; Y - [%i]\n\n\t- Area of circle: %f", *(Circle->center->dot_x), *(Circle->center->dot_y), *(Circle->radius->point_B->dot_x), *(Circle->radius->point_B->dot_y), Circle->Area);
}

void calculateArea(struct tag_circle *Circle)
{
	float pi = 3.14;
	float radius = pow((*(Circle->radius->point_B->dot_x) - *(Circle->radius->point_A->dot_x)), 2) + pow((*(Circle->radius->point_B->dot_y) - *(Circle->radius->point_A->dot_y)), 2);
	Circle->Area = pi * radius;
}