#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "hometask_2.h"

int check_value_func(void)
{
    int value_of_coordinate;
    int check_result;
     do
    {
        check_result = 0;
        check_result = scanf("%i", &value_of_coordinate);
        fflush(stdin);
        if (check_result != 1)
        {
           printf("\n- Coordinate was not defined by integer value.\n\n- Please try again:\n\n- Your coordinate:");
        }
    }while(check_result != 1);
    return value_of_coordinate;
}

Circle *create_Circle_func(Point *Center, Point *Radius)
{
    Circle *created_Circle = NULL;
    if (NULL != Center && NULL != Radius)
	{
		created_Circle = (Circle *)malloc(sizeof(Circle));
		if (NULL != created_Circle)
		{
			created_Circle->Center = copy_Point_func(Center);
			created_Circle->Radius = copy_Point_func(Radius);
		}
	}
	return created_Circle;
}

Point *copy_Point_func(Point *incomePoint)
{
    Point *copied_Point = (Point*)malloc(sizeof(Point));
    if(NULL != copied_Point)
    {
        copied_Point->x = incomePoint->x;
        copied_Point->y = incomePoint->y;
    }
    return copied_Point;
}

void destroy_Circle_func(Circle *income_Circle)
{
	if (NULL != income_Circle)
	{
		free(income_Circle->Center);
		free(income_Circle->Radius);
		free(income_Circle);
	}
}

float calculating_area_of_Circle_func(Circle *incomeCircle)
{
	float Pi_number = 3.14;
	int Radius_line = pow((incomeCircle->Radius->x - incomeCircle->Center->x), 2) + pow((incomeCircle->Radius->y - incomeCircle->Center->y), 2);
	float area_of_Circle = Pi_number * Radius_line;
	return area_of_Circle;
}

void print_Circle_func(Circle *incomeCircle)
{
    if(NULL != incomeCircle)
    {
        printf("\n- The Circle has two components:\n\n\t- The Center with coordinates:\n\n\t\t X = [%i];\n\n\t\t Y = [%i];\n\n\t- The Radius with coordinates:\n\n\t\t X = [%i];\n\n\t\t Y = [%i];\n\n", incomeCircle->Center->x, incomeCircle->Center->y, incomeCircle->Radius->x, incomeCircle->Radius->y);
    }
}
