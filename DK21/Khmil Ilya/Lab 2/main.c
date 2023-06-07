#include <stdio.h>
#include "single_list.h"

int main(int argc, const char * argv[]) {

	IntSingleList *list = createIntSingleList();

	printIntSingleList(list);

	addIntValueToIntSingleList(list, 2);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 4);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 9);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 6);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 2);
	printIntSingleList(list);

	removeFirstElementFromIntSingleList(list);
	printIntSingleList(list);

	removeLastElementFromIntSingleList(list);
	printIntSingleList(list);

	DoubleList(list, 2); 
	printIntSingleList(list);

	deleteIntSingleList(list);
	return 0;
}
