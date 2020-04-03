#include<iostream>
using namespace std;
void InsertionSort(int A[],int n){
	for(int i=1;i<n;i++){
		int key = A[i];
		int j = i-1;
		while(j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

//time complexity : best case - O(n) and O(n2) in all other cases.
//space complexity : O(1)
