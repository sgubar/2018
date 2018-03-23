
#include "dk_tool.h"


 






int main(int argc, char const *argv[])
{
	if(argc != 3){
		printf("usage : ./main <num> <file>\n");
	}
	FILE* fp = fopen(argv[2], "w");

	int LEN = atoi(argv[1]);
	struct rusage usage;
	struct timeval start, end;

	int* a = gen_rand(LEN);

	getrusage(RUSAGE_SELF, &usage);
	start = usage.ru_utime;

	bsort(a, LEN);

	getrusage(RUSAGE_SELF, &usage);
  	end = usage.ru_utime;
  	fprintf(fp,"array of length %d buble sorted in %lu.%0.6lu s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);
  	free(a);

  	a = gen_rand(LEN);

  	getrusage(RUSAGE_SELF, &usage);
	start = usage.ru_utime;

	isort(a, LEN);
	
	getrusage(RUSAGE_SELF, &usage);
  	end = usage.ru_utime;
  	fprintf(fp,"array of length %d insertion sorted in %lu.%0.6lu s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);
  	free(a);

  	a = gen_rand(LEN);

  	getrusage(RUSAGE_SELF, &usage);
	start = usage.ru_utime;

	csort(a, LEN);
	
	getrusage(RUSAGE_SELF, &usage);
  	end = usage.ru_utime;
  	fprintf(fp,"array of length %d choice sorted in %lu.%0.6lu s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);

  	free(a);

  	



	return 0;
}
