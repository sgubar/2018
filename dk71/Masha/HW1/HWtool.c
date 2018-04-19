
#include "HWtool.h"
#include "stdio.h"
void Search(char *WhereFind, char *WhatFind)
{
    int i ,j;
    int Rezult=0;
    for(i = 0, j = 0; WhereFind[i] !='\0'  ; i++, j++)
    {

        if(WhereFind[i] == WhatFind[j])
        {
            if(WhatFind[j+1]== '\0')
                Rezult++;
        }
        else
        {
            j = -1;
        }
    }

    printf("%d",Rezult);
}
