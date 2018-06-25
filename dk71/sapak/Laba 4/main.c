#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    
    FILE *aFile = fopen("/Users/nazarsapak/Documents/Programming/Lab5/Lab5/test.txt", "r");
    
    int check = bracketBallanceCheck(aFile);
    
    if(check == 1)
    {
        printf("\nBrackets in file didn't match.\n");
    }
    
    if(check == 0)
    {
        printf("Brackets in file match:)\n");
    }
    
    if(check == 2)
    {
        printf("\nFile doesn't exist.\n");
    }
    
    fclose(aFile);
    
    return 0;
}
