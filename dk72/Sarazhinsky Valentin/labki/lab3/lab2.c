#include "lab2.h"

int enter_size_array()
{
	int size;
	printf("Enter a size of array(0-2 147 483 647): ");
	scanf("%d", &size);
	printf("You have entered: %d\n", size);
	
	while(size <= 0 || size > 2147483647)
	{
		printf("ERR Invalid size of array:(\nEnter new: ");
		scanf("%d", &size);
		printf("You have entered: %d\n", size);
	}
	return size;
}

void enter_data_to_array(char *array, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(rand()%2 == 1) array[i] = rand()%('z' + 1 - 'a')+'a';
		else array[i] = rand()%('9' + 1 - '0')+'0';	
	}
}

char* loadFile (char* path , int  size) {
  FILE *infile = fopen (path, "r");
  if (infile !=NULL)
    {
    int i = 0;
    char *output_array = malloc (sizeof (char) * (size));
    for (i = 0;i < size;i++)
    {
      fscanf (infile, "%c", &output_array[i]);
    }
    fclose (infile);
    
    return output_array;
  }
  return NULL;
}

void write_array_in_fail(char *aray, int size, char *name)
{
	FILE *file;
	file= fopen(name, "w+");
	int i;
	for(i = 0; i < size; i++)
	{
	    fprintf(file, "%c", aray[i]);

	}

	fclose(file);
}

void sort_bulbashka(char *aray, int size)
{
	int k,i;
  for(k = 0; k < size - 1; k++)
  {
    int swaps = 0;
    for( i = 0; i < size - 1 - k; i++)
      {
        if(aray[i] < aray[i+1])
        {
          int temp = aray[i+1];
          aray[i+1] = aray[i];
          aray[i] = temp;
          swaps++;
        }
      }
    if(!swaps)
      break;
  }
}

void sort_vstavka(char *aray, int size)
{
    char newElement;
    int  location,i;

    for ( i = 1; i < size; i++)
    {
        newElement = aray[i];
        location = i - 1;
        while(location >= 0 && aray[location] < newElement)
        {
            aray[location+1] = aray[location];
            location = location - 1;
        }
        aray[location+1] = newElement;
    }
}

void sort_vybora(char *aray, int size)
{
    char temp;
    int dopomigna,i,j;
    for(i = 0; i < size; ++i)
    {
        dopomigna = i;
        temp = aray[i];
        for(j = i + 1; j < size; ++j)
        {
            if (aray[j] > temp)
            {
               dopomigna = j;
               temp = aray[j];
            }
        }
        aray[dopomigna] = aray[i];
        aray[i] = temp;
    }
}




