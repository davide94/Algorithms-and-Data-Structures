#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "BST.c"
#include "RBT.c"
#include "tree_print.c"

void a_binary_search_tree(BST * T) {

	T->root = NULL;

	BST_insert(T, 15);
	BST_insert(T, 6);
	BST_insert(T, 18);
	BST_insert(T, 3);
	BST_insert(T, 7);
	BST_insert(T, 17);
	BST_insert(T, 20);
	BST_insert(T, 2);
	BST_insert(T, 4);
	BST_insert(T, 13);
	BST_insert(T, 9);
	BST_insert(T, 10);

}

void a_red_black_tree(RBT * T) {

	T->nil = malloc(sizeof(RBT_node));
	T->root = malloc(sizeof(RBT_node));
	
	T->root->key = 11;
	T->root->p = T->nil;
	T->root->left = T->nil;
	T->root->right = T->nil;
	T->root->color = BLACK;
	
	T->nil->p = NULL;
	T->nil->left = NULL;
	T->nil->right = NULL;
	T->nil->color = BLACK;

	
	RBT_insert(T, 2);
	RBT_insert(T, 14);
	RBT_insert(T, 1);
	RBT_insert(T, 7);
	RBT_insert(T, 15);
	RBT_insert(T, 5);
	RBT_insert(T, 8);

}

int main() {
	
	BST *T = malloc(sizeof(BST));
	a_binary_search_tree(T);
	BST_print(T);

	BST_inorder_walker(T->root);
	uint32_t h = tree_height(T->root, 0);
	printf("%i\n", h);

	BST_remove(T, BST_search(T->root, 7));
	BST_print(T);

	BST_right_rotate(T, BST_search(T->root, 6));
	BST_print(T);

	BST_node *found = BST_search(T->root, 5);
	BST_node *found = BST_iterative_search(T->root, 5);
	BST_inorder_walker(found);
	
	BST_node *m = BST_maximum(T->root);
	BST_node *m = BST_iterative_maximum(T->root);
	BST_node *m = BST_minimum(T->root);
	BST_node *m = BST_iterative_minimum(T->root);
	if (m!=NULL) printf("%i\n", m->key);
	else printf("NULL\n");
	
	BST_node *n = BST_successor(T->root->left->right);
	if (n!=NULL) printf("%i\n", n->key);
	else printf("NULL\n");
	
	BST_node *p = BST_predecessor(T->root->left->left);
	if (p!=NULL) printf("%i\n", p->key);
	else printf("NULL\n");

	return 0;
}