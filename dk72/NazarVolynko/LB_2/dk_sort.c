#include "dk_sort.h"

void sort_bulbashka(char *aray, int size)
{
  for(int k = 0; k < size - 1; k++)
  {
    int swaps = 0;
    for(int i = 0; i < size - 1 - k; i++)
      {
        if(aray[i] > aray[i+1])
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
    int  location;

    for (int i = 1; i < size; i++)
    {
        newElement = aray[i];
        location = i - 1;
        while(location >= 0 && aray[location] > newElement)
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
    int dopomigna;
    for(int i = 0; i < size; ++i)
    {
        dopomigna = i;
        temp = aray[i];
        for(int j = i + 1; j < size; ++j)
        {
            if (aray[j] < temp)
            {
               dopomigna = j;
               temp = aray[j];
            }
        }
        aray[dopomigna] = aray[i];
        aray[i] = temp;
    }
}

int GetCharsAmoutInFile (FILE* file) {
  int size = 0;
  if (file != NULL) {
    fseek (file, 0, SEEK_END);
    size = ftell (file);
    fseek (file, 0, SEEK_SET);
    return size-1;
  }
  else {
    return -1;
  }
}

char* loadFile (char * path , int  *size) {
  FILE *infile = fopen (path, "r");
  if (infile !=NULL)
    {
    int _size = GetCharsAmoutInFile (infile);
    int i = 0;
    char * c = malloc (sizeof (char) * (_size+1));
    for (int i = 0;i < _size;i++)
    {
      fscanf (infile, "%c", &c[i]);
    }
    fclose (infile);
    c[_size-1]='\0';
    *size = _size;
    return c;
  }
  return NULL;
}

void zapys_sortirovky_v_fajl(char *aray, int size, char *name)
{
	FILE *file;
	file= fopen(name, "w+");

	for(int i = 0; i < size; i++)
	{
	    fprintf(file, "%c\n", aray[i]);

	}

	fclose(file);
}

void vyvod_masiva(char* x, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", x[i]);
	}
	printf("\n");
}
