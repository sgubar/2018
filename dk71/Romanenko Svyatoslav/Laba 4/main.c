#include "lb_4.h"

int main(void)
{
	ring* aring = CreateRing();
		
	EnterTheData(aring);

	int index = IndexOfMin(aring);
	
	PrintTheRing(aring, index);
	
	DeleteTheRing(aring);
	
	return 0;
}
