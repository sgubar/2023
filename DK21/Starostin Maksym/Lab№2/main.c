#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (void) {
    printf("Note, that every value must be integer value!\n");
    int size = 0;
    printf("Enter size of your list: ");
    scanf("%d", &size);

    single_list *list = create_single_list();

    int temp = 0;
    for(int i = 0; i < size; i++) {
        printf("Enter %d value: ", i);
        scanf("%d", &temp);
        addIntValueTosingle_list(list, temp);
    }

    printf("Your list:\n");
    printsingle_list(list);

    float average = findAverageFromsingle_list(list);
    printf("Average value: %f\n", average);

    int i = 1;
    for (SingleListIntElement *element = list->head; element != NULL; element = element->next, i++) {
		if (element->value < average) {
            printf("Element to delete: %d at index %d\n", element->value, i);
			removeIntElementFromsingle_listAtIndex(list, i);
            break;
		}
	}

    printf("Your list:\n");
    printsingle_list(list);

    deletesingle_list(list);
}
