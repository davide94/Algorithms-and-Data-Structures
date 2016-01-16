int arraySize;
int heapSize;

void heap_sort(int[], int);
void build_max_heap(int[]);
void max_heapify(int[], int);
int parent(int);
int left(int);
int right(int);

void heap_sort(int A[], int n) {
	
	arraySize = n;
	
	build_max_heap(A);
	
	for (int i = arraySize-1; i > 0; i--) {
		int swap = A[0];
		A[0] = A[i];
		A[i] = swap;
		heapSize--;
		max_heapify(A, 0);
	}
}

void build_max_heap(int A[]) {
	
	heapSize = arraySize;
	for (int i = (int)(arraySize/2); i >= 0; i--) {
		max_heapify(A, i);
	}
}

void max_heapify(int A[], int i) {

	int l = left(i);
	int r = right(i);
	int max;

	if (l < heapSize && A[l] > A[r]) {
		max = l;
	} else {
		max = i;
	}

	if (r < heapSize && A[r] > A[max]) {
		max = r;
	}

	if (max != i) {
		int swap = A[max];
		A[max] = A[i];
		A[i] = swap;
		max_heapify(A, max);
	}
}

int parent(int i) {
	return (int)(i/2);
}

int left(int i) {
	return 2*(i + 1) - 1;
}

int right(int i) {
	return 2*(i + 1);
}