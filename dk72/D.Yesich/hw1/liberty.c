#include "liberty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos_of_word(char *string)
{   int i;
    int len = strlen(string);
    for(i=0;i<len;i++)
    {
        if(string[i]=='f')
        {
           if(string[i+1]=='o')
           {
            if(string[i+2]=='x')
            {
               printf("the word fox is located after the %d rd(th) letter",i);
               return i;
            }
        else
            return -1;

             }
        else
            return -1;
        }
     }
}

