
typedef struct queue_node {
	int32_t key;
	struct queue_node *next;
} queue_node;

typedef struct queue {
	struct queue_node *head;
	struct queue_node *tail;
} queue;

queue *new_queue() {
	queue *new = malloc(sizeof(queue));
	new->head = NULL;
	new->tail = NULL;
	return new;
}

void _enqueue(queue *Q, queue_node *node) {

	if (node == NULL)
		return;
	
	if (Q->tail == NULL)
		Q->head = node;
	else
		Q->tail->next = node;

	Q->tail = node;

}

void enqueue(queue *Q, int64_t key) {

	queue_node *new = malloc(sizeof(queue_node));
	new->key = key;
	new->next = NULL;
	_enqueue(Q, new);
}

queue_node *_dequeue(queue *Q) {
	
	if (Q->head == NULL)
		return NULL;

	queue_node *ret = Q->head;
	Q->head = Q->head->next;
	if (Q->tail == ret)
		Q->tail = NULL;

	return ret;
}

int32_t dequeue(queue *Q) {

	queue_node *n =_dequeue(Q);
	if (n != NULL)
		return n->key;
	return -1;					// if dequeue() returns -1 means the queue is empty, so storing -1 value in the queue causes ambiguity.

}
