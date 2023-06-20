#include <stdio.h>
#include "tree.h"

int main(void)
{
	CharTree *tree = createCharTree();
	insertCharValueToTree(tree, '5');
	insertCharValueToTree(tree, '4');
	insertCharValueToTree(tree, '3');
	insertCharValueToTree(tree, '4');
	insertCharValueToTree(tree, '9');
	insertCharValueToTree(tree, '2');

	insertCharValueToTree(tree, '5');
	insertCharValueToTree(tree, '3');
	insertCharValueToTree(tree, '1');
	insertCharValueToTree(tree, '6');

	printTree(tree);

	CharNode *find_node = findNodeWithValue(tree, '6');
	if (find_node != NULL)
	{
		printNode(find_node);
		printf("\n");
	} else {
		printf("The node with request key/value was not found\n");
	}

	deleteNodeWithValue(tree, '3');
	printTree(tree);

	destroyCharTree(tree);

	return 0;
}
