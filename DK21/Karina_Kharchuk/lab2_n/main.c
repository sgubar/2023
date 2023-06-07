#include<stdio.h>
#include"list.h"

int main (int argc, const char *argv[])
{
	IntSingleList *list = createIntSingleList();

    	addIntValueToIntSingleList(list, 26);
    	addIntValueToIntSingleList(list, 15);
    	addIntValueToIntSingleList(list, 3);
    	addIntValueToIntSingleList(list, 26);
    	addIntValueToIntSingleList(list, 3);
    	addIntValueToIntSingleList(list, 33);
    	addIntValueToIntSingleList(list, 33);

    	printf("Your numbers: ");
    	printIntSingleList(list);

    	removeDuplicateValues(list);

    	printf("After remove the same numbers(one of them is left): ");
    	printIntSingleList(list);

    	deleteIntSingleList(list);
	return 0;
}





