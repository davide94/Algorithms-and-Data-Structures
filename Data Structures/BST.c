
typedef struct BST_node
{
	int32_t key;
	struct BST_node *p;
	struct BST_node *left;
	struct BST_node *right;
} BST_node;

typedef struct BST
{
	struct BST_node *root;	
} BST;

void BST_inorder_walker(BST_node *x) {
	
	if (x != NULL) {
		BST_inorder_walker(x->left);
		printf("%i\n", x->key);
		BST_inorder_walker(x->right);
	}
}

int32_t _BST_height(BST_node *x, int32_t h) {
	
	if (x == NULL)
		return h-1;

	int32_t l = _BST_height(x->left, h+1);
	int32_t r = _BST_height(x->right, h+1);

	if (l < r)
		return r;
	return l;
}

int32_t BST_height(BST *T) {
	return _BST_height(T->root, 0);
}

BST_node *_BST_search(BST_node *x, int32_t key) {

	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return _BST_search(x->left, key);

	return _BST_search(x->right, key);
}

BST_node *BST_search(BST *T, int32_t key) {
	return _BST_search(T->root, key);
}

BST_node *BST_iterative_search(BST *T, int32_t key) {

	BST_node *x = T->root;
	while (x != NULL && x->key != key) {
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

BST_node *_BST_maximum(BST_node *x) {
	
	if (x->right == NULL)
		return x;
	return _BST_maximum(x->right);
}

BST_node *BST_maximum(BST *T) {
	return _BST_maximum(T->root);
}

BST_node *BST_iterative_maximum(BST *T) {
	
	BST_node *x = T->root;
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}

BST_node *_BST_minimum(BST_node *x) {
	
	if (x->left == NULL)
		return x;
	return _BST_minimum(x->left);

}

BST_node *BST_minimum(BST *T) {
	return _BST_minimum(T->root);
}

BST_node *BST_iterative_minimum(BST *T) {
	
	BST_node *x = T->root;
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}

BST_node *BST_successor(BST_node *x) {

	if (x->right != NULL)
		return _BST_minimum(x->right);
	
	BST_node *y = x->p;

	while (y != NULL && x == y->right) {
		x = y;
		y = y->p;
	}
	return x;
}

BST_node *BST_predecessor(BST_node *x) {
	
	if (x->left != NULL)
		return _BST_maximum(x->left);
	
	BST_node *y = x->p;

	while (y != NULL && x == y->left) {
		x = y;
		y = y->p;
	}
	return x;
}

void BST_left_rotate(BST *T, BST_node *x) {

	BST_node *y = x->right;
	x->right = y->left;

	if (y->left != NULL)
		y->left->p = x;
	y->p = x->p;
	if(x == T->root)
		T->root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;

	y->left = x;
	x->p = y;
}

void BST_right_rotate(BST *T, BST_node *x) {

	BST_node *y = x->left;
	x->left = y->right;

	if (y->right != NULL)
		y->right->p = x;
	y->p = x->p;
	if(x == T->root)
		T->root = y;
	else if (x == x->p->right)
		x->p->right = y;
	else
		x->p->left = y;

	y->right = x;
	x->p = y;
}
void BST_insert(BST *T, int32_t v) {

	BST_node *x = T->root;
	BST_node *y = NULL;
	
	while (x != NULL) {	

		y = x;
		if (v < x->key)
			x = x->left;
		else 
			x = x->right;
	}

	BST_node *new = malloc(sizeof(BST_node));
	new->key = v;
	new->p = y;
	new->left = NULL;
	new->right = NULL;

	if (y == NULL)
		T->root = new;
	else if (new->key < y->key)
		y->left = new;
	else
		y->right = new;
}

void BST_remove(BST *T, BST_node *x) {

	if (x->left == NULL) {
		if (x->p->left == x)
			x->p->left = x->right;
		else
			x->p->right = x->right;
	} else if (x->right == NULL) {
		if (x->p->left == x)
			x->p->left = x->left;
		else
			x->p->right = x->left;
	} else {
		BST_node *y = BST_predecessor(x);
		if (T->root == x)
			T->root = y;
		y->p->right = y->left;
		y->right = x->right;
		y->left = x->left;		
		y->p = x->p;
		if (x->p != NULL) {
			if (y->p->left == x)
				y->p->left = y;
			else
				y->p->right = y;
		}
	}
}










