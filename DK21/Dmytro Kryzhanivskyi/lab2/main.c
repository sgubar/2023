#include "list.h"
#include <stdio.h>

#define MAX_LIST_SIZE 10

int main(void)
{
    List *list = CreateList();

    printf("Please enter %d integers to add to the list: ", MAX_LIST_SIZE);

    int value;
    for (int i = 0; i < MAX_LIST_SIZE; i++) {
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Error reading input.\n");
            DeleteList(list);
            return 1;
        }
        if (!AddValueToList(list, value)) {
            fprintf(stderr, "Failed to add element to the list.\n");
            DeleteList(list);
            return 1;
        }
    }

    printf("Unsorted list: ");
    PrintList(list);

    SortAfterMin(list);

    printf("\nSorted list: ");
    PrintList(list);
    printf("\n");

    DeleteList(list);
    return 0;
}
