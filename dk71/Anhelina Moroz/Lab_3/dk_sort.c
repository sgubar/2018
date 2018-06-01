#include "dk_sort.h"


void quickSort( char *array, int l, int r)
{
   int j;
   if( l < r )
   {
       j = partition( array, l, r);
       quickSort( array, l, j - 1);
       quickSort( array, j + 1, r);
   }
}


int partition( char *array, int l, int r)
{
	int i, j;
	char pivot, temp;

	pivot = array[l];
	i = l; j = r + 1;

	while( 1)
	{
		do ++i; while( array[i] <= pivot && i <= r );
		do --j; while( array[j] > pivot );
		if( i >= j ) break;
		temp = array[i]; 
		array[i] = array[j]; 
		array[j] = temp;
	}
	temp = array[l]; 
	array[l] = array[j]; 
	array[j] = temp;
	return j;
}

int binarysearch(char key, char *array, int size)
{
    int low, high, middle;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (key < array[middle]) high = middle - 1;
        else 
		{
			if (key > array[middle])
            low = middle + 1;
        	else return middle;
    	}
    }
    return -1;
}

int FileSize (FILE* file)
{
	int size = 0;
	if (file != NULL) 
	{
    	fseek (file, 0, SEEK_END);
    	size = ftell (file);
    	fseek (file, 0, SEEK_SET);
    	return size - 1;
	}
	else return -1;
}


char* loadFile (char * path , int  *size)
{
	FILE *infile = fopen (path, "r");
	if (infile !=NULL)
    {
    	int size = FileSize (infile);
    	fseek(infile, 0L, SEEK_SET);
    	int i = 0, k = 0;
    	char value;
    	char * c = malloc (sizeof (char) * size);
    	for (i = 0; i < size; i++)
    	{
			fscanf (infile, "%c", &value);
			if(value >= 'A' && value<='Z')
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
		return c;
	}
	return NULL;
}

void record_to_file(char *aray, int size, char *name)
{
	int i;
	FILE *file;
	file= fopen(name, "w+");
	for(i = 0; i < size; i++)
	{
		fprintf(file,"%c\n", aray[i]);
	}
	fclose(file);
}

void output_of_the_array(char* x, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%c", x[i]);
	}
	printf("\n");
}
