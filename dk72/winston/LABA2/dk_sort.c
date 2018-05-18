#include "dk_sort.h"

void buble_sort(char *aray, int size)
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
          aray[i] = swaps;
          swaps++;
        }
      }
    if(!swaps)
      break;
  }
}

void insert_sort(char *aray, int size)
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

void selection_sort(char *aray, int size)
{
    char temp;
    int location;
    for(int i = 0; i < size; ++i)
    {
        location = i;
        temp = aray[i];
        for(int j = i + 1; j < size; ++j)
        {
            if (aray[j] < temp)
            {
               location = j;
               temp = aray[j];
            }
        }
        aray[location] = aray[i];
        aray[i] = temp;
    }
}

int GetCharsAmoutInFile (FILE* file)
{
  int size = 0;
  if (file != NULL) {
    fseek (file, 0, SEEK_END);
    size = ftell (file);
    fseek (file, 0, SEEK_SET);
    return size-1;
  }
  else
    {
    return -1;
    }
}

int GetLetterAmoutInFile (FILE* file)
 {
  int size = 0, i=0;
  char value;
  int _size = GetCharsAmoutInFile (file);
  fseek(file, 0L, SEEK_SET);
  if (file != NULL)
    {
    for(i = 0;i < _size ; i++)
    {
      fscanf (file, "%c", &value);

      if(value>='A' && value<='Z')
      {
          size++;
      }
      if(value>='a' && value<='z')
      {
          size++;
      }
    }
     return size-1;
    }
    else
    {
    return -1;
    }
}

char* loadFile (char * path , int  *size)
{
  FILE *infile = fopen (path, "r");
  if (infile !=NULL)
    {
    int _size = GetCharsAmoutInFile (infile);
    fseek(infile, 0L, SEEK_SET);
    int size_ = GetLetterAmoutInFile (infile);
    fseek(infile, 0L, SEEK_SET);
    int i = 0, k=0;
    char value;
    char * c = malloc (sizeof (char) * size_);
    for (i = 0;i < _size; i++)
    {
      fscanf (infile, "%c", &value);

      if(value>='A' && value<='Z')
      {
          c[k] = value;
          k++;
      }
      if(value>='a' && value<='z')
      {
          c[k] = value;
          k++;
      }
    }
    fclose (infile);
    *size = size_;

    return c;
  }
  return NULL;
}

void record_to_file(char *aray, int size, char *name)
{
	FILE *file;
	file= fopen(name, "w+");

	for(int i = 0; i < size; i++)
	{

	    fprintf(file,"%c\n", aray[i]);

	}

	fclose(file);
}

void output_of_the_array(char* x, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", x[i]);
	}
	printf("\n");
}
