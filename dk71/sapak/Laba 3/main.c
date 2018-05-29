#include "sort.h"


#include "sort.h"
#include <stdlib.h>

 
int main()
{
int i;	
 char **p,**n;
char serch[32];
 p = (char**) malloc(5000*sizeof(char*));
 n = (char**) malloc(5000*sizeof(char*));
 for (i=0;i<5000;i++){
	p[i] = (char*) malloc(32);
	n[i] = (char*) malloc(32);
}
FILE *input,*output;
p = scan_file(input,p);
n = quick_sort(p,n);

  printf("enter value :");
  scanf("%s",serch);
  
binary_find(n,serch,output);
      
    
    return 0;
}
