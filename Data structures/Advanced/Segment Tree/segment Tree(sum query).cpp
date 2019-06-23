#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int n;
vector<int> A(MAXN), segTree(MAXN);

void BuildTree(int node,int start,int end){
	if(start == end){
		segTree[node] = A[start];
		return;
	}
	int mid = (start + end)/2;
	BuildTree(2*node, start, mid);
	BuildTree(2*node+1, mid+1, end);
	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

int SumQuery(int node, int start, int end, int qstart, int qend){
	if(qstart > end || qend < start)     // no overlap , so return sum 0
	return 0;
	
	if(qstart <= start && end <= qend)   // query range totally overlaps the segment, so return the value of the node
	return segTree[node];
	// for partial overlap , recurse on the left and right subtree  and  return their sum
	int mid = (start + end)/2;          
	int q1 = SumQuery(2*node, start, mid, qstart, qend);
	int q2 = SumQuery(2*node+1, mid+1, end, qstart, qend);
	return q1 + q2;
}

void Update(int node, int start, int end, int idx, int new_val) {
	if(idx < start || end < idx) return;  // if idx of the number is out of bound
	
	int diff = new_val - A[idx];
	if(start == end) {
		A[idx] += diff;
		segTree[node] += diff;
		return;
	}

	int mid = (start + end)/2;
	if(idx < mid) 
		Update(2*node, start, mid, idx, new_val);
	else
		Update(2*node+1, mid+1, end, idx, new_val);

	segTree[node] = segTree[2*node] + segTree[2*node+1];
}


int main(){
 	vector<int> v {5,3,8,1,6,9,3,7,4,2,8};
 	A = v;
 	n = A.size();
 	int len = (int)(2*pow(2.0 , floor(log(n)/log(2.0)) + 1));

	BuildTree(1, 0, n-1);

	int x = SumQuery(1, 0, n-1, 3, 6);  // output = 19
	cout<<x;
}


