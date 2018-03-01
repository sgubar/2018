#include <stdio.h>
#include "dk_tool.h"

int main()
{
    char word[32];
    char string[1024];
    printf("Enter the sentence\n");
    gets(string);
    printf("Enter the word\n");
    gets(word);
    printf("The number of prestring is %d",lengthofstring(&string,&word));
}

