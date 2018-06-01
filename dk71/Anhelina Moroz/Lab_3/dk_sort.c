#include "dk_sort.h"


void quickSort( char *array, int first, int last)
{
   int left, mid, right;
   
   left = first;
   right = last;
   
   int *array_pointer_left = &array[left];
   int *array_pointer_right = &array[right];
   
   mid = array[(left + right)/2];
   while (left <= right) 
   {
		while (array[left] < mid) left++;
		while (array[right] > mid) right--;
		
		if (left <= right)
		{
			swap (array_pointer_left, array_pointer_right);
			left++;
			right--;
		}
   }
   if (first < right) quickSort(array, first, right);
   
   if (left < last) quickSort(array, left, last);
}
   
   
void swap (int *one, int *two)
{
	int three = *one;
	*one = *two;
	*two = three;
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
    	return -1;
    }
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

void record_to_file(char *array, int size, char *name)
{
	FILE *file;
	file = fopen(name, "w+");
	int i;

	for(i = 0; i < size; i++)
	{
	    fprintf(file,"%c\n", array[i]);
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

