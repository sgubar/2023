#include <stdio.h>
#include "single_list.h"
int main(void) {

	printf("*** TEST SINGLE LINKED LIST *** \n");
	CharSingleList *list = createCharSingleList();

	printCharSingleList(list);

	addCharValueToCharSingleList(list, '5');
	printCharSingleList(list);

	addCharValueToCharSingleList(list, '6');
	printCharSingleList(list);

	addCharValueToCharSingleList(list, '7');
	printCharSingleList(list);

	removeFirstElementFromCharSingleList(list);
	printCharSingleList(list);

	removeLastElementFromCharSingleList(list);
	printCharSingleList(list);

	printf("*** FINISH SINGLE LINKED LIST *** \n");

	deleteCharSingleList(list);
	return 0;
}
