void quick_sort(int[], int, int);
int partition(int[], int, int);

void quick_sort(int A[], int p, int r) {
	if (p <= r) {
		int q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j=p; j<=r-1; j++) {
		if (A[j] <= x) {
			i++;
			int swap = A[i];
			A[i] = A[j];
			A[j] = swap;
		}
	}
	int swap = A[i+1];
	A[i+1] = A[r];
	A[r] = swap;
	return i + 1;
}
