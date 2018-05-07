#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include "spysok.h"
#include "work_with_file.h"

void Start_of_work(CharList *Before_Range, CharList *IN_Range, CharList *After_Range);

int Choose_theList();

int choose_check();

void Work_with_list(CharList *theList, int chek);

void find_Node(CharList *alist);

void add_Node(CharList *alist);

void delete_Node(CharList *alist);

void insert_Node(CharList *alist);

void Swap_Place(CharList *alist);

void size_List(CharList *alist);

void sort_List(CharList *alist);

void print_List(CharList *alist);

void delete_Lists(CharList *Before_Range, CharList *IN_Range, CharList *After_Range);

void The_End();

#endif // MENU_H_INCLUDED
