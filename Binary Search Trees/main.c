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

#include "BST.c"
#include "tree_print.c"

void tree_init(node * root) {

	root->p = NULL;
	root->key = 15;
	root->left = NULL;
	root->right = NULL;

	/*tree_insert(root, 5);
	tree_insert(root, 9);
	tree_insert(root, 2);
	tree_insert(root, 18);
	tree_insert(root, 15);
	tree_insert(root, 19);
	tree_insert(root, 17);
	tree_insert(root, 13);*/
	tree_insert(root, 6);
	tree_insert(root, 18);
	tree_insert(root, 3);
	tree_insert(root, 7);
	tree_insert(root, 17);
	tree_insert(root, 20);
	tree_insert(root, 2);
	tree_insert(root, 4);
	tree_insert(root, 13);
	tree_insert(root, 9);

	tree_insert(root, 10);

}

int main() {
	
	node *root = malloc(sizeof(node));
	tree_init(root);
	
	//inorder_tree_walker(root);
	//uint32_t h = tree_height(root, 0);
	//printf("%i\n", h);

	//tree_print(root);

	//struct node *found = tree_search(root, 5);
	//struct node *found = iterative_tree_search(root, 5);
	//inorder_tree_walker(found);
	
	//node *m = tree_maximum(root);
	//node *m = iterative_tree_maximum(root);
	//node *m = tree_minimum(root);
	//node *m = iterative_tree_minimum(root);
	//if (m!=NULL) printf("%i\n", m->key);
	//else printf("NULL\n");
	
	//node *n = tree_successor(root->left->right);
	//if (n!=NULL) printf("%i\n", n->key);
	//else printf("NULL\n");
	
	//node *p = tree_predecessor(root->left->left);
	//if (p!=NULL) printf("%i\n", p->key);
	//else printf("NULL\n");

	return 0;
}