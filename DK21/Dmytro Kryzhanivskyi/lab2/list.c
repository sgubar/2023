#include "list.h"
#include <strings.h>
#include <string.h>

Node *CreateNode(int data)
{
	Node *result = malloc(sizeof(*result));

	if (result != NULL) {
		memset(result,0, sizeof(*result));
		result->data = data;
		result->next = NULL;
		result->prev = NULL;
	}
	return result;
};

void DeleteItem(Node *item)
{
	if (NULL != item) {
		free(item);
	}
}

void PrintItem(Node *item)
{
	if (item != NULL) {
		printf("%d ", item->data);
	}
}


List *CreateList(void)
{
	List *result = malloc(sizeof(*result));

	if (result != NULL) {
		result->head = NULL;
		result->tail = NULL;
	}

	return result;
}

void DeleteList(List *list)
{
	if (list == NULL) {
		return;
	}
	Node *item = list->head;
	while (item != NULL) {
		Node *tmp = item->next;
		DeleteItem(item);
		item = tmp;
	}
	free(list);
}

void PrintList(List *list)
{
	if (list == NULL) {
                printf("Invalid a pointer to the list\n");
		return;
	}

	 Node *item = list->head;

	while (item != NULL)  {
	       	PrintItem(item);
		item = item->next;
	}
}
int AddValueToList(List *list, int data)
{
	if (list == NULL) {
		return 0;
	}
	Node *item = CreateNode(data);
	if (item == NULL) {
		return 0;
	}
	if (list->head == NULL) {
		list->head = item;
		list->tail = list->head;
		return 1;
	}
	list->tail->next = item;
	item->prev = list->tail;
	list->tail = item;
	return 1;
}

void SortAfterMin(List *list) {
	if (list == NULL || list->head == NULL) {
	       	return;
	}

	Node *min_node = list->head;
	Node *current = list->head->next;
	while (current != NULL) {
		if (current->data < min_node->data) {
			min_node = current;
		}
		current = current->next;
	}
	printf("min_value = %d\n", min_node->data );
	Node *after_min_node = min_node->next;

	  while (after_min_node != NULL) {
	    Node *j = after_min_node->next;
	    while (j != NULL) {
	      if (after_min_node->data > j->data) {
		int temp = after_min_node->data;
		after_min_node->data = j->data;
		j->data = temp;
	      }
	      j = j->next;
	    }
	    after_min_node = after_min_node->next;
	  }
}

