#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define CARD_V 5

#include "graph.c"

int main() {
	
	graph *G = new_graph();
	new_link(G, 0, 1, 1);
	new_link(G, 0, 4, 1);
	new_link(G, 1, 2, 1);
	new_link(G, 1, 3, 1);
	new_link(G, 1, 4, 1);
	new_link(G, 2, 3, 1);
	new_link(G, 3, 4, 1);

	//printf("%i\n", list_find(G->V[3]->links, 4));
	//BFS(G, 0);

	//print_path(G, 0, 4);

	DFS(G);

	return 0;
}