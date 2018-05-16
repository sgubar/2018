#include <stdio.h>
#include "tools.h"

int main() {

    FILE *aFile = fopen("test.txt", "r");

    int check = BracketBallanceCheck(aFile);

    if(check == 1)
    {
        printf("\nBrackets in file didn't match.\n");
    }

    if(check == 0)
    {
        printf("\nAll OK!\n");
    }

    if(check == 2)
    {
        printf("\nFile doesn't exist.\n");
    }

    fclose(aFile);

    return 0;
}
