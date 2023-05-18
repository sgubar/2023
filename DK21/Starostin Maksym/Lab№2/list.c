#include "list.h"
#include <stdlib.h>


SingleListIntElement *createSingleListIntElement(int value) {
	SingleListIntElement *result = (SingleListIntElement *)malloc(sizeof(SingleListIntElement));
	if (NULL != result) {
		result->value = value;
		result->next = NULL;
	}
	return result;
}

void deleteSingleListIntElement(SingleListIntElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void prsingle_listIntElement(SingleListIntElement *element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}
//========
single_list *create_single_list(void) {
	single_list *result = (single_list *)malloc(sizeof(single_list));
	if (NULL != result) {
		result->head = NULL;
	}
	return result;
}

void deletesingle_list(single_list *list) {
	if (NULL == list) {
		return ;
	}
	SingleListIntElement *element = list->head;
	while(NULL != element) {
		SingleListIntElement *tmp = element->next;
		deleteSingleListIntElement(element);
		element = tmp;
	}
	free(list);
}

void printsingle_list(single_list *list) {
	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}
	printf("[");
	for (SingleListIntElement *element = list->head; element != NULL; element = element->next) {
		prsingle_listIntElement(element);
		if (element->next != NULL) {
			printf(",");
		}
	}
	printf("]\n");
}

long countOfsingle_list(single_list *list) {
	if (NULL == list) {
 		return 0;
	}
	long count = 0;
	for (SingleListIntElement *element = list->head; element != NULL; element = element->next, count++);
	return count;
}

int addIntValueTosingle_list(single_list *list, int value) {
	if (NULL == list) {
 		return 0;
	}

	SingleListIntElement *element = createSingleListIntElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	SingleListIntElement *tail = list->head;

	while(NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void removeLastElementFromsingle_list(single_list *list) {
	if (NULL == list) {
 		return;
	}
	if (NULL == list->head) {
		return;
	}

	SingleListIntElement *element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		deleteSingleListIntElement(element);
		return;
	}

	while(NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	deleteSingleListIntElement(element->next);
	element->next = NULL;
}

void removeFirstElementFromsingle_list(single_list *list) {
	if (NULL == list) {
 		return;
	}
	if (NULL == list->head) {
		return;
	}

	SingleListIntElement *element = list->head->next;
	deleteSingleListIntElement(list->head);
	list->head = element;
}

int removeIntElementFromsingle_listAtIndex(single_list *list, int index) {
	if (NULL == list) {
 		return 0;
	}

	long count = countOfsingle_list(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromsingle_list(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromsingle_list(list);
		return 1;
	} else {
		int current = 0;
		SingleListIntElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		SingleListIntElement *to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		deleteSingleListIntElement(to_delete);
	}

	return 1;
}



float findAverageFromsingle_list(single_list *list) {
	if (NULL == list) {
 		return 0;
	}
	int sum = 0, i = 0;
	for (SingleListIntElement *element = list->head; element != NULL; element = element->next, i++) {
		sum += element->value;
	}

	return (float)sum / (float)(i);
}
