#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LAB_2.h"


int main(void)
{
	int num_of_words = 0;
	char **array_of_words = NULL;
	printf("\t\t- This program will scan some words from file and after this they will be sorted -\n\n- Opening file ...");
	FILE *file_of_words = fopen("file_of_words.txt", "r");
	check_file(file_of_words);
	printf("\n\n- How many words do you want to scan from file?\n\n- Number of words: ");
	check_value(&num_of_words);
	array_of_words = (char **)malloc(sizeof(char *) * num_of_words);
	for(int i = 0; i < num_of_words; ++i)
		array_of_words[i] = (char *)malloc(sizeof(char) * 32);
	scan_from_file(file_of_words, array_of_words, num_of_words);
	fclose(file_of_words);
	file_of_words = fopen("C:/Users/Wander/Desktop/file_of_words.txt", "w+");
	check_file(file_of_words);
	fputs("Array of your words after bubble sorting:\n\n", file_of_words);
	char **array_of_words_after_bubble_sorting = bubble_sort(array_of_words, num_of_words);
	fflush(stdin);
	for(int i = 0; i < num_of_words; ++i)
		fputs(array_of_words_after_bubble_sorting[i], file_of_words);
	fputs("\n\nArray of your words after insert sorting:\n\n", file_of_words);
	char **array_of_words_after_insert_sorting = insert_sort(array_of_words, num_of_words);
	fflush(stdin);
	for(int i = 0; i < num_of_words; ++i)
		fputs(array_of_words_after_insert_sorting[i], file_of_words);
	fputs("\n\nArray of your words after choice sorting:\n\n", file_of_words);
	char **array_of_words_after_choice_sorting = choice_sort(array_of_words, num_of_words);
	fflush(stdin);
	for(int i = 0; i < num_of_words; ++i)
		fputs(array_of_words_after_choice_sorting[i], file_of_words);
	fclose(file_of_words);
	free(array_of_words);
	free(array_of_words_after_bubble_sorting);
	free(array_of_words_after_insert_sorting);
	free(array_of_words_after_choice_sorting);
	return 0;
}