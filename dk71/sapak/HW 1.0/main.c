#include <stdio.h>
#include "m_tool.h"


int main()
{
  int i, aa[10]={-5, 2, -4, 1, 2, 0, -3, -8, 5, -2};
  
  for (i=0; i<10; i++)
  {
    printf("%d ",aa[i]);
  }
  printf("\n");

  swap_elements(10,aa);

  for (i=0; i<10; i++)
  {
    printf("%d ",aa[i]);
  }
  printf("\n");
  
  
  return 0;
}
