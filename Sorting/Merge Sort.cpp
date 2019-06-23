#include <iostream>
using namespace std;

void Merge(int A[],int L[],int R[]){
	int l = sizeof(L)/sizeof(L[0]);
	int r = sizeof(R)/sizeof(R[0]);
	int i,j,k; i=j=k=0;
	while(i<l && j<r){
		if(L[i]<=R[j]){
			A[k] = L[i];
			i++; k++;
		}
		else{
			A[k] = R[j];
			j++; k++;
		}
	}
	while(i<l){
		A[k] = L[i];
		i++; k++;
	}
	while(j<r){
		A[k] = R[j];
		j++; k++;
	}
}

void MergeSort(int A[]){
	int n = sizeof(A)/sizeof(A[0]);
	if(n<2) return;
	int mid = n>>1;
	int L[mid] , R[n-mid];
	for(int i=0;i<mid;i++) L[i] = A[i];
	for(int i=mid;i<n;i++) R[i-mid] = A[i];
	MergeSort(L);
	MergeSort(R);
	Merge(A,L,R);
}

// time complexity : O(nlogn) in all cases.
// Auxiliary space complexity : average case - O(logn) , worst case - O(n)

/* Another way of doing it is : 
// Merges two subarrays of arr[].
// First subarray is arr[l..m], Second subarray is arr[m+1..r] */

// another approach //
void merge(int lstart, int lend, int rstart, int rend)
{
    int k = 0, p = lstart;
    // create temp arrays 
    int tmp[rend - lstart +2];
    // Merge the temp arrays back into tmp[l..r]
    while (lstart <= lend && rstart <= rend)
    {
        if (A[lstart] <= A[rstart])
            tmp[k++] = A[lstart++];
        else
            tmp[k++] = A[rstart++];
    }
 
    while(lstart <= lend) tmp[k++] = A[lstart++];
    
    while(rstart <= rend) tmp[k++] = A[rstart++];

    for(int i = 0; i < k; ++i)
        A[p + i] = tmp[i];
}
 
void mergeSort(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and r
        int m = l+(r-l)>>1;
        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);
 
        merge(l, m, m+1, r);
    }
}
