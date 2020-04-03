#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

void buildTree(int A[],int segTree[],int node,int start,int end){
	if(start==end){
		segTree[node] = A[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(A,segTree,2*node,start,mid);
	buildTree(A,segTree,2*node+1,mid+1,end);
	segTree[node] = max(segTree[2*node],segTree[2*node+1]);
}

int maxQuery(int A[],int segTree[],int node,int start,int end,int qstart,int qend){
	if(qstart<=start && end<=qend)         //  total overlap
	return segTree[node];
	
	if(qstart>end || qend<start)         //  no overlap
	return INT_MIN;
	
	int mid = (start + end)/2;
	return max(maxQuery(A,segTree,2*node,start,mid,qstart,qend) , maxQuery(A,segTree,2*node+1,mid+1,end,qstart,qend));         //   if partailly overlap
}

int main(){
		int A[] = {5,3,8,1,6,9,3,7,4,2,8};
 	int n = sizeof(A)/sizeof(A[0]);
 	int len = (int)(2*pow(2.0 , floor(log(n)/log(2.0)) + 1));
 	int segTree[len];
	buildTree(A,segTree,1,0,n-1);
	int x = maxQuery(A,segTree,1,0,n-1,4,10);
	cout<<x;
}
