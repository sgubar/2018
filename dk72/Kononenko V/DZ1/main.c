#include <stdio.h>
#include <string.h>
#include "dk_tools.h"


int main()
{
    char myString[100];
    for (;;)
    {
    puts("Vvedite stroky ");
    gets(myString);

    printf("Vsevo slov %d\n", word_ct(myString));
}
}
