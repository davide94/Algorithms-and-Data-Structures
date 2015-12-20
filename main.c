#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

#include "insertion_sort.c"
#include "merge_sort.c"
#include "heap_sort.c"

void print_array(int*, int);

int main() {
	
	FILE *h;
	h = fopen("result.dat","w");

	for (int len = 10; len <= MAX; len+=10) {
		
		int *A = malloc(len*sizeof(int));
		int *B = malloc(len*sizeof(int));
		int *C = malloc(len*sizeof(int));

		srand(time(NULL));

		for (int i=0; i<len; i++) {
			int value = rand() % MAX;
			A[i] = value;
			B[i] = value;
			C[i] = value;
		}


		//printf("Before:\n");
		//print_array(A, len);

		clock_t start, end;
		double cpu_time_insertion_sort, cpu_time_merge_sort, cpu_time_heap_sort;

		start = clock();
		insertion_sort(A, len);
		end = clock();
		cpu_time_insertion_sort = ((double) (end - start)) / CLOCKS_PER_SEC;

		start = clock();
		merge_sort(B, 0, len-1);
		end = clock();
		cpu_time_merge_sort = ((double) (end - start)) / CLOCKS_PER_SEC;

		start = clock();
		heap_sort(C, len);
		end = clock();
		cpu_time_heap_sort = ((double) (end - start)) / CLOCKS_PER_SEC;

		//printf("\nAfter:\n");
		//print_array(A, len);

		printf("\nSorted	%i	items in	%f	%f	%f	clock times\n\n", len, cpu_time_insertion_sort, cpu_time_merge_sort, cpu_time_heap_sort);
		fprintf(h,"%i,%f,%f,%f\n", len, cpu_time_insertion_sort, cpu_time_merge_sort, cpu_time_heap_sort);

	}

	fclose(h);
}

void print_array(int A[], int len) {

	for (int i = 0; i < len-1; i++) {
		printf("%i, ", A[i]);
	}
	printf("%i\n", A[len-1]);

}
