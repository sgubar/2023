#include <stdio.h>
#include "list.h"

int main() {
    Node *head = create_list();

    int choice;
    int data;
    int index;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Add a node\n");
        printf("2. Remove a node\n");
        printf("3. Insert a node\n");
        printf("4. Delete the list\n");
        printf("5. Get the list size\n");
        printf("6. Print the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &data);
                add_node(head, data);
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &data);
                remove_node(head, data);
                break;
            case 3:
                printf("Enter the index to insert: ");
                scanf("%d", &index);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insert_node(head, index, data);
                break;
            case 4:
                delete_list(head);
                head = NULL;
                printf("List deleted\n");
                break;
            case 5:
                printf("List size: %d\n", list_size(head));
                break;
            case 6:
                printf("Linked List: ");
                print_list(head);
                break;
            case 7:
                delete_list(head);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
