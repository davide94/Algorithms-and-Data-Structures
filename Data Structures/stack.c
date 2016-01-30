
typedef struct stack_node {
	int32_t key;
	struct stack_node *prev;
} stack_node;

typedef struct stack {
	struct stack_node *head;
} stack;

stack *new_stack() {
	stack *new = malloc(sizeof(stack));
	new->head = NULL;
	return new;
}

void _stack_push(stack *S, stack_node *node) {

	if (node == NULL)
		return;
	
	node->prev = S->head;
	S->head = node;

}

void stack_push(stack *S, int32_t key) {

	stack_node *node = malloc(sizeof(stack_node));
	node->key = key;
	_stack_push(S, node);
}

stack_node *_stack_pop(stack *S) {

	if (S->head == NULL)
		return NULL;

	stack_node *ret = S->head;
	S->head = S->head->prev;
	return ret;
}

int32_t stack_pop(stack *S) {

	stack_node *n =_stack_pop(S);
	if (n != NULL)
		return n->key;
	return -1;					// if stack_pop() returns -1 means the stack is empty, so storing -1 value in the stack causes ambiguity.

}
