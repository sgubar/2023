#ifndef LIST_H
#define LIST_H

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list();
void add_node(Node *head, int data);
void remove_node(Node *head, int data);
void insert_node(Node *head, int index, int data);
void delete_list(Node *head);
int list_size(Node *head);
void print_list(Node *head);

#endif
