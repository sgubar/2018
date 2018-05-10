#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "hometask_5.h"

int main(void)
{
    printf("\t\t\t\t - Array of Circles -\n\n-Please indicate number of circles by integer value ...\n\n- Your value: ");
    int number_of_Circles = check_value_func();
    Circle_Array *current_Circle_Array = create_Array_func(number_of_Circles);
    Point Center, Radius;
    Circle created_Circle = {&Center, &Radius};
    for(int i = 0; i < number_of_Circles; ++i)
    {
        printf("\n- Please indicate coordinates for center of your circle ...\n\n- Enter the integer value for coordinate 'X' ...\n\n- Coordinate 'X' = ");
        Center.x = check_value_func();
        printf("\n- Enter the integer value for coordinate 'Y' ...\n\n- Coordinate 'Y' = ");
        Center.y = check_value_func();
        printf("\n- Please indicate coordinates for radius of your circle ...\n\n- Enter the integer value for coordinate 'X' ...\n\n- Coordinate 'X' = ");
        Radius.x = check_value_func();
        printf("\n- Enter the integer value for coordinate 'Y' ...\n\n- Coordinate 'Y' = ");
        Radius.y = check_value_func();
        add_Element_to_Array_func(current_Circle_Array, &created_Circle);
    }
    printf("\n- You have next values to find: ");
    for(int i = 0; i < number_of_Circles; ++i)
        printf("%f\t", calculating_Length_and_Area_of_Circle_func(current_Circle_Array->Circles[i], 1));
    printf("\n\n- Please indicate your desired value by float number: ");
    float desired_value = check_value_func();
    line_search(current_Circle_Array, number_of_Circles, desired_value);
    Shell_sorting_func(current_Circle_Array, number_of_Circles);
    FILE *current_File = fopen("C:/Users/Wander/Desktop/scan_file.json", "a+");
    write_Array_to_JSON_func(current_File, current_Circle_Array);
    fflush(current_File);
    fclose(current_File);
    destroy_Array_func(current_Circle_Array);
    return 0;
}
