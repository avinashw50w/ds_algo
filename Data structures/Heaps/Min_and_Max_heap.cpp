#include <iostream>
using namespace std;

int A[1000];   //  heap  , note that heap starts from index 1
int N;         // no of elements

//  O(logn)
void min_heapify(int i){ 
	int left  = 2*i;
	int right = 2*i + 1;
	int smallest = i;
	if(left <= N && A[left] < A[smallest])
		smallest = left;
	if(right <= N && A[right] < A[smallest])
		smallest = right;
	
	if(smallest != i){
		swap(A[smallest], A[i]);
		min_heapify(A, smallest, N);
	}
}

// O(N) amortized
void build_minheap(){
	for(int i=N/2; i>=1; --i)     //  the leaf nodes have index  N/2+1 , N/2+2 , N/2+3 ,......, N
	min_heapify(i);               //  so thre is no need to heapify the leaf nodes
}

/*============================== Similarly for Max heap =======================================*/
void max_heapify(int i){ 
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

void build_maxheap(){
	for(int i=N/2; i>=1; --i)     
	max_heapify(i);               
}
