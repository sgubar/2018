#include <stdlib.h>
#include "Tree.h"
#include <string.h>






int main()
{ char *a = 'a'; char *b = 'b'; char *c = 'c'; char *d = 'd'; char *e = 'e'; char *f = 'f';

Node *root = NULL;


    insert(&root,f);

    insert(&root,a);

    insert(&root, e);

    insert(&root, c);

    insert(&root, d);

    insert(&root, b);
inOrderTravers(root);


    getch();
}
