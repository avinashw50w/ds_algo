#include "Min_and_Max_heap.cpp"


// to sort in ascending order, we use max heap //  // note that the array is 1-indexed //
void HeapSort(int A[], int N){

	build_maxheap(A, N);
	
	for(int i=N; i>=2; --i){
		swap(A[1], A[i]);
		N--;
		max_heapify(1, A, N);
	}
}

/* time complexity : O(nlogn)
   	space : O(1)  
*/

void max_heapify(int i, int A[], int N){ 
	int left  = 2*i;
	int right = 2*i + 1;
	int largest = i;
	if(left <= N && A[left] > A[largest])
		largest = left;
	if(right <= N && A[right] > A[largest])
		largest = right;
	
	if(largest != i){
		swap(A[largest], A[i]);
		min_heapify(A, largest, N);
	}
}

void build_maxheap(int A[], int N){
	for(int i=N/2; i>=1; --i)     
	max_heapify(i);               
}
