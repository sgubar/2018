#ifndef WORK_WITH_FILE_H_INCLUDED
#define WORK_WITH_FILE_H_INCLUDED

#include <stdio.h>
#include "spysok.h"

void loadFile (char * path, CharList *Before_Range, CharList *IN_Range, CharList *After_Range, char minimum, char maximum);
void Enter_range(char *minimum, char *maximum);

#endif // WORK_WITH_FILE_H_INCLUDED
