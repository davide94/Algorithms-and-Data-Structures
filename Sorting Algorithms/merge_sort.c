
void merge_sort(int[], int, int);
void merge(int[], int, int, int);

void merge_sort(int A[], int p, int r) {

	if(p<r) {
		int q = (p+r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

void merge(int A[], int p, int q, int r) {
	
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1+1];
	int R[n2+1];

	for (int i=0; i<n1; i++) {
		L[i] = A[p+i];
	}

	for (int i=0; i<n2; i++) {
		R[i] = A[q+i+1];
	}

	L[n1] = R[n2] = MAX + 1;
	int i = 0;
	int j = 0;

	for (int k=p; k<=r; k++) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void merge_sort_worst_case(int A[], int len) {

	srand(time(NULL));

	for (int i=0; i<len; i++) {
		A[i] = rand();
	}
}