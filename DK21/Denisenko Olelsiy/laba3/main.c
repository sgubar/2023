#include <stdio.h>
#include "tree.h"

int main(void)
{
	floatTree *tree = createfloatTree();
	insertfloatValueToTree(tree, 53.5);
	insertfloatValueToTree(tree, 43);
	insertfloatValueToTree(tree, 39);
	insertfloatValueToTree(tree, 30);
	insertfloatValueToTree(tree, 14);
	insertfloatValueToTree(tree, 9);
	insertfloatValueToTree(tree, 23);

	insertfloatValueToTree(tree, 35);
	insertfloatValueToTree(tree, 73);
	insertfloatValueToTree(tree, 61);
	insertfloatValueToTree(tree, 56);

	printTree(tree);

	floatNode *node43 = findNodeWithValue(tree, 61);

	if (NULL != node43)
	{
		printNode(node43);
		printf("\n");
	} else {
		printf("The node with request key/value was not found\n");
	}

	deleteNodeWithValue(tree, 30);
	printTree(tree);
 destroyfloatTree(tree);

	return 0;
}
