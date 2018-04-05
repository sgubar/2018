#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "second_lab_func.h"

char * scan_from_file_func(int array_length)
{
    FILE * scan_file;
    if((scan_file = fopen("C:/Users/dyach/Desktop/scan_file.txt", "rb")) == NULL)
    {
        printf("There are problems with reading from the file ...");
        perror("");
        return NULL;
    }
    char *letters = malloc(array_length * sizeof(char));
    for(int i = 0; i < array_length; ++i)
    {
        letters[i] = getc(scan_file);
    }
    fclose(scan_file);
    return letters;
}

int first_write_to_file_func(int array_length)
{
    FILE * scan_file;
    if((scan_file = fopen("C:/Users/dyach/Desktop/scan_file.txt", "wb")) == NULL)
    {
        perror("");
        return 1;
    }
    printf("\n- Now you must fill your file with the characters (a-z, A-Z)...\n\n- You have to enter %i characters ...\n", array_length);
    for(int i = 0; i < array_length; ++i)
    {
        char letter;
        int check_num = 1;
        while(check_num == 1)
        {
            fflush(stdin);
            printf("\n- Character #%i: ", i);
            scanf("%c", &letter);
            int num_of_letter = letter;
            if(((num_of_letter >= 65) && (num_of_letter <= 90)) || ((num_of_letter >= 97) && (num_of_letter <= 122)))
            {
                check_num = 0;
                putc(letter, scan_file);
            }else
            {
                printf("\n- You have entered an incorrect character ...\n\n- Please try again ...\n");
            }
        }
    }
    fclose(scan_file);
}

char * bubble_sorting_func(char letters[], int array_length)
{
    char * letters_after_bubble_sorting = malloc(array_length * sizeof(char));
    for(int i = 0; i < array_length; ++i)
        letters_after_bubble_sorting[i] = letters[i];
    printf("\n\n- Bubble sorting algorithm is working ...\n\n- Original array order:\n\n");
    for(int i = 0; i < array_length; ++i)
        printf("%c\t", letters[i]);
    long start = 0;
    long end = 0;
    start = GetTickCount();
    for(int i = 0; i <= array_length; ++i)
    {
        for(int j = 0; j < array_length; ++j)
        {
            if(letters_after_bubble_sorting[j] < letters_after_bubble_sorting[j+1])
            {
                char swap_val = letters_after_bubble_sorting[j];
                letters_after_bubble_sorting[j] = letters_after_bubble_sorting[j+1];
                letters_after_bubble_sorting[j+1] = swap_val;
            }
        }
    }
    end = GetTickCount();
    printf("\n\n- Bubble sorting algorithm was continued %f seconds...\n\n- Order of the array after algorithm:\n\n", end - start);
    for(int i = 0; i < array_length; ++i)
        printf("%c\t", letters_after_bubble_sorting[i]);
    printf("\n\n");
    return letters_after_bubble_sorting;
}

char * choice_sorting_func(char letters[], int array_lenght)
{
    char * letters_after_choice_sorting = malloc(array_lenght * sizeof(char));
    for(int i = 0; i < array_lenght; ++i)
        letters_after_choice_sorting[i] = letters[i];
    printf("\n\n- Choice sorting algorithm is working ...\n\n- Original array order:\n\n");
    for(int i = 0; i < array_lenght; ++i)
        printf("%c\t", letters_after_choice_sorting[i]);
    long start = 0;
    long end = 0;
    start = GetTickCount();
    for(int i = 0; i < array_lenght; ++i)
    {
        char max_value = letters_after_choice_sorting[0];
        for(int j = i + 1; j < array_lenght; ++j)
        {
            if(letters_after_choice_sorting[i] < letters_after_choice_sorting[j])
            {
                max_value = letters_after_choice_sorting[j];
                letters_after_choice_sorting[j] = letters_after_choice_sorting[i];
                letters_after_choice_sorting[i] = max_value;
            }
        }
    }
    end = GetTickCount();
    printf("\n\n- Choice sorting algorithm was continued %f seconds...\n\n- Order of the array after algorithm:\n\n", end - start);
    for(int i = 0; i < array_lenght; ++i)
        printf("%c\t", letters_after_choice_sorting[i]);
    printf("\n\n");
    return letters_after_choice_sorting;
}

char * insert_sorting_func(char letters[], int array_length)
{
    char * letters_after_insert_sorting = malloc(array_length * sizeof(char));
    for(int i = 0; i < array_length; ++i)
        letters_after_insert_sorting[i] = letters[i];
    printf("\n\n- Insert sorting algorithm is working ...\n\n- Original array order:\n\n");
    for(int i = 0; i < array_length; ++i)
        printf("%c\t", letters_after_insert_sorting[i]);
    char current_value;
    int the_value_before = 0;
    long start = 0;
    long end = 0;
    start = GetTickCount();
    for(int i = 1; i < array_length; ++i)
    {
        current_value = letters_after_insert_sorting[i];
        the_value_before = i - 1;
        while(the_value_before >= 0 && current_value > letters_after_insert_sorting[the_value_before])
        {
            letters_after_insert_sorting[the_value_before + 1] = letters_after_insert_sorting[the_value_before];
            the_value_before = the_value_before - 1;
        }
        letters_after_insert_sorting[the_value_before + 1] = current_value;
    }
    end = GetTickCount();
    printf("\n\n- Insert sorting algorithm was continued %f seconds...\n\n- Order of the array after algorithm:\n\n", end - start);
    for(int i = 0; i < array_length; ++i)
        printf("%c\t", letters_after_insert_sorting[i]);
    printf("\n\n");
    return letters_after_insert_sorting;
}

int second_write_to_file_func(char letters_after_bubble_sorting[], char letters_after_choice_sorting[], char letters_after_insert_sorting[], int array_length)
{
    FILE * scan_file;
    if((scan_file = fopen("C:/Users/dyach/Desktop/scan_file.txt", "a+b")) == NULL)
    {
        perror("");
        return 1;
    }
    char t = '\t';
    putc(t, scan_file);
    for(int i = 0; i < array_length; ++i)
    {
        putc(t, scan_file);
        putc(letters_after_bubble_sorting[i], scan_file);
    }
    putc(t, scan_file);
    for(int i = 0; i < array_length; ++i)
    {
        putc(t, scan_file);
        putc(letters_after_choice_sorting[i], scan_file);
    }
    putc(t, scan_file);
    for(int i = 0; i < array_length; ++i)
    {
        putc(t, scan_file);
        putc(letters_after_insert_sorting[i], scan_file);
    }
    printf("\n\n- The original array and all results of sorted arrays have been written to your file ...\n\n");
}
