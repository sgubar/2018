#ifndef LAB5_V10_H_INCLUDED
#define LAB5_V10_H_INCLUDED
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

typedef struct tag_tnode tnode;
typedef struct tag_tnode 
{
char *word;
int count; 
tnode *left;
tnode *right; 
}tnode;

void treeprint(tnode *p) ;
void freemem(tnode *tree) ;
tnode *addtree(tnode *p, char *w);
void treeprint2(tnode *p) ;

#endif // LAB5_V10_H_INCLUDED
