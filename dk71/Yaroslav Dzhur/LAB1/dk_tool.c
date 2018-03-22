#include "dk_tool.h"
#include "math.h"

int P1(int A, int B, int C, float *result)
{
	float FV = 0;
	float denominator;
	denominator = 100 - B - C;
	if (denominator == 0){
	
		printf("Denominator can't be NULL\n");
		return 0;
}
		else
	*result = (A + B + C) / denominator;
	return 1;
}


int P2(int A)                                      //P2  - funciya drugogo dodanku
{
	int SV=0;
	int D;
   for(D = 0; D <= A; D++)                     
	{
		SV += pow(2,(D+A));
	}
    return(SV);
}

