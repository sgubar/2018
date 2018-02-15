#include <stdio.h>
#include <string.h>


int main()
{
    char myString[100];
    for (;;)
    {
    puts("Vvedyte stroku: ");
    gets(myString);

    printf("chislo slov ravno %d\n", word_ct(myString));
}
}
