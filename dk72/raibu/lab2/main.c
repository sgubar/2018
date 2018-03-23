
#include "dk_tool.h"


 






int main(int argc, char const *argv[])
{
	// int LEN = atoi(argv[1]);
	// struct rusage usage;
	// struct timeval start, end;

	// int* a = gen_rand(LEN);

	// getrusage(RUSAGE_SELF, &usage);
	// start = usage.ru_utime;

	// bsort(a, LEN);

	// getrusage(RUSAGE_SELF, &usage);
 //  	end = usage.ru_utime;
 //  	printf("array of length %d buble sorted in %ld.%0.6ld s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);
 //  	free(a);

 //  	a = gen_rand(LEN);

 //  	getrusage(RUSAGE_SELF, &usage);
	// start = usage.ru_utime;

	// isort(a, LEN);
	
	// getrusage(RUSAGE_SELF, &usage);
 //  	end = usage.ru_utime;
 //  	printf("array of length %d insertion sorted in %ld.%0.6ld s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);
 //  	free(a);

 //  	a = gen_rand(LEN);

 //  	getrusage(RUSAGE_SELF, &usage);
	// start = usage.ru_utime;

	// csort(a, LEN);
	
	// getrusage(RUSAGE_SELF, &usage);
 //  	end = usage.ru_utime;
 //  	printf("array of length %d choice sorted in %ld.%0.6ld s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);

 //  	free(a);


int a[5] = {1,32768, 123456, 7654321, 1000};
msort(a,5); 
print_arr(a,5);



	return 0;
}