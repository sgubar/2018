#include "Lab5_V10.h"


tnode *addtree(tnode *p, char *w)
{
int cond;
if(p == NULL) 
    {
p = (tnode *)malloc(sizeof(tnode));
p->word = strdup(w);
p->count = 1;
p->left = p->right = NULL;
} else if((cond = strcmp(w, p->word)) == 0)
p->count++;
else if(cond < 0)
p->left = addtree(p->left, w);
else
p->right = addtree(p->right, w);
return p;
}


void freemem(tnode *tree)
{
if(tree!=NULL)
    {
freemem(tree->left);
freemem(tree->right);
free(tree);
    }
}


void treeprint(tnode *p)
{
if(p != NULL)
    {
    treeprint(p->left); 
    printf("%d %s\n", p->count, p->word);
    treeprint(p->right); 
    }
}



void treeprint2(tnode *p)
{
if (p!=NULL) 
{
printf("%d %s\n", p->count, p->word);
treeprint(p->left); 
treeprint(p->right); 
}
}
