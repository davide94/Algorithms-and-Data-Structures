#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
	uint32_t key;
	struct node *p;
	struct node *left;
	struct node *right;	
} node;

typedef struct tree
{
	struct node *root;	
} tree;

#include "BST.c"
#include "tree_print.c"

void tree_init(tree * T) {

	tree_insert(T, 15);
	tree_insert(T, 6);
	tree_insert(T, 18);
	tree_insert(T, 3);
	tree_insert(T, 7);
	tree_insert(T, 17);
	tree_insert(T, 20);
	tree_insert(T, 2);
	tree_insert(T, 4);
	tree_insert(T, 13);
	tree_insert(T, 9);

	tree_insert(T, 10);

}

int main() {
	
	tree *T = malloc(sizeof(tree));
	tree_init(T);
	
	//inorder_tree_walker(T->root);
	//uint32_t h = tree_height(T->root, 0);
	//printf("%i\n", h);

	tree_print(T->root);
	tree_remove(T, tree_search(T->root, 7));
	tree_print(T->root);

	//struct node *found = tree_search(T->root, 5);
	//struct node *found = iterative_tree_search(T->root, 5);
	//inorder_tree_walker(found);
	
	//node *m = tree_maximum(T->root);
	//node *m = iterative_tree_maximum(T->root);
	//node *m = tree_minimum(T->root);
	//node *m = iterative_tree_minimum(T->root);
	//if (m!=NULL) printf("%i\n", m->key);
	//else printf("NULL\n");
	
	//node *n = tree_successor(T->root->left->right);
	//if (n!=NULL) printf("%i\n", n->key);
	//else printf("NULL\n");
	
	//node *p = tree_predecessor(T->root->left->left);
	//if (p!=NULL) printf("%i\n", p->key);
	//else printf("NULL\n");

	return 0;
}