#include "lab2.h"

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

void sortirovka(char str[], int count)
{
    for(int i = 0 ; i < count - 1; i++) {

       for(int j = 0 ; j < count - i - 1 ; j++) {
           if((int)str[j] > (int)str[j+1]) {

              char tmp = str[j];
              str[j] = str[j+1] ;
              str[j+1] = tmp;

           }
        }
    }
}

void sortirovka2( char str[],int count)
{
    for (int i = 1; i < count; i++)
    {
        int newElement, location;
        newElement = (int)str[i];
        location = i - 1;
        while(location >= 0 && str[location] > newElement)
        {
            str[location+1] = str[location];
            location = location - 1;
        }
        str[location+1] = newElement;
    }
}


void sortirovka3( char str[],int count)
{
for (int i = 0; i < count ; i++)
    {
        int min = i;
        for (int j = i + 1; j < count ; j++)


            if ((int)str[min] > (int)str[j])
                min = j;
        char tmp = str[min];
        str[min] = str[i];
        str[i] = tmp;
    }
}


