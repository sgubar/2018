#include "circle.h"
#include <stdio.h>

int main()
{
    Circle *circle1 = createCircle2(1, 2, 5);
    printCircle(circle1);
    
    destroyCircle(circle1);
    return 0;

}
