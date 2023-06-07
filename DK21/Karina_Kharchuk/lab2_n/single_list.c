#include"list.h"
#include<stdio.h>
#include <stdlib.h>

IntSingleList *createIntSingleList(void) {
    	IntSingleList *list = (IntSingleList *)malloc(sizeof(IntSingleList));
    	list->head = NULL;
    	return list;
}

void deleteIntSingleList(IntSingleList *list) {
    	if (NULL == list) {
		return ;
	}

	SingleListIntElement *element = list->head;

	while (element != NULL) {
        	SingleListIntElement *next = element->next;
        	free(element);
        	element = next;
    	}
    	free(list);
}

SingleListIntElement *createSingleListIntElement(int value) {
	SingleListIntElement *element = (SingleListIntElement *)malloc(sizeof(SingleListIntElement));
    	element->value = value;
    	element->next = NULL;
    	return element;
}

void deleteSingleListIntElement(SingleListIntElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntSingleList(IntSingleList *list) {
    	SingleListIntElement *element = list->head;
    	
	while (element != NULL) {
        	printf("%d ", element->value);
        	element = element->next;
    	}
    	printf("\n");
}

int addIntValueToIntSingleList(IntSingleList *list, int value) {
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

void removeDuplicateValues(IntSingleList *list) {
	if (list->head == NULL) {
		return;  // Empty list, nothing to remove
   	}

    	SingleListIntElement *element = list->head;
    
	while (element != NULL) 
	{
        	SingleListIntElement *tmp = element;
        	
		while (tmp->next != NULL) 
		{
            		if (tmp->next->value == element->value) 
			{
				SingleListIntElement *temp = tmp->next;
                		tmp->next = tmp->next->next;
               			deleteSingleListIntElement(temp);
            		} else {
                		tmp = tmp->next;
            			}
        	}
        	
		element = element->next;
    	}
	return;
}
