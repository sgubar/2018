#include "lab4.h"

int main(void)
{
	list* alist = CreateList();
    
	int amount;
	
	do
	{
		printf("Vvedit kilkist elementiv: ");
		scanf("%d", &amount);
	}while(amount < 1);
	
	int i;
	for( i = 0; i < amount; i++)
	{
		float a;
		scanf("%f", &a);
		AddTheElement(alist, a);
	}
	
	PrintTheList(alist);
	
	DeleteList(alist);
	
	return 0;
}
