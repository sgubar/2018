#include "dk_tool.h"


void func(int z)
	
	{
	int *a;  
	int i, n, q;

	printf("Enter the size of array: ");
	n = z;
	
	a = (int*)malloc(n * sizeof(int));
	
	for (i = 0; i<n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}


	for (i = 0; i<n / 2; i++)
	{
		q = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = q;
	};



	
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);
	free(a);
	getchar();   getchar();
	return 0;
	}
