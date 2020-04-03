
void max_heapify(int i, int A[], int N){ 
	int left  = 2*i + 1;
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

void convertToMaxHeap(int A[], int N) {

	for(int i = N/2-1; i >= 0; --i)     
		max_heapify(i, A, N);  
}

