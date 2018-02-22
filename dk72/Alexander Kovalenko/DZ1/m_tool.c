//
//  m_tool.c
//  dz1
//
//  Created by Alexander Kovalenko on 2/14/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//


#include "m_tool.h"


void swap_elements(int n, int a1[])
{
    int buf,i,k;
    k=n/2 -1;
    for (i=0; i<=k; i++)
    {
      buf=a1[i];
      a1[i]=a1[n-1-i];
      a1[n-1-i]=buf;     
    }
}
