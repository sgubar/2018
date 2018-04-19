#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

int main()
{
  char str [100]= "";
  int count = getfile("C:\\Users\\di_ray\\Desktop\\labaC\\laba3.txt", str);
  printf("%s\n\n", str);
  printf("iskomiy element:\n");
  char znach = '0';
  scanf("%c", &znach);
  printf("%d", Linesearch(str, znach, count));
  sortirovkaShella(str,count);
  printf("\n%s\n\n", str);
  return 0;
}
