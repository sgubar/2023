#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk21_tool.h"

Character* crtChrctr(char value)
{
    Character* result = (Character*)malloc(sizeof(Character));
    if (NULL != result)
    {
        result->value = value;

        result->next = NULL;
        result->prev = NULL;
    }
    return result;
}

void delChrctr(Character* element)
{
    if (NULL != element)
    {
        free(element);
    }
}

void prntChrctr(Character* element)
{
    if (NULL != element)
    {
        printf("%c", element->value);
    }
}

Row* crtRow(void)
{
    Row* result = (Row*)malloc(sizeof(Row));
    if (NULL != result)
    {
        result->head = NULL;
        result->tail = NULL;

        memset(result, 0, sizeof(Row));
    }

    return result;
}

void delRow(Row* list)
{
    if (NULL == list)
    {
        return;
    }

    Character* element = list->head;

    while (NULL != element)

    {
        Character* tmp = element->next;
        delChrctr(element);
        element = tmp;
    }
    free(list);
}

void prntRvrsRow(Row* list)
{
    if (NULL == list)

    {
        printf("Неправильний вказівник у списку\n");
        return;
    }

    Character* element = NULL;

    for (element = list->tail; element != list->head; element = element->prev)

    {
        prntChrctr(element);
    }

    if (element != NULL)

    {
        prntChrctr(element);
    }
    printf("\n");
}

int addChrctrToRow(Row* list, char value)

{
    if (NULL == list || (list->head == NULL && list->head != list->tail))

    {
        return 0;
    }

    Character* element = crtChrctr(value);

    if (NULL == element)

    {
        return 0;
    }

    if (NULL == list->head)
    {
        list->head = element;
        list->tail = list->head;

        return 1;
    }

    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;

    return 1;
}