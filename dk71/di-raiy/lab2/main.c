#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

int main()
{
  char str [100]= "";
  int count = getfile("C:\\Users\\di_ray\\Desktop\\labaC\\laba2.txt", str);
  printf("%s\n\n", str);
  sortirovka(str, count);// сортируем пузыриком
  printf("%s\n\n", str);
  count = getfile("C:\\Users\\di_ray\\Desktop\\labaC\\laba2.txt", str);
  printf("%s\n\n", str);
  sortirovka2(str, count);// сортируем вставками
  printf("%s\n\n", str);
  count = getfile("C:\\Users\\di_ray\\Desktop\\labaC\\laba2.txt", str);
  printf("%s\n\n", str);
  sortirovka3(str, count); // сортируем выбором
  printf("%s\n\n", str);
  return 0;

}
