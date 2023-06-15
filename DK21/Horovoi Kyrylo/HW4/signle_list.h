#ifndef SIGNLE_LIST_H_INCLUDED
#define SIGNLE_LIST_H_INCLUDED


#include <stdio.h>

typedef struct single_lists_double_element List_element;

struct single_lists_double_element {
	List_element *next;
	double value;
};

List_element *create_double_list_element(double value);

void delete_double_list_element(List_element *element);

void print_double_list_element(List_element *element);

typedef struct single_list_double {
	List_element *head;
} double_list;

double_list *create_double_list(void);

void delete_double_list(double_list *list);

void print_double_list(double_list *list);

long count_elements(double_list *list);
int add_double_value_to_list(double_list *list, double value);

void remove_first_element_from_list(double_list *list);

void remove_last_element_from_list(double_list *list);
int insert_double_element_to_list_at_index(double_list *list, int index, double value);
int remove_list_element_at_index(double_list *list, int index);


#endif // SIGNLE_LIST_H_INCLUDED
