#ifndef dk_sort_h
#define dk_sort_h
char **get_words_from_file(FILE *aFile);
int get_file_size(FILE *aFile);
void print_words(char **aWords);
void quicksort(char**words,int first,int last);
int the_number_of_words(char*string);
int binarysearch(char**words,char*search,FILE *file,char*buffer);
#endif
