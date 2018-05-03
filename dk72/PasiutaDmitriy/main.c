#include <stdio.h>

#include <stdio.h>
#include "dk_triangle.h"
#include "dk_triangle_array.h"
#define R 2.5
int main(int argc, const char * argv[])
{
    int k;
    int i;
    int A_x, A_y, B_x, B_y, C_x, C_y;
    TriangleArray *theArray = createArray(5);
    printf("Enter k = ");
    scanf("%d", &k);
    for(i=1; i<=k; i++)
    {
        printf("\n\tEnter %d triangle\n", i);

        enter(&A_x,&A_y);
        enter(&B_x,&B_y);
        enter(&C_x,&C_y);

        Point A = {A_x,A_y};
        Point B = {B_x,B_y};
        Point C = {C_x,C_y};

        Triangle ABC = {&A, &B, &C};

        addElement(theArray, &ABC);
    }
    FILE *theFile = fopen("//home/dima/labs/2_semestr/labs-on-C/Hw3/test.json", "a+");
    // printTriangle(ABC);
    writeArrayToJSON(theFile, theArray);

    fflush(theFile);
    fclose(theFile);

    freeArray(theArray);


    return 0;


}
