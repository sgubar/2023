#include<stdio.h>
#include<stdlib.h>
#include"DK_tools.h"
#include"signle_list.h"



int main(int argc, const char* argv[]) {
    struct Node* start = NULL;
	IntSingleList* list = createIntSingleList();
	IntSingleList* listbe = createIntSingleList();
	IntSingleList* listaf = createIntSingleList();
	

	addIntValueToIntSingleList(list, 6);
	addIntValueToIntSingleList(list, 5);
	addIntValueToIntSingleList(list, 3);
	addIntValueToIntSingleList(list, 2);
	addIntValueToIntSingleList(list, 22);
	addIntValueToIntSingleList(list, 1);
	addIntValueToIntSingleList(list, 123);
	addIntValueToIntSingleList(list, 11);
	printf("list:");
	
	printIntSingleList(list);

	addlistaf(list,listaf, Min(list));
	addlistbf(list,listbe, Min(list));
	bubble(listaf);
	
	collect2list(listaf,listbe);
	printf("\nsortedlist:");
	printIntSingleList(listbe);
	
	
	
	


}
