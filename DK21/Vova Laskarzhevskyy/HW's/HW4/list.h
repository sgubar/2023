#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
#define LIST_H

typedef struct node {
	double data; 
	struct node *next;
} node_t;

typedef struct single_list {
	node_t *head;
} list_t; 

node_t *create_node(double data);
void delete_node(node_t *node_ptr);
void print_node(node_t *node_ptr);
list_t *create_list(void);
void delete_list(list_t *list_ptr);
void print_list(list_t *list_ptr);
long count_list(list_t *list_ptr);
double add_node2list(list_t *list_ptr, double data);
void del_first_node_list(list_t *list_ptr);
void del_last_node_list(list_t *list);
double add_node2list_by_index(list_t *list_ptr, int index, double data);
double list_del_node_by_index(list_t *list_ptr, int index);


#endif
