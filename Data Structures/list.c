
typedef struct list_node {
	int32_t key;
	struct list_node *next;
	struct list_node *prev;
} list_node;

typedef struct list {
	struct list_node *head;
} list;

list *new_list() {
	list *ret = malloc(sizeof(list));
	ret->head = NULL;
	return ret;
}

void _list_append(list *L, list_node* node) {

	node->prev = NULL;
	node->next = L->head;
	L->head = node;

	if (node->next != NULL)
		node->next->prev = node;


}

void list_append(list *L, int32_t key) {

	list_node *new = malloc(sizeof(list_node));
	new->key = key;
	_list_append(L, new);

}

list_node *_list_find(list *L, int32_t key) {
	
	list_node *node = L->head;
	while (node != NULL && node->key != key)
		node = node->next;
	return node;

}

int8_t list_find(list *L, int32_t key) {
	
	if (_list_find(L, key) == NULL)
		return 0;		//	key not found
	return 1;			//	key found

}

void _list_delete(list *L, list_node *node) {
	
	if (node == NULL || (node->next != NULL && node->next->prev != node) || (node->prev != NULL && node->prev->next != node))
		return;			//	if the node is not in the list do nothing
	
	if (node->next != NULL)
		node->next->prev = node->prev;
	
	if (node->prev != NULL)
		node->prev->next = node->next;
	else 
		L->head = node->next;

}

void list_delete(list *L, int32_t key) {
	_list_delete(L, _list_find(L, key));
}
