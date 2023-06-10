#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
	FloatTree *tree = createFloatTree();
	insertFloatValueToTree(tree, 53);//1
	insertFloatValueToTree(tree, 39);//1
	insertFloatValueToTree(tree, 30);//1
	insertFloatValueToTree(tree, 14);//1
	insertFloatValueToTree(tree, 23);//1
	insertFloatValueToTree(tree, 83);//3
	insertFloatValueToTree(tree, 79);//1
	insertFloatValueToTree(tree, 61);//1
	insertFloatValueToTree(tree, 56);//2 
/*
	insertFloatValueToTree(tree, 97);//1
        insertFloatValueToTree(tree, 113);//1
        insertFloatValueToTree(tree, 98);//1
        insertFloatValueToTree(tree, 111);//1
        insertFloatValueToTree(tree, 112);//3
        insertFloatValueToTree(tree, 99);//1
        insertFloatValueToTree(tree, 110);//1
	
        insertFloatValueToTree(tree, 120);//1
        insertFloatValueToTree(tree, 122);//1
        insertFloatValueToTree(tree, 109);//1

	*/
	printTree(tree);

	FloatNode *node_to_find = findNodeWithValue(tree, 61);

	if (NULL != node_to_find)
	{
		printf("\n");
		printNode(node_to_find);
		printf("\n");
	} else {
		printf("Ноди з таким значенням немає\n");
	}

	deleteNodeWithValue(tree, 61);
	printf("\nПісля видлення\n");

	printTree(tree);

	destroyFloatTree(tree);
	
	return 0;
}
