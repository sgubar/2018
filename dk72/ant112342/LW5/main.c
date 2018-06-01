#include <stdio.h>
#include <stdlib.h>
#include"dk_tree.h"
#include "menu.h"

int main(void)
{

    char choice;

    DoubleTree *aTree = createDoubleTree();
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a' :  addnumber(aTree);
                break;
            case 'l' :  show_tree(aTree);
                break;
            case 'f' :  findnumber(aTree);
                break;
            case 'n' :  the_number_of_values(aTree);

                break;
            case 'd' :  delete_a_value(aTree);
                break;
            default  :  puts("Switching error");
        }
    }
    destroyDoubleTree(aTree);
    puts("Bye.");

    return 0;
}



