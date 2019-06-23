#include<iostream>
#include<algorithm>
using namespace std;
void selectionSort(int A[],int n){
	for(int i=0;i<n-1;i++){
		int k=i;
		for(int j=i+1;j<n;j++){
			if(A[j]<A[k])
				k=j;	
		}
		swap(A[i],A[k]);
	}
}

// time complexity : O(n2) in all cases
//space complexity : O(1)
