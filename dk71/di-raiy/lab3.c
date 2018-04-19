#include "lab3.h"

int getfile(char mainfile[], char str [] )
{
 FILE *file = fopen(mainfile, "r+");
    if(file == NULL)
    {
       printf("error");
    }

  int count = 0;
  while (!feof(file))
  {
      char temp = fgetc(file);
      if(((int)temp >=48 && (int)temp<=57) || ((int)temp>=97 && (int)temp<=122))
      {
          str[count] = temp;
          count++;
      }
  }
  fclose(file);
  return count;
}

void sortirovkaShella(char str[], int count)
{
    int i, j, step;
    int tmp;
    for (step = count / 2; step > 0; step /= 2)
        for (i = step; i < count; i++)
        {
            tmp = str[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < str[j - step])
                    str[j] = str[j - step];
                else
                    break;
            }
            str[j] = tmp;
        }
}

int Linesearch(char str[], char znach, int count)
{
    int i;
    for (i=0; i<count; i++)
    {
    if (str[i]==znach)
    {
       return i+1;
    }
    }
     return -1;
}




