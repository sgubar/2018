#ifndef hometask_5
#define hometask_5
#include <stdio.h>

typedef struct creating_Point
{
    int x;
    int y;
}Point;

typedef struct creating_Circle
{
    Point *Center;
    Point *Radius;
}Circle;

typedef struct creating_Circle_Array
{
    int number_of_Circles;
    int counter_of_Circles;
    Circle **Circles;
}Circle_Array;

int check_value_func(void);
Circle *create_Circle_func(Point *Center, Point *Radius);
Point *copy_Point_func(Point *incomePoint);
void destroy_Circle_func(Circle *income_Circle);
Circle_Array *create_Array_func(int number_of_Circles);
void Shell_sorting_func(Circle_Array *current_Circle_Array, int number_of_Circles);
void line_search(Circle_Array *current_Circle_Array, int number_of_Circles);
void add_Element_to_Array_func(Circle_Array *current_Circle_Array, Circle *created_Circle);
void write_Array_to_JSON_func(FILE *current_File, Circle_Array *current_Circle_Array);
void write_Circle_to_JSON(FILE *current_File, Circle *created_Circle);
float calculating_Length_and_Area_of_Circle_func(Circle *incomeCircle, int choice);
void write_Point_to_JSON(FILE *current_File, Point *current_Point);
void destroy_Array_func(Circle_Array *current_Circle_Array);

#endif
