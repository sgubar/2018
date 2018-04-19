#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "hometask_2.h"

int main(void)
{
    Point Center, Radius;
    printf("\t\t\t\t - Circle -\n\n- Please indicate coordinates for center of your circle ...\n\n- Enter the integer value for coordinate 'X' ...\n\n- Coordinate 'X' = ");
    Center.x = check_value_func();
    printf("\n- Enter the integer value for coordinate 'Y' ...\n\n- Coordinate 'Y' = ");
    Center.y = check_value_func();
    printf("\n- Please indicate coordinates for radius of your circle ...\n\n- Enter the integer value for coordinate 'X' ...\n\n- Coordinate 'X' = ");
    Radius.x = check_value_func();
    printf("\n- Enter the integer value for coordinate 'Y' ...\n\n- Coordinate 'Y' = ");
    Radius.y = check_value_func();
    Circle *created_Circle = create_Circle_func(&Center, &Radius);
    print_Circle_func(created_Circle);
    printf("- The area of Circle using your coordinates = %f\n", calculating_area_of_Circle_func(created_Circle));
    destroy_Circle_func(created_Circle);

    return 0;
}
