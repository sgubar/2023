#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include"DK_tools.h"
#include"signle_list.h"



int Min(IntSingleList* List) {
	Node* Ptr = List->head;
	int Temp = Ptr->value, Indexmin = 0;
	while (NULL !=Ptr->next) {
		if (Temp > Ptr->next->value) {
			Temp = Ptr->next->value;
			Indexmin++;
		}
		Ptr = Ptr->next;
	}
	return Indexmin;
}

void addlistbf(IntSingleList* list, IntSingleList* list2, int value) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	Node* element = list->head;

	for (int i = 0; i < value; i++)
	{

		addIntValueToIntSingleList(list2, element->value);
		element = element->next;
	}

}

void addlistaf(IntSingleList* list, IntSingleList* list2, int value) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	Node* element = list->head;
	for (int i = 0; i < value; i++)
	{
		element = element->next;
	}
	for (int j; element != NULL; element = element->next) {

		addIntValueToIntSingleList(list2, element->value);
		if (element->next != NULL) {

		}
	}

}

void bubble(IntSingleList* list)
{
	int  swap = 1, tmp;

	for (int j = 0; swap != 0; j++)
	{
		Node* element = list->head;
		if (element->next == NULL)
		{
			break;
		}
		Node* element2 = list->head;
		if (element->next == NULL)
		{
			break;
		}
		element2 = element2->next;

		for (int i = 0; element2 != NULL; i++)
		{

			swap = 0;
			if (element->value > element2->value) {
				tmp = element2->value;
				element2->value = element->value;
				element->value = tmp;
				swap = 1;
			}
			element = element->next;
			element2 = element2->next;


		}
	}
	
}

void collect2list(IntSingleList* list, IntSingleList* list2)
{
	Node* element = list->head;
	for (int i; element != NULL; element = element->next)
	{

		addIntValueToIntSingleList(list2, element->value);

	}


}


