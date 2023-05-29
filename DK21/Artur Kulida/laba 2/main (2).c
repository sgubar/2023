#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


void swap(struct Node *current);


void addElement(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool swapped = false;
    struct Node* current;
    struct Node* tail = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != tail) {
            if (current->data > current->next->data) {
                swap(current);
                swapped = true;
            }
            current = current->next;
        }
        tail = current;
    } while (swapped);
}


void swap(struct Node *current) {
    int temp = current->data;
    current->data = current->next->data;
    current->next->data = temp;
}


void showList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int getInput(const char* text) {
    int value;
    char input[100];

    while (true) {
        printf("%s", text);
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &value) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
        }
    }

    return value;
}


int main() {
    struct Node* head = NULL;

    int countOfElements = getInput("Enter the count of elements:(use int number) ");

    for (int i = 0; i < countOfElements; ++i) {
        int number = getInput("Enter the number:(use int number) ");
        addElement(&head, number);
    }


    printf("List: ");
    showList(head);
    sortList(head);
    printf("Sorted list: ");
    showList(head);

    return 0;
}
