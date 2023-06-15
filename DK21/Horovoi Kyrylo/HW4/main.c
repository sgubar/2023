#include <stdio.h>
#include "signle_list.h"

int main(int argc, const char * argv[])
{

	double_list *list = create_double_list();

	print_double_list(list);

	add_double_value_to_list(list, 8.7);
	print_double_list(list);

    add_double_value_to_list(list, 5.8);
	print_double_list(list);
	double a=4.5;
	for(int i=0; i<6; i++, a+=0.8){
        add_double_value_to_list(list, a);
        print_double_list(list);
	}

    insert_double_element_to_list_at_index(list, 4, 43.5);
    print_double_list(list);
	remove_last_element_from_list(list);
	print_double_list(list);
	remove_list_element_at_index(list, 6);
	print_double_list(list);
    printf("Кількість елементів: %ld\n", count_elements(list));
    delete_double_list(list);

        return 0;
}
