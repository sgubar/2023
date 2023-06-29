#include "tree.h"

int main(void)
{
	CharTree *treec = create_tree();

        IncertToTree(treec, 'f');
        IncertToTree(treec, 'l');
        IncertToTree(treec, 'G');
        IncertToTree(treec, 'J');
        IncertToTree(treec, 'e');
        IncertToTree(treec, 'r');
        IncertToTree(treec, 'X');
        IncertToTree(treec, 't');
        IncertToTree(treec, 'S');
        IncertToTree(treec, 'o');

        print_tree(treec);

        printf("\n");

	delete_node_value(treec, 'f');


	CharNode *findchar = FindNode(treec, 'b');
	if (findchar != NULL)
    {
		show_node(findchar);
	}
	else
    {
		printf( " node not found\n");
	}
        printf("\n");
        print_tree(treec);
        delete_tree(treec);

	return 0;
}
