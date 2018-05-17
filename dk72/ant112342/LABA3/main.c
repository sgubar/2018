#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char * argv[])
{
	// insert code here...
	FILE *file = fopen("some words1.txt", "r");

	char **result = get_words_from_file(file);
	char *buffer = NULL;
	long buffer_size = get_file_size(file);
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	int i;
	for ( i = 0; !feof(file); i++)
		buffer[i] = fgetc(file);

int n=the_number_of_words(buffer);

	quicksort(result, 0, n-1);
	print_words(result);
char* string;
printf("Input  string for search: ");
   gets(&string);
   int k = binarysearch(result,string,file,buffer);
    if (k != -1)
    {
        printf("The index of the element is %d\n", k);
    }
    else
        printf("The element isn't found!\n");

	fclose(file);

	char **to_free = result;
	while ((*to_free) != NULL)
	{
		free (*to_free);
		to_free ++;
	}

	free(result);

	return 0;
}
