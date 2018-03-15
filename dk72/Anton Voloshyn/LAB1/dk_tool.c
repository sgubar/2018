#include "dk_tool.h"
#include "math.h"

 SecondFromSumm(int A)   // Our second conjunction                                  
{
	int SecondValue = 0;
	int D;
   for(D = 0; D <= A; D++)                     
	{
		SecondValue += pow(2,(D+A));    // Now we count the amount of terms from D to A and add thee terms
	}
    return SecondValue;
}

