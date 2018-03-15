#include <stdio.h>
#include "dk_elips.h"

int main()
{
    Point A = {-2, 0};//declaring points
    Point B = {0, 1};
    Point C = {2, 0};
    Point D = {0, -1};
    Point middle = {0,0};

    Elips *example = createElips(&A, &B, &C, &D,&middle);

    if(example == NULL)
    {
        printf("An error occurred\n");//if something goes wrong and the elips was not created, we get that message
    }
    else
    {
        printf("Square of elips = %d\n", ElipsArea(example));
    }

    destroyElips(example);
}
