#include <stdio.h>
#include "dk_tool.h"

int main()
{
    printf("                              Hello!This is my firs lab,pls do not judge strictly; \n");                    // made by @a_z_0_0_o_o
    printf("                                                Variant 8 (1);\n");
    printf("                                                  by di-raiy:\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                          ________________________ \n");
    printf("                                         |       A * B      B     |\n");         // для красоты
    printf("                                         |  Q = _______ + E    D! |\n");        // ну чисто время убить
    printf("                                         |      B + C^2     D=0   |\n");
    printf("                                         |------------------------|\n");
    printf("\n");
    printf("\n");
    printf(" Input data A, B, C;\n");
    char contin ;
    do
    {
    printf(" Please, enter A : ");
    float A;
    while (!scanf("%f", &A)) {                       //защита от дурака
        while (getchar() != '\n');
        printf(" Input error(enter only numbers)\n try again A: ");
    }
    printf(" Please, enter B : ");
    float B;
    while (!scanf("%f", &B)) {
        while (getchar() != '\n');
        printf(" Input error(enter only numbers)\n try again B: ");
    }
    printf(" Please, enter C : ");
    float C;
    while (!scanf("%f", &C)) {
        while (getchar() != '\n');
        printf(" Input error(enter only numbers)\n try again C: ");
    }
    float result = REsult( A, B, C) ;
    printf("\n");
    printf("\n");
    printf("...and having counted everything we received: %.1f\n", result);
    printf("\n");
    printf("\n");
    printf("\n");
    printf(" Do you want to continue?\ny - yes,any other button - no\n");
    scanf(" %c", &contin);
    }
    while (contin == 'y');
    printf("\n");
    printf("\n");
    printf("So quickly go away?It was nice to work with you)Goodbye!");
    printf("\n");
    printf("\n");
    printf("\n");

            return 0;
}
