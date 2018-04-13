#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "third_lab.h"

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

void quick_sort_func(char * letters, int first, int last)
{
	int first_element_num = first;
	int last_element_num = last;
	int middle_element_key = letters[(first_element_num + last_element_num) / 2];
    do
	{
		while(letters[first_element_num] > middle_element_key)
			first_element_num++;
		while(letters[last_element_num] < middle_element_key)
			last_element_num--;
		if(first_element_num <= last_element_num)
		{
			char swap = letters[first_element_num];
			letters[first_element_num] = letters[last_element_num];
			letters[last_element_num] = swap;
			first_element_num++;
			last_element_num--;
		}
	}while(first_element_num < last_element_num);
	if(first < last_element_num)
		quick_sort_func(letters, first, last_element_num);
	if (first_element_num < last)
        quick_sort_func(letters, first_element_num, last);
}

void line_search(char * letters, int array_length)
{
    int vl_rslt = 0;
    char desired_character;
    int num_of_desired_characters = 0;
    printf("\n- Please enter your desired character ...\n\n- Desired character: ");
     do
    {
        fflush(stdin);
        vl_rslt = 0;
        vl_rslt = scanf("%c", &desired_character);
        if (vl_rslt != 1)
        {
           printf("\n- You have entered not character.\n\n- Please try again:\n\n- Desired character:");
        }
    }while(vl_rslt != 1);
    printf("\n");
    for(int i = 0; i < array_length; i++)
        printf("\t%c", letters[i]);
    printf("\n");
    for(int i = 0; i < array_length; i++)
    {
        if(desired_character == letters[i])
        {
            printf("\n- Your desired character is situated in sorted array on position: %d\n\n", i+1);
            num_of_desired_characters++;
        }
    }
    if(num_of_desired_characters == 0)
    {
        printf("\n- There are no characters in this array which you desire ...\n");
    }else
    {
        printf("- Number of desired characters: %d", num_of_desired_characters);
    }
}



int second_write_to_file_func(char * letters, int array_length)
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
        putc(letters[i], scan_file);
    }
    printf("\n\n- The original array and all results of sorted array have been written to your file ...\n\n");
}
