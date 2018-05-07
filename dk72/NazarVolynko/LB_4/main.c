#include <stdio.h>
#include "spysok.h"
#include "work_with_file.h"
#include "menu.h"

int main()
{
    int check, check_for_list;
    CharList *Before_Range = SLCreateList();
    CharList *IN_Range= SLCreateList();
    CharList *After_Range = SLCreateList();

    Start_of_work(Before_Range, IN_Range, After_Range);

    do
    {
        check_for_list = Choose_theList();

        if(check_for_list != 0)
        check = choose_check();

        switch(check_for_list)
        {

        case 1:
        Work_with_list(Before_Range, check);
        break;

        case 2:
        Work_with_list(IN_Range, check);
        break;

        case 3:
        Work_with_list(After_Range, check);
        break;

        }

	}while(check_for_list != 0);

	delete_Lists(Before_Range, IN_Range, After_Range);

	The_End();

    return 0;
}
