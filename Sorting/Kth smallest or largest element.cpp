// another method :
// for both Kth largest and Kth smallest use min heap
/*1) Build a Min Heap MH of the first k elements (arr[0] to arr[k-1]) of the given array. O(k)

2) For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
……a) If the element is greater than the root then make it root and call heapify for MH
……b) Else ignore it.
// The step 2 is O((n-k)*logk)

3) Finally, MH has k largest elements and root of the MH is the kth largest element.

Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)*/


int KthLargest(int a[], int n, int K) {
	priority_queue<int, vector<int>, greater<int>> Q;
	int i;
	for (i = 0; i < K; ++i) Q.push(a[i]);

	for (; i < n; ++i) {
		if (a[i] > Q.top()) // in case of Kth smallest do (a[i] < Q.top())
			Q.pop(), Q.push(a[i]);
	}

	return Q.top();
}

////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
int partition(int *A, int l, int r) {
	int pivot = A[r];
	int pIndex = l;
	for (int i = l; i < r; i++) {
		if (A[i] <= pivot)
			swap(A[i], A[pIndex]);
		pIndex++;
	}
	swap(A[r], A[pIndex]);
	return pIndex;
}

int randomPartition(int *A, int l, int r) {
	int pivotIndx  = l + rand() % (r - l + 1);
	swap(A[r], A[pivotIndx]);
	return partition(A, l, r);
}

int Kth_largest_elem(int *A, int l, int r, int k) {
	if (k > 0 && k <= (r - l + 1)) {
		int pos = randomPartition(A, l, r);
		if (k == pos - l + 1) return A[pos];

		if (k < pos - l + 1)
			return Kth_largest_elem(A, l, pos - 1, k);

		else return Kth_largest_elem(A, pos + 1, r, k);
	}
	else return;
}
