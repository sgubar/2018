#include "dk_rect.h"

ppoint rect;

int main(void)
{
	
	rect = enter_data();

	print_param(rect);

	deleting(rect);

	return 0;
}
