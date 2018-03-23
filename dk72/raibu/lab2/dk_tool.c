#include "dk_tool.h"


void print_arr(int* x, int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}




void bsort(int* x, int len){
	for (int i = len - 1; i >= 0; i--)
 	{
	    for (int j = 0; j < i; j++)
 		{
			if (x[j] > x[j + 1])
			{
				int tmp = x[j];
				x[j] = x[j + 1]; 
				x[j + 1] = tmp;
			}
		}
	}
  
}



void isort(int* x, int len){
	for(int i=1;i<len;i++){    
		for(int j=i;j>0 && x[j-1]>x[j];j--){
			int tmp = x[j];
			x[j] = x[j - 1];
			x[j - 1] = tmp;
		}
	}
}



void csort(int* x, int len){
	for (int i = 0; i < len-1; ++i)
	{
		int min=i;
		for (int j = 0; j < len; ++j)
		{
			min = (x[min] < x[j])?min:j;
		}
		int tmp = x[i];
		x[i] = x[min];
		x[min] = tmp;
	}
}



void msort(int* x, int len){											//NE RABOTAET
	printf("\n\nsorting array of size %d:\n", len);
	print_arr(x, len);
	if(len==1){
		return;
	}else{
		printf("split into %d and %d len arrays", len/2, len-len/2);

		msort(x,len/2);
		msort(x+len/2,len-len/2);
		printf("merging arrays of len %d and %d:\n", len/2, len-len/2);
		print_arr(x, len/2);
		print_arr(x+len/2, len-len/2);
		memcpy(x,merge(x,x+len/2, len/2, len-len/2),len*sizeof(int));
		printf("merged array:\n");
		print_arr(x,len);
	}

}
 

int* merge(int* x, int* y, int len1, int len2){
	int* m = malloc((len1+len2)*sizeof(int));
	int i=0,j=0, k=0;
	while(i<=len1 && j<=len2){
		m[k] = (x[i]>y[j])? y[j++]:x[i++];
		k++;

	}
	while(i<=len1){
		m[k] = x[i++];
		k++;
	}
	while(j<=len2){
		m[k] = y[j++];
		k++;
	}
	return m;
}
 

int* gen_rand(int len){
	int* m = malloc(sizeof(int)*len);
	if(m==NULL)return NULL;
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
	{
		m[i] = rand()%1000;
	}
	return m;
}

 











