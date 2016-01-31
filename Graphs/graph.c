#include "../Data Structures/list.c"
#include "../Data Structures/queue.c"

typedef struct graph_node {
	int32_t key;
	list *links;
	enum { WHITE, GRAY, BLACK } color;
	int32_t d;
	int32_t f;
	struct graph_node *p;
} graph_node;

typedef struct graph {
	graph_node *V[CARD_V];
} graph;

graph *new_graph() {
	graph *new = malloc(sizeof(graph));
	for (int i=0; i<CARD_V; i++) {
		new->V[i] = malloc(sizeof(graph_node));
		new->V[i]->key = i;
		new->V[i]->links = new_list();
	}
	return new;
}

void new_link(graph *G, int32_t a, int32_t b, int8_t duplex) {
	list_append(G->V[a]->links, b);
	if (duplex == 1)
		list_append(G->V[b]->links, a);
}

void _BFS(graph *G, graph_node *s) { 
	for (int i=0; i<CARD_V; i++) {
		G->V[i]->color = WHITE;
		G->V[i]->d = CARD_V + 1;
		G->V[i]->p = NULL;
	}

	s->color = GRAY;
	s->d = 0;
	s->p = NULL;
	queue *Q = new_queue();
	enqueue(Q, s->key);

	while (Q->head != NULL) {	//	until the queue is not empty
		graph_node *u = G->V[dequeue(Q)];
		list_node *n = u->links->head;
		while (n != NULL) {
			graph_node *v = G->V[n->key];
			if (v->color == WHITE) {
				v->color = GRAY;
				v->d = u->d + 1;
				v->p = u;
				enqueue(Q, v->key);
			}
			n = n->next;
		}
		u->color = BLACK;
	}
}

void BFS(graph *G, int32_t s) {
	_BFS(G, G->V[s]);
}

void print_path(graph *G, int32_t s, int32_t v) {
	BFS(G, s);

	if (v == s)
		printf("%i\n", s);
	else if (G->V[v]->p == NULL)
		printf("No paths between %i and %i\n", s, v);
	else {
		print_path(G, s, G->V[v]->p->key);
		printf("%i\n", v);
	}
}

int32_t time;
void DFS_visit(graph *G, graph_node *u) {
	time++;
	u->d = time;
	u->color = GRAY;

	list_node *n = u->links->head;
	while (n != NULL) {
		graph_node *v = G->V[n->key];
		if (v->color == WHITE) {
			v->p = u;
			DFS_visit(G, v);
		}
		n = n->next;
	}
	u->color = BLACK;
	time++;
	u->f = time;
}

void DFS(graph *G) {
	for (int i=0; i<CARD_V; i++) {
		G->V[i]->color = WHITE;
		G->V[i]->p = NULL;
	}

	time = 0;
	for (int i=0; i<CARD_V; i++)
		if (G->V[i]->color == WHITE)
			DFS_visit(G, G->V[i]);
}
