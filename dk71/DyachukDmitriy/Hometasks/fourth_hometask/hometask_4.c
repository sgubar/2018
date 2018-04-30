#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "hometask_4.h"

int check_value_func(void)
{
    int value;
    int check_result;
     do
    {
        check_result = 0;
        check_result = scanf("%i", &value);
        fflush(stdin);
        if (check_result != 1)
        {
           printf("\n- The value was not defined by integer value.\n\n- Please try again:\n\n- Your value:");
        }
    }while(check_result != 1);
    return value;
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

Circle_Array *create_Array_func(int number_of_Circles)
{
    Circle_Array *created_Array_of_Circles = NULL;
    if(number_of_Circles > 0)
    {
        created_Array_of_Circles = (Circle_Array *) malloc(sizeof(Circle_Array));
        if(NULL != created_Array_of_Circles)
        {
            created_Array_of_Circles->Circles = (Circle **) malloc(sizeof(Circle *) * number_of_Circles);
            if(NULL != created_Array_of_Circles->Circles)
            {
                created_Array_of_Circles->number_of_Circles = number_of_Circles;
                created_Array_of_Circles->counter_of_Circles = 0;
            }else
            {
                free(created_Array_of_Circles);
                created_Array_of_Circles = NULL;
            }
        }
    }
    return created_Array_of_Circles;
}
void add_Element_to_Array_func(Circle_Array *current_Circle_Array, Circle *created_Circle)
{
    if(NULL != current_Circle_Array && NULL != created_Circle && current_Circle_Array->counter_of_Circles < current_Circle_Array->number_of_Circles)
    {
        current_Circle_Array->Circles[current_Circle_Array->counter_of_Circles] = create_Circle_func(created_Circle->Center, created_Circle->Radius);
        current_Circle_Array->counter_of_Circles++;
    }
}

void write_Array_to_JSON_func(FILE *current_File, Circle_Array *current_Circle_Array)
{
    if (NULL == current_Circle_Array || NULL == current_File)
    {
        return;
    }

    fprintf(current_File, "{\n\"number of Circles\" : %d,\n\"count of Circles\" : %d,\n",
            current_Circle_Array->number_of_Circles, current_Circle_Array->counter_of_Circles);
    fprintf(current_File, "\"Circles\" : \n[\n");

    for (int i = 0; i < current_Circle_Array->number_of_Circles; i++)
    {
        write_Circle_to_JSON(current_File, current_Circle_Array->Circles[i]);

        if (i < current_Circle_Array->number_of_Circles - 1)
        {
            fprintf(current_File, ",");
        }
        fprintf(current_File, "\n");
    }

    fprintf(current_File, "],\n}");

}

void write_Circle_to_JSON(FILE *current_File, Circle *current_Circle)
{
    if (NULL == current_File || NULL == current_Circle)
    {
        return ;
    }

    fprintf(current_File, "{\n\"Center of Circle\" : ");
    write_Point_to_JSON(current_File, current_Circle->Center);
    fprintf(current_File, ", \n\"Point on Circle\" : ");
    write_Point_to_JSON(current_File, current_Circle->Radius);
    fprintf(current_File, ", \n\"Length of Radius\" : %f", calculating_Length_and_Area_of_Circle_func(current_Circle, 0));
    fprintf(current_File, ", \n\"Area of Circle\" : %f", calculating_Length_and_Area_of_Circle_func(current_Circle, 1));

}

void write_Point_to_JSON(FILE *current_File, Point *current_Point)
{
    if (NULL == current_Point || NULL == current_File)
    {
        return ;
    }

    fprintf(current_File, "{\"X\" : %d, \"Y\" : %d}", current_Point->x, current_Point->y);
}

void destroy_Array_func(Circle_Array *current_Circle_Array)
{
    if(NULL != current_Circle_Array)
    {
        for(int i = 0; i < current_Circle_Array->counter_of_Circles; ++i)
            destroy_Circle_func(current_Circle_Array->Circles[i]);
        free(current_Circle_Array->Circles);
        free(current_Circle_Array);
    }
}

float calculating_Length_and_Area_of_Circle_func(Circle *incomeCircle, int choice)
{
    float Pi_number = 3.14;
    int Radius_line = pow((incomeCircle->Radius->x - incomeCircle->Center->x), 2) + pow((incomeCircle->Radius->y - incomeCircle->Center->y), 2);
    float area_of_Circle = Pi_number * Radius_line;
    if(choice == 1)
    {
        return area_of_Circle;
    }else if(choice == 0)
    {
        return Radius_line;
    }
}

void choice_sorting_func(Circle_Array *current_Circle_Array, int number_of_Circles)
{
    printf("\n\n- Insert sorting algorithm is working ...\n\n- Original array order:\n\n");
    for(int i = 0; i < number_of_Circles; ++i)
        printf("%f\t", calculating_Length_and_Area_of_Circle_func(current_Circle_Array->Circles[i], 1));
    for(int repeat_counter = 0; repeat_counter < number_of_Circles; repeat_counter++)
    {
        Circle *temp = current_Circle_Array->Circles[0];
        for(int element_counter = repeat_counter + 1; element_counter < number_of_Circles; element_counter++)
        {
            if(calculating_Length_and_Area_of_Circle_func(current_Circle_Array->Circles[repeat_counter], 1) > calculating_Length_and_Area_of_Circle_func(current_Circle_Array->Circles[element_counter], 1))
            {
                temp = current_Circle_Array->Circles[repeat_counter];
                current_Circle_Array->Circles[repeat_counter] = current_Circle_Array->Circles[element_counter];
                current_Circle_Array->Circles[element_counter] = temp;
            }
        }
    }
    for(int i = 0; i < number_of_Circles; ++i)
        printf("%f\t", calculating_Length_and_Area_of_Circle_func(current_Circle_Array->Circles[i], 1));
}
