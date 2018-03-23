#ifndef __DK_TOOL_H
#define __DK_TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
#include <stdint.h>

void bsort(int* x, int len);
void isort(int* x, int len);
void csort(int* x, int len);
void msort(int* x, int len);
int* merge(int* x, int* y, int len1, int len2);
void print_arr(int* x, int len);
int* gen_rand(int len);









#endif










