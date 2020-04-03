#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int a[],int l,int r,int item){
	int mid, ans = -1;
	while(l <= r){
		mid = l + (r-l)/2;
		if(item <= a[mid])
			ans = mid, r = mid-1;
		else 
			l = mid+1;
	}
	return ans;
}

int lastOccurrence(int a[],int l,int r,int item){
	int mid, ans = -1;
	while(l <= r){
		mid = l + (r-l)/2;
		if(a[mid] <= item)
			ans = mid, l = mid+1;
		else 
			r = mid-1;
	}
	return ans;
}

int numberOfOccurrences(int A[], int size, int item) {
    // Note the boundary parameters
    int l = firstOccurrence(A, 0, size, item);
    int r = lastOccurrence(A, 0, size, item);
    if (A[l] == item && A[r] == item)            // If the item is in the array A
        return (r - l + 1);
    else                                               // If the item is not in the array A
        return 0;
}

int numberOfOccurrences1(int A[], int size, int item) {
	int low = lower_bound(A, A+size, item) - A;
	int high = upper_bound(A, A+size, item) - A;
	return (high - low);
}

int main(){
	int a[] = {1,3,4,4,4,5,6,7,8,8};
	int n = sizeof(a)/sizeof(a[0]);
	cout << firstOccurrence(a,0,n,2) << endl;
	cout << lastOccurrence(a,0,n,8) << endl;
	cout << numberOfOccurrences(a,n,4) << endl;
}
