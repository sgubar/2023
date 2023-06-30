#include <stdio.h>
#include "signle_list.h"

int main(void)
{
	IntSingleList *list = createIntSingleList();

	printIntSingleList(list);

	addIntValueToIntSingleList(list, 5.23);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 6.112);
	printIntSingleList(list);

	removeFirstElementFromIntSingleList(list);
	printIntSingleList(list);

	removeLastElementFromIntSingleList(list);
	printIntSingleList(list);

	deleteIntSingleList(list);
	return 0;
}
