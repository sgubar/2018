#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

int input_matrix(int *matrix, int lines, int columns);
int transponation(int *matrix, int *trans_matrix, int lines, int columns);
int output_matrix(int *trans_matrix, int lines, int columns);

#endif
