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
	printf("This is a binary search tree:\n");
	BST_print(T);

	printf("BST_inorder_walker(BST_node *) prints the nodes' keys in crescent order:\n");
	BST_inorder_walker(T->root);
	
	printf("\nBST_height(BST *) returns the height of the tree:\n");
	uint32_t h = BST_height(T);
	printf("%i\n", h);

	printf("\nBST_maximum(BST *), BST_iterative_maximum(BST *)/BST_minimum(BST *), BST_iterative_minimum(BST *) returns tht node with the smaller/bigger key in the tree:\n");
	BST_node *M = BST_maximum(T);
	BST_node *M_i = BST_iterative_maximum(T);
	BST_node *m = BST_minimum(T);
	BST_node *m_i = BST_iterative_minimum(T);
	printf("%i, %i/%i, %i\nWARNING: if the tree is empty the returned value is NULL.\n\n", M->key, M_i->key, m->key, m_i->key);
	
	printf("BST_successor(BST_node *)/BST_predecessor(BST_node *) returns the node's successor/predecessor:\n");
	BST_node *n = BST_successor(T->root);
	printf("The key of the root's successor node is: %i\n", n->key);
	BST_node *p = BST_predecessor(T->root);
	printf("The key of the root's predecessor node is: %i\n", p->key);
	printf("WARNING: if the tree is empty the returned value is NULL.\n");

	printf("\nBST_search(BST *, uint32_t) and BST_iterative_search(BST *, uint32_t) returns the tree's node wit the wanted key.\n");
	BST_node *found = BST_search(T, 5);
	BST_node *found_i = BST_iterative_search(T, 5);

	printf("\nBST_remove(BST *, BST_node *) removes a node from the tree.\nThis is the previous tree after removing the node with key = 7:\n");
	BST_remove(T, BST_search(T, 7));
	BST_print(T);
	
	printf("BST_insert(BST *, BST_node *) inserts a node with the desired key in the propper position.\nThis is the previous tree after adding a node with key = 8:\n");
	BST_insert(T, 8);
	BST_print(T);

	printf("BST_right_rotate(BST *, BST_node *)/BST_left_rotate(BST *, BST_node *) makes a right/left rotation on a node.\nThis is the previous tree after a right rotation on the node with key = 6:\n");
	BST_right_rotate(T, BST_search(T, 6));
	BST_print(T);
	printf("And this is the previous tree after a left rotation on the node with key = 3:\n\n\n");
	BST_left_rotate(T, BST_search(T, 3));
	BST_print(T);
	
	return 0;
}