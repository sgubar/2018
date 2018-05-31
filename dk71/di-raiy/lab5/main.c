#include "tree.h"
#include <stdio.h>


int main ()
{
   Node* Tree = createTree(2);
      insElem(Tree, 4);
      insElem(Tree, 1);
      insElem(Tree, 0);
      insElem(Tree, 10);
      insElem(Tree, 24);
      insElem(Tree, 13);



      delElem(Tree, 1);

      printTree(Tree);
    //deleteTree(Tree);
   // printTree(Tree);
   return 1;
}
