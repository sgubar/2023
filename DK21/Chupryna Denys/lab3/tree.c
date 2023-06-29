#include "tree.h"

static CharNode *get_successor(CharNode *delete);

CharTree *create_tree()
{
	CharTree *tree_ptr = malloc(sizeof(*tree_ptr));
	if (tree_ptr != NULL) {
		tree_ptr->root = NULL;
	}
	return tree_ptr;
}

void print_node(CharNode *node_ptr)
{
	if (NULL == node_ptr) {
		return;
	}
	print_node(node_ptr->left);
	printf("%c\n", node_ptr->data);
	print_node(node_ptr->right);

}

void print_tree(CharTree *tree_ptr)
{
	CharNode *item = tree_ptr->root;
	print_node(item);
}

void show_node(CharNode *node_ptr)
{
	if (node_ptr == NULL) {
		return;
	}
	printf("data: %c;\n", node_ptr->data);
}

CharNode *create_node(char data)
{
	CharNode *node_ptr = malloc(sizeof(*node_ptr));
	if (node_ptr != NULL) {
		node_ptr->left = NULL;
		node_ptr->right = NULL;
		node_ptr->data = data;
	}
	return node_ptr;
}

void delete_node(CharNode *node_ptr)
{
	if (node_ptr != NULL) {
		delete_node(node_ptr->left);
		delete_node(node_ptr->right);
		free(node_ptr);
	}
}

void delete_tree(CharTree *tree_ptr)
{
	if (tree_ptr != NULL) {
		delete_node(tree_ptr->root);
		free(tree_ptr);
	}
}

void IncertToTree(CharTree *tree_ptr, char data)
{
	if (NULL == tree_ptr) {
		return;
	}
	CharNode *node_ptr = create_node(data);
	if (NULL == node_ptr) {
		return;
	}

	if (NULL == tree_ptr->root) {
		tree_ptr->root = node_ptr;
	} else {
		CharNode *current = tree_ptr->root;
		CharNode *parent = NULL;
		while (1) {
			parent = current;
			if (data < current->data) {
				current = current->left;
				if (NULL == current) {
					parent->left = node_ptr;
					break;
				}
			} else {
				current = current->right;
				if (NULL == current) {
					parent->right = node_ptr;
					break;
				}
			}
		}
	}
}

CharNode *FindNode(CharTree *tree_ptr, char data)
{
	CharNode *current_node = NULL;
	if (NULL != tree_ptr && NULL != tree_ptr->root) {
		current_node = tree_ptr->root;
		while (data != current_node->data) {
			current_node = (data < current_node->data)
				? current_node->left
				: current_node->right;
			if (NULL == current_node) {
				break;
			}
		}
	}
	return current_node;
}

void delete_node_value(CharTree *tree_ptr, char data) {
	if (NULL == tree_ptr || NULL == tree_ptr->root) {
		return;
	}

       	CharNode *current = tree_ptr->root;
	CharNode *parent = tree_ptr->root;

	while (data != current->data) {
		parent = current;
		if (data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}

		if (NULL == current) {
			return;
		}
	}

	if (NULL == current->left && NULL == current->right) {
		if (tree_ptr->root == current) {
			tree_ptr->root = NULL;
		} else if (parent->left == current) {
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}

	} else if (NULL == current->right) {
		if (tree_ptr->root == current) {
			tree_ptr->root = current->left;
		} else if (parent->left == current) {
			parent->left = current->left;
		} else {
			parent->right = current->left;
		}
	} else if (current->left == NULL) {
		if (tree_ptr->root == current) {
			tree_ptr->root = current->right;
		} else if (parent->right == current) {
			parent->right = current->right;
		} else {
			parent->left = current->right;
		}
	} else {
		CharNode *successor = get_successor(current);
		if (tree_ptr->root == current) {
			tree_ptr->root = successor;
		} else if (parent->left == current) {
			parent->left = successor;
		} else {
			parent->right = successor;
		}
		current->left = NULL;
		current->right = NULL;
	}
	if (current != NULL) {
		free(current);
	}
}

CharNode *get_successor(CharNode *delete) {
	CharNode *success_parent = delete;
	CharNode *successor = delete;
	CharNode *current = delete->right;

	while(NULL != current) {
		success_parent = successor;
		successor = current;
		current = current->left;
	}
	if (successor != delete->right) {
		success_parent->right = successor->right;
		successor->right = delete->right;
	}

	successor->left = delete->left;
	return successor;
}
