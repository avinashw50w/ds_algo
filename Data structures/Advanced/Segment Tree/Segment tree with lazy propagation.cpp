#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int N;
int tree[MAXN], A[MAXN], lazy[MAXN];

// this function builds the segment tree
void build(int node, int l, int r) {
	// if the node is a leaf node, then assign the element to it
	if(l == r) {
		tree[node] = A[l];
		return;
	}
	int mid = (l+r)>>1;
	// build the left subtree
	build(2*node, l, mid);
	// build the right subtree
	build(2*node+1, mid+1, r);
	// value at a node is the sum of values of its left and right child
	tree[node] = tree[2*node] + tree[2*node+1];
}

// this function updates the val at index idx of the array
// note that here val = new value - old value
void update(int node, int l, int r, int idx, int val) {
	// if leaf node, means the index is reached, now update the old value
	if(l == r) {
		A[idx] += val;
		tree[node] += val;
		return;
	}
	int mid = (l+r)>>1;
	// if idx is on the left of mid, then recurse on the left subtree
	// otherwise recurse on the right subtree
	if(idx <= mid)
		update(2*node, l, mid, idx, val);
	else 
		update(2*node+1, mid+1, r, idx, val);
// since the value of the leaf node is changed, the value of its parent should also be chaged
	tree[node] = tree[2*node] + tree[2*node+1];  
}

void laziness(int node, int l, int r, int val) {
	// there are r-l+1 children of the node 'node' , so store all of their updates in this node
	tree[node] += (r-l+1) * val;  // in case of min/max query : tree[node] += val;
	// if the node is not a leaf node store the updates that need to be made 
	//to the children of this node in the lazy array
	if(l != r) {  
		lazy[2*node] += val;
		lazy[2*node+1] += val;
	}
	return;
}

void updateRange(int node, int l, int r, int ql, int qr, int val) {
	// if there are pending updates, then update the node
	if(lazy[node] != 0) {
		laziness(node, l, r, lazy[node]);
		lazy[node] = 0;  // done with it
	}
	// if range is out of bound
	if(l > r or ql > r or qr < l) return;
	// if range is completly within bound
	if(ql <= l and r <= qr) {
		laziness(node, l, r, val);
		return;  // note that we are returning from here and not recursively updating its children nodes(this is called lazy propagation)
	}
	int mid = (l+r)>>1;
	updateRange(2*node, l, mid, ql, qr, val);
	updateRange(2*node+1, mid+1, r, ql, qr, val);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int queryrange(int node, int l, int r, int ql, int qr) {
	// if range is out of bound
	if(ql > r or qr < l) return 0;
	// if there are pending updates, then update it
	if(lazy[node] != 0){
		laziness(node, l, r, lazy[node]);
		lazy[node] = 0;
	}
	// if range is completly within bound, then return the value of the node
	if(ql <= l and r <= qr) return tree[node];

	int mid = (l+r)>>1;
	int a = queryrange(2*node, l, mid, ql, qr);
	int b = queryrange(2*node+1, mid+1, r, ql, qr);
	return a + b;
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i) cin >> A[i];

	build(1, 0, N-1);
}


