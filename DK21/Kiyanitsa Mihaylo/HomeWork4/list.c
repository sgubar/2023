#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_list() {
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void add_node(Node *head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void remove_node(Node *head, int data) {
    Node *current = head->next;
    Node *previous = head;

    while (current != NULL) {
        if (current->data == data) {
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Element not found in the list\n");
}

void insert_node(Node *head, int index, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    Node *current = head;
    int i = 0;

    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid index\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void delete_list(Node *head) {
    Node *current = head->next;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    free(head);
}

int list_size(Node *head) {
    int size = 0;
    Node *current = head->next;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

void print_list(Node *head) {
    Node *current = head->next;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}
