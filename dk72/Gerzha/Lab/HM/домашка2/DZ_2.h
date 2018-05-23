#ifndef DZ_2
#define DZ_2
#include <stdio.h>

struct tag_point
{
	int *dot_y;
	int *dot_x;
};

struct tag_line
{
	struct tag_point *point_A;
	struct tag_point *point_B;
};

struct tag_circle
{
	struct tag_line *radius;
	struct tag_point *center;
	float Area;
};


struct tag_circle *createCircle(void);
struct tag_line *createLine(void);
struct tag_point *createPoint(void);
int checkValidity(void);
void calculateArea(struct tag_circle *Circle);
void printCircle(struct tag_circle *Circle);
void destroyCircle(struct tag_circle *Circle);
void destroyLine(struct tag_line *Line);
void destroyPoint(struct tag_point *Point);

#endif