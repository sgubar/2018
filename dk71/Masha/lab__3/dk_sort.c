#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_of_(FILE*file)
{
     char*words;
    int j=0;
   file = fopen("some words.txt","r");
	while(!feof(file))
 		{ int res=fscanf(file,"%c",&words);
 			if (res == EOF) break;
 			words++;
 			j++;
 		}
		fclose(file);
return j;
}



void quicksort(char**words,int first,int last)
 {
   int i, j,pivot;

     char temp[32];

   if(first<last)
    {
      pivot=first;
      i=first;
      j=last;

      while(i<j)
        {
         while(strcmp(words[i],words[pivot])<=0&&i<last)
            i++;
         while(strcmp(words[j],words[pivot])>0)
            j--;
         if(i<j)
            {
                strcpy(temp,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],temp);

         }
      }
strcpy(temp,words[pivot]);
strcpy(words[pivot],words[j]);
strcpy(words[j],temp);

      quicksort(words,first,j-1);
      quicksort(words,j+1,last);

   }
}
void print_words(char **aWords)
{
	while(*aWords != NULL)
	{
		printf("%s\n", *aWords);
		aWords++;
	}
}

char **get_words_from_file(FILE *aFile)
{
	char **result = NULL;
	char *buffer = NULL;

	int buffer_size = get_file_size(aFile);
	int number_of_words = 0;

	if (0 == buffer_size)
	{
		return NULL;
	}

	number_of_words ++;

	buffer = (char *)malloc(sizeof(char) * buffer_size);


	for (long i = 0; !feof(aFile); i++)
	{
		buffer[i] = fgetc(aFile);

		if (' ' == buffer[i] || '\n' == buffer[i])
		{
			number_of_words ++;
		}
	}

	result = (char **)malloc(sizeof(char *) * (number_of_words + 1));

	long num_real_words = 0;
	for (long j = 0, w_len = 0; j < buffer_size; j ++)
	{
		if (' ' == buffer[j] || '\n' == buffer[j])
		{
			if (w_len > 0)
			{
				result[num_real_words] = (char *)malloc(sizeof(char) * (w_len + 1));
				strncpy(result[num_real_words], (buffer + (j - w_len)), w_len);
				result[num_real_words][w_len] = '\0';
				num_real_words ++;
			}

			w_len = 0;
		}
		else
		{
			w_len ++;
		}
	}


	result[num_real_words] = NULL;

	free(buffer);

	return result;
}
int the_number_of_words(char*string)
{
int j=1;
while(*string!='\0')
{
    if(*string==' '&&*(string+1)!=' '){
     j++;
    }
        string++;
}
return j;
}

int get_file_size(FILE *aFile)
{
	char*words;
    int j=0;
   aFile = fopen("some words.txt","r");
	while(!feof(aFile))
 		{ int res=fscanf(aFile,"%c",&words);
 			if (res == EOF) break;
 			words++;
 			j++;
 		}
		fclose(aFile);
return j;
}
 int binarysearch(char**words,char*search,FILE *file,char*buffer)
{
    int n = the_number_of_words(buffer);
	int low, high, middle;
    low = 0;
    high = n - 1;

while (low<=high)
 {

    if (strcmp(words[middle],search) <0)
        high = middle + 1;
    if (strcmp(words[middle],search) > 0)
          high = middle - 1;
    else
        return middle;
   }
 return -1;
 }
