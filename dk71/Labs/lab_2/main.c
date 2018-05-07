#include <stdio.h>
#include "dk_lab2.h"

int main()
{

    int quantity = 0, choice = 0;

    printf("Specify the quantity : ");
    scanf("%d", &quantity);
    while(quantity <= 0)
    {
        printf("Your quantity : ");
        scanf("%d", &quantity);
    }
    int mass[quantity];

    random(mass, quantity);

    Filewriter(mass, quantity, "files.txt");

    printf("Specify the type:\n 1 - Bubble type\n 2 - Select type\n 3 - Insert  type\nYour type: ");

    Type_chooser(mass, quantity, choice);
}
