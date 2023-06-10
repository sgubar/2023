#include <stdio.h>
#include "list.h"

int main(void)
{
	FloatList *ListPtr = createFloatList();

	printFloatList(ListPtr);

	addFloatValueToFloatList(ListPtr, 5.23);
	printFloatList(ListPtr);

	addFloatValueToFloatList(ListPtr, 6.12);
	printFloatList(ListPtr);

	insertFloatElementToFloatListAtIndex(ListPtr, 1, 7);
	printFloatList(ListPtr);

	addFloatValueToFloatList(ListPtr, 8.03);
	printFloatList(ListPtr);

	insertFloatElementToFloatListAtIndex(ListPtr, 2, 8);
	printFloatList(ListPtr);

	removeFirstElementFromFloatList(ListPtr);
	printFloatList(ListPtr);

	removeLastElementFromFloatList(ListPtr);
	printFloatList(ListPtr);

	deleteFloatList(ListPtr);
	return 0;
}
