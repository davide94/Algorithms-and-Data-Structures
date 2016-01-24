int BST_print_t(BST_node *root, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!root) return 0;

	sprintf(b, "(%03d)", root->key);

	int left  = BST_print_t(root->left,  1, offset,                depth + 1, s);
	int right = BST_print_t(root->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width/2 + i] = '-';

		s[depth - 1][offset + left + width/2] = '.';

	} else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width/2 + i] = '-';

		s[depth - 1][offset + left + width/2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width/2 + i] = '-';

		s[2 * depth - 1][offset + left + width/2] = '+';
		s[2 * depth - 1][offset + left + width + right + width/2] = '+';

	} else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width/2 + i] = '-';

		s[2 * depth - 1][offset + left + width/2] = '+';
		s[2 * depth - 1][offset - width/2 - 1] = '+';
	}
#endif

	return left + width + right;
}

int RBT_print_t(RBT *T, RBT_node *root, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (root == T->nil) return 0;

	if (root->color == BLACK)
		sprintf(b, "B_%03d", root->key);
	else
		sprintf(b, "R_%03d", root->key);

	int left  = RBT_print_t(T, root->left,  1, offset,                depth + 1, s);
	int right = RBT_print_t(T, root->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width/2 + i] = '-';

		s[depth - 1][offset + left + width/2] = '.';

	} else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width/2 + i] = '-';

		s[depth - 1][offset + left + width/2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width/2 + i] = '-';

		s[2 * depth - 1][offset + left + width/2] = '+';
		s[2 * depth - 1][offset + left + width + right + width/2] = '+';

	} else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width/2 + i] = '-';

		s[2 * depth - 1][offset + left + width/2] = '+';
		s[2 * depth - 1][offset - width/2 - 1] = '+';
	}
#endif

	return left + width + right;
}

void BST_print(BST *T)
{
	if (T->root == NULL)
		return;

	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");

	BST_print_t(T->root, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}

void RBT_print(RBT *T)
{
	if (T->root == NULL)
		return;

	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");

	RBT_print_t(T, T->root, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}