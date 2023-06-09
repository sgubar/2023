#include <stdio.h>
#include "tree.h"

int main(void) {
	CharTree *tree = createCharTree();
	insertCharValueToTree(tree, '5');
	insertCharValueToTree(tree, '3');
	insertCharValueToTree(tree, '9');
	insertCharValueToTree(tree, '0');
	insertCharValueToTree(tree, '4');
	insertCharValueToTree(tree, '8');
	insertCharValueToTree(tree, '3');
	insertCharValueToTree(tree, '6');

	printTree(tree);

	CharNode *node43 = findNodeWithValue(tree, '5');

	if (NULL != node43) {
		printNode(node43);
		printf("\n");
	} else {
		printf("The node with request key/value was not found\n");
	}

	deleteNodeWithValue(tree, '3');
	printTree(tree);
	destroyCharTree(tree);
	return 0;
}
