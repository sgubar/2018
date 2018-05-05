#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include "spysok.h"

int choose_check();

void find_Node(CharList *alist);

void add_Node(CharList *alist);

void delete_Node(CharList *alist);

void insert_Node(CharList *alist);

void Swap_Place(CharList *alist);

void size_List(CharList *alist);

void sort_List(CharList *alist);

void print_List(CharList *alist);

void delete_List(CharList *alist);

void The_End();


#endif // MENU_H_INCLUDED
