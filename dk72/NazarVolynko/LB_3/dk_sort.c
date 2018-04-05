#include "dk_sort.h"

void shellSort(char *anArray, int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

	//1. Calculate start value of h
	while (theH <= aCount/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter ++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
}

int linijnyj_poshuk(char *array, char key, int size)
{

    for (int i = 1; i <= size; i++)
    {

        if (array[i] == key)
        return i;

    }

    return -1;

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

	    fprintf(file, "%c", aray[i]);

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
