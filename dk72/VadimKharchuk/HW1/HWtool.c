//
//H_W_tool.h
//
//hw1
//
//Created by Vadim Kharhuk on 2/09/18.
//
//Copyright © 2018 Vadim Kharchuk. All rights reserved.

#include "HWtool.h"
#include <stdio.h>
void Seach(char str[])
{
    char strFind[] = "so";
    int k  = strFind[0]+strFind[1];
    int j = 0;
    for (int i=0; str[i] != '\0';i++){
        if(str[i]+str[i+1] == k) {
            j++;
        }
    }
    printf("%d",j);
}