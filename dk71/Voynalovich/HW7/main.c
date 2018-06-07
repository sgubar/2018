#include <stdlib.h>
#include "My_Tree.h"
#include <string.h>


int main()



{ 

  Node *theTree = NULL;

    insert(&theTree,17);

    insert(&theTree,65);

    insert(&theTree, 37);

    insert(&theTree, 6);

    insert(&theTree, 72);

    insert(&theTree, 8);

     inOrder(theTree);
     deleteValue(theTree, 6);
     inOrder(theTree);
     deleteTree(&theTree);










    getch();



}
