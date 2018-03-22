#include <stdio.h>
#include <conio.h>
#include "dk_tool.h"
 
int main(void)
{
	int number;
	int base = 2;
	printf("Binary arithmetic: ");
    scanf_s("%d", &number);
	printf("Decimal numerical system : %d", ConvertToDecimal (number, base));

	getch();
	return 0;
}
