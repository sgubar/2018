
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

	quick_sort(a, 0, LEN);
	
	getrusage(RUSAGE_SELF, &usage);
  	end = usage.ru_utime;
  	fprintf(fp,"array of length %d quick sorted in %lu.%0.6lu s\n",LEN, end.tv_sec-start.tv_sec, end.tv_usec - start.tv_usec);
  	int tosearch = rand()%1000;
  	int present = lin_search(a,LEN,tosearch);
  	char s[5];
  	*s=0;
  	if(!present) strcpy(s, "not");
  	printf("value %d %s found in array\n", tosearch, s);
  	free(a);



	return 0;
}
