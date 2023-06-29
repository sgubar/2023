#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TREE_H
#define TREE_H


typedef struct node {
	char data;
	struct node *left;
	struct node *right;
} CharNode;

typedef struct tree {
	CharNode *root;
} CharTree;

CharTree *create_tree(void);
CharNode *create_node(char data);

void delete_node(CharNode *node_ptr);
void delete_tree(CharTree *tree_ptr);
void print_node(CharNode *node_ptr);
void print_tree(CharTree *tree_ptr);

void delete_node_value(CharTree *tree_ptr, char data);
void show_node(CharNode *node_ptr);

CharNode *FindNode(CharTree *tree_ptr, char data);
void delete_node_value(CharTree *tree_ptr, char data);
void IncertToTree(CharTree *tree_ptr, char data);

#endif
