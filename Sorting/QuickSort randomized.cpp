#include<iostream>
#include<algorithm>
using namespace std;

//void swap(int *a , int *b){if(a==b) return;int *t=a;a=b;b=t;}

int partition(int *A,int left,int right){
	int pivot = A[right];
	int pIndex = left;
	for(int i=left;i<right;i++){
		if(A[i]<=pivot){
			swap(A[i],A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex],A[right]);
	return pIndex;
}

int rand_partition(int *A,int left,int right){
	int randomIndex = left + rand()%(right-left+1);
	swap(A[randomIndex],A[right]);
	return partition(A,left,right);
}

void quickSort(int *A,int left,int right){
	if(left<right){
		int pIndex = rand_partition(A,left,right);
		quickSort(A,left,pIndex-1);
		quickSort(A,pIndex+1,right);
	}
}

int main(){
	int A[] = {5,3,8,1,7,6};
	int n = sizeof(A)/sizeof(A[0]);
	quickSort(A,0,n-1);
	for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
	return 0;
}
