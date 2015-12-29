void insertion_sort(int A[], int n) {

	for(int i=1; i<n; i++) {

		int key = A[i];
		int j = i-1;

		while(j>=0 && A[j]>key) {

			A[j+1] = A[j];
			j--;
		}

		A[j+1] = key;
	}
}

void insertion_sort_worst_case(int A[], int len) {

	for (int i = 0; i < len; i++) {
		A[i] = len - i;
	}
}