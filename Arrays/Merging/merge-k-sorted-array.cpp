/*Given k sorted arrays of size n each, merge them and print the sorted output.

Example:

Input:
k = 3, n =  4
arr[][] = { {1, 3, 5, 7},
            {2, 4, 6, 8},
            {0, 9, 10, 11}} ;

Output: 0 1 2 3 4 5 6 7 8 9 10 11 
A simple solution is to create an output array of size n*k and one by one copy all arrays to it. Finally, sort the output array using any O(nLogn) 
sorting algorithm. This approach takes O(nkLognk) time.

We can merge arrays in O(nk*Logk) time using Min Heap. Following is detailed algorithm.

1. Create an output array of size n*k.
2. Create a min heap of size k and insert 1st element of all the arrays into the heap
3. Repeat following steps n*k times.
     a) Get minimum element from heap (minimum is always at root) and store it in output array.
     b) Replace heap root with next element from the array from which the element is extracted. If the array doesn’t have any more elements, 
     then replace root with infinite. After replacing the root, heapify the tree.*/

// using C++ priority_queue
struct Node {
	int elem;
	int i, j;

	Node(int e, int x, int y) { // don't take parameters with the same name as that of the struct variables
		elem = e;
		i = x;
		j = y;
	}
};

struct cmp {
	bool operator()(struct Node a, struct Node b) { return a.elem > b.elem; }
};

//auto comp = [] (const Node &a, const Node &b) { return a.elem > b.elem };

int* solve(int a[][4], int n, int k) {

	int *output = new int[n*k];

	priority_queue<Node, vector<Node>, cmp> pq;
	//priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);

	for(int i = 0; i < k; ++i) pq.push(Node(a[i][0], i, 1));
	
	int cnt = 0;
	
	while(pq.size()) {
		Node root = pq.top();
		pq.pop();

		output[cnt++] = root.elem;

		if(root.j < n) {
			root.elem = a[root.i][root.j];
			root.j += 1;

			pq.push(root);
		}
	}

	return output;
}

int main() {
	int n = 4, k = 3;
	int arr[3][4] = { {1, 3, 5, 7},
		            {2, 4, 6, 8},
		            {0, 9, 10, 11}} ;

    int* output = solve(arr, 4, 3);

    for(int i = 0; i < n*k; ++i) cout << output[i] << " "; 
}

///////////////////////////////////////////////////////////////////////////////
struct Node {
	int element;
	int i;
	int j;
};

class MinHeap {
	
	Node *harr;
	int heap_size;

public:

	MinHeap(Node a[], int sz);

	void Heapify(int );

	int left(int i) { return 2*i +1; }

	int right(int i) { return 2*i +2; }

	Node getMin() { return harr[0]; }

	void replaceMin(Node x) { harr[0] = x; Heapify(0); }
}

MinHeap::MinHeap(Node a[], int sz) {

	harr = a;
	heap_size = sz;

	for (int i = (heap_size-1)/2; i >= 0; --i) 
		Heapify(i);
}

void MinHeap::Heapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heap_size and harr[l].element < harr[smallest].element)
		smallest = l;
	if(r < heap_size and harr[r].element < harr[smallest].element)
		smallest = r;
	if(smallest != i) {
		swap(harr[i], harr[smallest]);
		Heapify(smallest);
	}
}

/*-------------------------------------------------------------------------*/
int *MergeKsortedArray(int *a[], int k) {

	int *output = new int[n*k];

	Node *harr = new Node[k];

	for(int i = 0; i < k; ++i) {
		harr[i].element = a[i][0];
		harr[i].i = i;
		harr[i].j = 1;
	}

	MinHeap h(harr, k);

	for(int cnt = 0; cnt < n*k; ++cnt) {

		Node root = h.getMin();

		output[cnt] = root.element;

		if(root.j < n) {

			root.element = a[root.i][root.j];
			root.j += 1;
		}

		else root.element = INT_MAX;

		h.replaceMin(root);
	}

	return output;
}
/*--------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////
