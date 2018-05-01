#ifndef l4_h
#define l4_h


#include "libs.h"

void add_an_data_to_file(char *aadtf_name, int aadtf_amount);

void print_data_from_file(char *pdff_name);

void distribution_of_data_in_file(char *dodif_name, plist dodif_list_b, plist dodif_list_d, plist dodif_list_a, float dodif_min, float dodif_max);

int enter_a_number_of_elements();


#endif