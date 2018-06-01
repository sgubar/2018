#ifndef LAB_2
#define LAB_2

void scan_from_file(FILE *income_file, char **array_of_words, int num_of_words);
int check_value(int *variable);
void check_file(FILE *income_file);
char **bubble_sort(char **array_of_words, int num_of_words);
char **insert_sort(char **array_of_words, int num_of_words);
char **choice_sort(char **array_of_words, int num_of_words);
char **copy_array(char **array_of_words, int num_of_words);

#endif