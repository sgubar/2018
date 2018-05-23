#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "dk_tool.h"

int main() {
	double start;
	char str [100]= "";
	int count = read("read.txt", str);
	
	int len = strlen(str);
	
	start = clock();
	quickSort(str, 0, len - 1);
	printf("%s\n", str);
	printf("Time of quick sorting is %.5f sec\n\n", (clock() - start) / CLOCKS_PER_SEC);
	
	int a;
	printf("Input char for search: ");
    scanf("%d", &a);
    
    int k;
    start = clock();
    k = binarySearch(a, str, len);
    if (k != -1)
        printf("The index of the element is %d\n", k);
    else
        printf("The element isn't found!\n");
        printf("Time of binary searching is %.5f sec\n\n", (clock() - start) / CLOCKS_PER_SEC);
}
