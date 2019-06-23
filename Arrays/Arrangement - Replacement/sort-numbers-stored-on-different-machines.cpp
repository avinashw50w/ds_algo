/*Given N machines. Each machine contains some numbers in sorted form. But the amount of numbers, each machine has is not fixed. 
Output the numbers from all the machine in sorted non-decreasing form.

Example:
       Machine M1 contains 3 numbers: {30, 40, 50}
       Machine M2 contains 2 numbers: {35, 45} 
       Machine M3 contains 5 numbers: {10, 60, 70, 80, 100}
       
       Output: {10, 30, 35, 40, 45, 50, 60, 70, 80, 100}
Representation of stream of numbers on each machine is considered as linked list. A Min Heap can be used to print all numbers in sorted order.

Following is the detailed process

1. Store the head pointers of the linked lists in a minHeap of size N where N is number of machines.

2. Extract the minimum item from the minHeap. Update the minHeap by replacing the head of the minHeap with the next number from 
the linked list or by replacing the head of the minHeap with the last number in the minHeap followed by decreasing the size of heap by 1.

3. Repeat the above step 2 until heap is not empty.*/

typedef tuple<int,int,int> tiii
auto cmp = [] (const tiii &a, const tiii &b) { return get<0>(a) > get<0>(b); };

vector<int> solve(vector<vector<int>> A) {
	vector<int> res;
	int N = A.size();
	priority_queue<tiii, vector<tiii>, decltype(cmp)> Q(cmp);

	for (int i = 0; i < N; ++i) {
		Q.push(make_tuple(a[i][0], i, 1));
	}

	while(Q.size()) {
		tie(val, i, j) = Q.top();
		Q.pop();
		res.push_back(val);

		if (j < A[i].size()) {
			Q.push(make_tuple(A[i][j], i, j+1));
		}
	}
}




//////////////////////////////////////////////////////////////////////////

struct Node {
	int data;
	Node *next;
};

class MinHeap {
	vector<Node*> A;

public:
	MinHeap() : {}

	Node* top() const { return A[0]; }

	int left(int i) const { return 2*i + 1; }

	int right(int i) const { return 2*i + 2; }

	int parent(int i) const { return (i-1)>>1; }

	void push(Node* );

	void pop();

	void heapify(int );

};

/*----------------------------------------------------------------------*/
void externalSort(Node *arr[], int N) {

	MinHeap H;
	for(int i = 0; i < N; ++i) 
		H.push(arr[0]);

	while(!H.empty()) {
		Node* top = H.top();
		H.pop();

		cout << top->data <<" ";
	}
}
/*-------------------------------------------------------------------------*/

void MinHeap::push(Node* x) {
	A.push_back(x);
	int i = A.size();
	while (i != 0 and A[i]->data < A[parent(i)]->data) {
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::pop() {
	if (A.empty()) return;

	if(A[0]->next != NULL) {
		A[0] = A[0]->next;
	}	
	else {
		A[0] = A[A.size()-1];
		A.pop_back();
	}

	heapify(0);
}

void MinHeap::heapify(int i) {
	int l = left(i);
	int r = right(i);
	int s = i;
	if(l < size and A[l]->data < A[s]->data) s = l;
	if(r < size and A[r]->data < A[s]->data) s = r;

	if(s != i) {
		swap(A[s], A[i]);
		heapify(s);
	}
}

int main()
{
    int N = 3; // Number of machines
 
    // an array of pointers storing the head nodes of the linked lists
    Node *array[N];
 
    // Create a Linked List 30->40->50 for first machine
    array[0] = NULL;
    push (&array[0], 50);
    push (&array[0], 40);
    push (&array[0], 30);
 
    // Create a Linked List 35->45 for second machine
    array[1] = NULL;
    push (&array[1], 45);
    push (&array[1], 35);
 
    // Create Linked List 10->60->70->80 for third machine
    array[2] = NULL;
    push (&array[2], 100);
    push (&array[2], 80);
    push (&array[2], 70);
    push (&array[2], 60);
    push (&array[2], 10);
 
    // Sort all elements
    externalSort( array, N );
 
    return 0;
}