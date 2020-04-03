// maximum subarray problem also known as Kadane's algorithm //
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void maxSubarray1(int a[],int n){
	int prefix = 0 , maxSum =  -1000000;
	for(int i=0; i<n; ++i){
		prefix += a[i];
		maxSum = max(maxSum , prefix);
		if(prefix < 0) prefix = 0;		
	}
	cout<<maxSum<<endl;
}
// maxSum is the sum of the elements of the maximum subarray //
// another dp way //
void maxSubarray(int a[], int n){
	int dp[n] = {};
	dp[0] = a[0];
	for(int i=1; i<n; ++i)
		dp[i] = max(a[i] , dp[i-1]+a[i]);
		
	cout << *max_element(dp,dp+n);
}


int main(){
	int a[] = {6,2,-4,3,8,1,-5,-6,-9,0,2,4};
	int n = sizeof(a)/sizeof(a[0]);
	maxSubarray(a,n);
}
