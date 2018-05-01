#include "l4.h"
#include "libs.h"

int main(void)
{
	
	int num_of_el = enter_a_number_of_elements();
	float min, max;
	
	add_an_data_to_file("1.txt", num_of_el);
	
	plist alist_b = create_list();
	plist alist_d = create_list();
	plist alist_a = create_list();
	
	
	printf("\nData in file\n");
	print_data_from_file("1.txt");
	
	printf("Enter a diapason of numbers:");
	scanf("%f %f", &min, &max);
	
	distribution_of_data_in_file("1.txt", alist_b, alist_d, alist_a, min, max);
	
	printf("Data before diapason:\n");
	print_list(alist_b);
	printf("Data from diapason:\n");
	print_list(alist_d);
	printf("Data after diapason:\n");
	print_list(alist_a);

	delete_list(alist_b);
	delete_list(alist_d);
	delete_list(alist_a);
	
	return 0;
}
