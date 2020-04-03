/*The idea is to use min heap. Following are detailed step.
1) Build a min heap of elements from first row. A heap entry also stores row number and column number.
2) Do following k times.
…a) Get minimum element (or root) from min heap.
…b) Find row number and column number of the minimum element.
…c) Replace root with the next element from same column and min-heapify the root.
3) Return the last extracted root. 

Following is C++ implementation of above algorithm.*/

typedef tuple<int,int,int> tiii;

int kthSmallest(int mat[4][4], int n, int k)
{		
	priority_queue<tiii, vector<tiii>, greater<tiii> > Q;	// min heap
	
	// insert every element of the first row in the heap 
	for(int i = 0; i < n; ++i) 
		Q.push(make_tuple(mat[0][i], 0, i));

	int val, x, y;
	for(int i = 0; i < k; ++i) {
		tie(val, x, y) = Q.top();
		Q.pop();

		if(x+1 < n) Q.push(make_tuple(mat[x+1][y], x+1, y));
	}

	return val;
}
////////// another implementation //////////////////////////

// kth largest element in a 2d array sorted row-wise and column-wise
 
// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;  // value to be stored
    int r;    // Row number of value in 2D array
    int c;    // Column number of value in 2D array
};
 
// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y) {
    HeapNode z = *x;
    *x = *y;
    *y = z;
}
 
// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
        smallest = l;
    if (r < heap_size && harr[r].val < harr[smallest].val)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}
 
// A utility function to convert harr[] to a max heap
void buildHeap(HeapNode harr[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}
 
// This function returns kth smallest element in a 2D array mat[][]
int kthSmallest(int mat[4][4], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k <= 0 || k > n*n)
       return INT_MAX;
 
    // Create a min heap of elements from first row of 2D array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
        harr[i] =  {mat[0][i], 0, i};
    buildHeap(harr, n);
 
    HeapNode hr;
    for (int i = 0; i < k; i++)
    {
       // Get current heap root
       hr = harr[0];
 
       // Get next value from column of root's value. If the
       // value stored at root was last value in its column,
       // then assign INFINITE as next value
       int nextval = (hr.r < (n-1))? mat[hr.r + 1][hr.c]: INT_MAX;
 
       // Update heap root with next value
       harr[0] =  {nextval, (hr.r) + 1, hr.c};
 
       // Heapify root
       minHeapify(harr, 0, n);
    }
 
    // Return the value at last extracted root
    return hr.val;
}

///////////////////////////////////////////////////////////////
  // python //
from heapq import *
class Solution:
    # @param matrix: a matrix of integers
    # @param k: an integer
    # @return: the kth smallest number in the matrix
    def kthSmallest(self, matrix, k):
        # write your code here
        if not matrix:
            return 0

        heap = []
        row = len(matrix)
        col = len(matrix[0])

        for i in range(col):
            heappush(heap, (matrix[0][i], 0, i))

        for j in range(k-1):
            curr = heappop(heap)
            x = curr[1]
            y = curr[2]
            if x + 1 < row:
                heappush(heap, (matrix[x+1][y], x+1, y))

        return heap[0][0]
