#ifndef hometask_2
#define hometask_2
#include <stdio.h>

typedef struct
{
    int x;
    int y;
}Point;

typedef struct
{
    Point *Center;
    Point *Radius;
}Circle;

int check_value_func(void);
Circle *create_Circle_func(Point *Center, Point *Radius);
Point *copy_Point_func(Point *incomePoint);
float calculating_area_of_Circle_func(Circle *incomeCircle);
void print_Circle_func(Circle *incomeCircle);
void destroy_Circle_func(Circle *income_Circle);

#endif
