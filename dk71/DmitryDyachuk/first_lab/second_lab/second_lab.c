#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "second_lab_func.h"

int main()
{
    int array_length = 0;
    int vl_rslt = 0;
    printf("- Please enter number of characters in your file ...\n\n- Number of characters: ");
     do
    {
        vl_rslt = 0;
        vl_rslt = scanf("%i", &array_length);
        fflush(stdin);
        if (vl_rslt != 1)
        {
           printf("\n- Number of characters was not defined by integer value.\n\n- Please try again:\n\n- Number of characters:");
        }
    }while(vl_rslt != 1);
    if (( vl_rslt = first_write_to_file_func(array_length)) == 1)
    {
        printf("There are problems with writing to the file ...");
        return 1;
    }
    char *letters = scan_from_file_func(array_length);
    if(*letters == NULL)
        return 1;
    char * letters_after_bubble_sorting = bubble_sorting_func(letters, array_length);
    char * letters_after_choice_sorting = choice_sorting_func(letters, array_length);
    char * letters_after_insert_sorting = insert_sorting_func(letters, array_length);
    if (( vl_rslt = second_write_to_file_func(letters_after_bubble_sorting, letters_after_choice_sorting, letters_after_insert_sorting, array_length) == 1))
    {
        printf("There are problems with writing to the file ...");
        return 1;
    }
    return 0;
}
