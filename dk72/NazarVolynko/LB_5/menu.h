#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include "tree.h"
#include <windows.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>

void GetXY (COORD *coord);
void SetCharXY (int x , int y , char c);
int menu1 ();
void insert_Node(IntTree *aTree);
void find_Node(IntTree *aTree);
void delete_Node(IntTree *aTree);
void print_Tree(IntTree *aTree);
void size_Tree_(IntTree *aTree);
void delete_Tree(IntTree *aTree);
void The_End();

#endif // MENU_H_INCLUDED
