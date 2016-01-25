
typedef struct RBT_node
{
	uint32_t key;
	struct RBT_node *p;
	struct RBT_node *left;
	struct RBT_node *right;
	enum { BLACK, RED } color;
} RBT_node;

typedef struct RBT
{
	struct RBT_node *root;	
	struct RBT_node *nil;	
} RBT;

void RBT_left_rotate(RBT *T, RBT_node *x) {

	RBT_node *y = x->right;
	x->right = y->left;

	if (y->left != T->nil)
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

void RBT_right_rotate(RBT *T, RBT_node *x) {

	RBT_node *y = x->left;
	x->left = y->right;

	if (y->right != T->nil)
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

void RBT_insert_fixup(RBT *T, RBT_node *x) {
	while (x->p->color == RED) {
		if (x->p == x->p->p->left) {			//	x->p è figlio sinistro
			RBT_node *y = x->p->p->right;
			if (y->color == RED) {				//	zio è rosso 
				x->p->color = BLACK;
				y->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			} else {
				if (x == x->p->right) {			//	zio nero e x figlio destro
					x = x->p;
					RBT_left_rotate(T, x);
				}								//	zio nero e x figlio sinistro
				x->p->color = BLACK;
				x->p->p->color = RED;
				RBT_right_rotate(T, x->p->p);
			}
		} else {								//	x->p è figlio destro
			RBT_node *y = x->p->p->left;
			if (y->color == RED) {
				x->p->color = BLACK;
				y->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			} else {
				if (x == x->p->left) {
					x = x->p;
					RBT_right_rotate(T, x);
				}
				x->p->color = BLACK;
				x->p->p->color = RED;
				RBT_left_rotate(T, x->p->p);
			}
		}
	}
	T->root->color = BLACK;
}

void RBT_insert(RBT *T, uint32_t v) {

	RBT_node *x = T->root;
	RBT_node *y = T->nil;
	
	while (x != T->nil) {	

		y = x;
		if (v < x->key)
			x = x->left;
		else 
			x = x->right;
	}

	RBT_node *new = malloc(sizeof(RBT_node));
	new->key = v;
	new->p = y;
	new->left = T->nil;
	new->right = T->nil;
	new->color = RED;

	if (y == T->nil)
		T->root = new;
	else if (new->key < y->key)
		y->left = new;
	else
		y->right = new;
	RBT_insert_fixup(T, new);
}


