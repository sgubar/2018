#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LAB_2.h"

void check_file(FILE *income_file)
{
	if(income_file == NULL)
	{
		printf("\n\n- Your file has not opened ...");
		perror("\n\n- Error occured while opening file_of_words.txt:");
		printf("\n\n- Program is closing ...\n\n");
		exit(EXIT_FAILURE);
	}
}

int check_value(int *variable)
{
	int result = scanf("%i", variable);
	while(result != 1)
	{
		fflush(stdin);
		printf("\n\t- Incorrect value ...\n\t- Value: ");
		result = scanf("%i", variable);
	}
}


void scan_from_file(FILE *income_file, char **array_of_words, int num_of_words)
{
	for (int i = 0; i < num_of_words; ++i)
		fgets(array_of_words[i], 32, income_file);
}

char **bubble_sort(char **array_of_words, int num_of_words)
{
    char swap_value[32];
	char **array_of_words_after_bubble_sorting = copy_array(array_of_words, num_of_words);
	for (int i = 0; i < num_of_words ; ++i)
		for (int j = 0; j < num_of_words - 1; ++j)
		{
			if(strcmp(array_of_words_after_bubble_sorting[j], array_of_words_after_bubble_sorting[j + 1]) > 0)
			{
                strcpy(swap_value, array_of_words_after_bubble_sorting[j]);
                strcpy(array_of_words_after_bubble_sorting[j], array_of_words_after_bubble_sorting[j + 1]);
                strcpy(array_of_words_after_bubble_sorting[j + 1], swap_value);
			}
		}
	return array_of_words_after_bubble_sorting;
}

char **copy_array(char **array_of_words, int num_of_words)
{
	char **copied_array = (char **)malloc(sizeof(char *) * num_of_words);
	for(int i = 0; i < num_of_words; ++i)
		copied_array[i] = (char *)malloc(sizeof(char) * 32);
	for (int i = 0; i < num_of_words; ++i)
        strcpy(copied_array[i], array_of_words[i]);
	return copied_array;
}

char **insert_sort(char **array_of_words, int num_of_words)
{
	char swap_value[32];
	char **array_of_words_after_insert_sorting = copy_array(array_of_words, num_of_words);
	for(int i = 1; i < num_of_words; ++i)
	{
		strcpy(swap_value, array_of_words_after_insert_sorting[i]);
		int j = i - 1;
		while(j >= 0 && strcmp(swap_value, array_of_words_after_insert_sorting[j]) < 0)
		{
			strcpy(array_of_words_after_insert_sorting[j + 1], array_of_words_after_insert_sorting[j]);
			strcpy(array_of_words_after_insert_sorting[j], swap_value);
			--j;
		}
	}
	return array_of_words_after_insert_sorting;
}

char **choice_sort(char **array_of_words, int num_of_words)
{
	char swap_value[32];
	char **array_of_words_after_choice_sorting = copy_array(array_of_words, num_of_words);
	for(int i = 0; i < num_of_words; ++i)
	{
		strcpy(swap_value, array_of_words_after_choice_sorting[0]);
		for(int j = i + 1; j < num_of_words; ++j)
		if(strcmp(array_of_words_after_choice_sorting[i], array_of_words_after_choice_sorting[j]) > 0)
		{
			strcpy(swap_value, array_of_words_after_choice_sorting[i]);
			strcpy(array_of_words_after_choice_sorting[i], array_of_words_after_choice_sorting[j]);
			strcpy(array_of_words_after_choice_sorting[j], swap_value);
		}
	}
	return array_of_words_after_choice_sorting;
}