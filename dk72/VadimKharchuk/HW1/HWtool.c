//
// Created by vadim on 12.03.2018.
//
#include "HWtool.h"
#include "stdio.h"
void Search(char *str, char *WhatFind)
{
  int CONST =0;
    int i ,j,number = 0;
    int Rezult=0;
    for(i = 0, j = 0; str[i] !='\0'  ; i++, j++)
    {

        if(str[i] == WhatFind[j])
        {
            CONST ++;
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
