# Sorting algorithms comparison

Just a simple comparison of the growing of temporal complexity of the most commons sorting algorithms at the growing of input size.

### Insertion Sort:

Insertion sort is a sorting algorithm efficient when the input is small, in fact the growth of the computation time (worst case) is proportional to the square of the input length: T(n)=Θ(n^2) *where n is the length of the input array*

### Merge Sort:

Merge sort is based on **divide et impera** paradigma: 
Divide: the problem is recursively divided in two subproblems, each has half the complexity of the previous.
Impera: we recursively split the problem until the subproblem is banal and we can solve in one step.
Combina: the MERGE procedure combines the subproblems to solve the initial problem

The time complexity is Θ(n*lg(n)).

### Heap Sort

### Quick Sort

## Summary

![alt tag](https://raw.githubusercontent.com/davide94/sorting_algorithms_comparison/master/charts/comparison.png)
