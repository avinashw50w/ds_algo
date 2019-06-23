#include<iostream>
#include<cmath>
using namespace std;
int A[] = {5,3,8,1,6,9,3,7,4,2,8};
int segTree[100000];
int lazy[100000];

void buildTree(int node,int start,int end){
	if(start == end){
		segTree[node] = A[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(2*node,start,mid);
	buildTree(2*node+1,mid+1,end);
	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

void UpdateRange(int node,int start,int end,int l,int r,int val){
	if(lazy[node]!=0){
		segTree[node] += (end-start+1)*lazy[node];
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start>end || r<start || l>end) return;
	if(l<=start && end<=r){
		segTree[node] += (end-start+1)*val;
		if(start != end){
			lazy[2*node] += val;
			lazy[2*node+1] += val;
		}
		return;
	}
	int mid = (start+end)/2;
	UpdateRange(2*node,start,mid,l,r,val);
	UpdateRange(2*node+1,mid+1,end,l,r,val);
		
	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

int sumQueryRange(int node,int start,int end,int l,int r){
	if(lazy[node] != 0){
		segTree[node] += (end-start+1)*lazy[node];
		if(start !=end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start>end || l>end || r<start)     // no overlap , so return sum 0
	return 0;
	
	if(l<=start && end<=r)   // total overlap , so return the value of the node
		return segTree[node];
	// for partial overlap , recurse on the left and right subtree   and  return their sum
	int mid = (start+end)/2;          
	int q1 = sumQuery(2*node,start,mid,l,r);
	int q2 = sumQuery(2*node+1,mid+1,end,l,r);
	return q1+q2;
}

int main(){
 	int n = sizeof(A)/sizeof(A[0]);
 	int len = (int)(2*pow(2.0 , floor(log(n)/log(2.0)) + 1));
 	
	buildTree(1,0,n-1);  // do not pass initial node value as 0 because 2*node will also become 0
	int x = sumQueryRange(1,0,n-1,3,6);
	cout<<x;
}
