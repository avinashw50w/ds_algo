#include <bits/stdc++.h>
using namespace std;

class MinHeap {
	int *A;
	int size;
	int capacity;
public:
	MinHeap(int );

	int top() const { return A[0]; }

	int left(int i) const { return 2*i + 1; }

	int right(int i) const { return 2*i + 2; }

	int parent(int i) const { return (i-1)>>1; }

	void push(int );

	void pop();

	void heapify(int );

	void replaceMin(int );

	void decreaseKey(int , int );

	void removeElement(int );

	void deleteKey(int ); 

};

MinHeap::MinHeap(int c) {
	capacity = c;
	size = 0;
	A = new int[c];
}

void MinHeap::heapify(int i) {
	int l = left(i);
	int r = right(i);
	int s = i;
	if(l < size and A[l] < A[s]) s = l;
	if(r < size and A[r] < A[s]) s = r;

	if(s != i) {
		swap(A[s], A[i]);
		heapify(s);
	}
}

void MinHeap::push(int x) {
	if (size > capacity) return;
	int i = size;
	A[i] = x;
	size++;

	while (i != 0 and A[i] < A[parent(i)]) {
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::pop() {
	if (size <= 0) return;

	if(size == 1) {
		size--;
		return;
	}	

	A[0] = A[size-1];
	size--;

	heapify(0);
}

void MinHeap::replaceMin(int new_val) {
	A[0] = new_val;
	heapify(0);
}

void MinHeap::decreaseKey(int i, int new_val) {
	A[i] = new_val;
	while (i != 0 and A[i] < A[parent(i)]){
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::deleteKey(int i) {
	decreaseKey(i, INT_MIN);
	pop();
}

void MinHeap::removeElement(int x) {
	int i;
	for (i = 0; i < size; ++i)
		if(A[i] == x) break;

	A[i] = A[size-1];
	size--;
	heapify(0);
}



/*
So why is Binary Heap Preferred for Priority Queue?

1.Since Binary Heap is implemented using arrays, there is always better locality of reference and operations are more cache friendly.
2.Although operations are of same time complexity, constants in Binary Search Tree are higher.
3.We can build a Binary Heap in O(n) time. Self Balancing BSTs require O(nLogn) time to construct.
4.Binary Heap doesn’t require extra space for pointers.
5.Binary Heap is easier to implement.
6.There are variations of Binary Heap like Fibonacci Heap that can support insert and decrease-key in T(1) time

Is Binary Heap always better?
Although Binary Heap is for Priority Queue, BSTs have their own advantages and the list of advantages is in-fact bigger compared to binary heap.

1.Searching an element in self-balancing BST is O(Logn) which is O(n) in Binary Heap.
2.We can print all elements of BST in sorted order in O(n) time, but Binary Heap requires O(nLogn) time.
3.Floor and ceil can be found in O(Logn) time.
4.K’th largest/smallest element be found in O(Logn) time by augmenting tree with an additional field.
*/
