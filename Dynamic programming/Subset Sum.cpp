#include <iostream>
using namespace std;

// let the total sum of the elemets of the array a be S
bitset<S> bit;

bit.reset();  // reset all bits to 0
bit[0] = 1; // 0th bit will be 1 indicating that sum 0 is possible (ie, when no element is chosen)

for(int i=0;i<n;++i) bit |= (bit<<a[i]);

// bit[i] will indicate that a subset sum of i is possible or not

/////////////////////////////////////////////////////////////////////////////////
// for -ve numbers also



///////////////////////////////////////////////////////////////////////////////////////////////////////


// top down approach //

int a[n];
for(int i=0;i<n;++i) cin>>a[i];
a[n] = -1;

int subsetSum(int *a, int sum) {
	for( ; *a != -1 ; a++ ){
		if(*a == sum) return 1;
		else if(*a < sum)
			return subsetSum(a+1, sum-*a) || subsetSum(a+1, sum);  // either include the element or don't include it
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

int subsetSum(int i, int sum) {
	for(int k = i; k < n; ++k){
		if(a[k] == sum) return 1;
		else if(sum > a[k])
			return subsetSum(k+1, sum - a[k]) || subsetSum(k+1, sum);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////

int dp[S+10];
void subsetSum(){
	dp[0] = 1;
	for(int i=0; i<n; i++)	// for all the numbers of the array
		for(int j=S; j>=a[i]; j--)  // for sums ranging b/w a[i] to S
			dp[j] |= dp[j-a[i]]
}

// here S is the total sum of the array
// dp[k] indicates whether any subset of sum k exists in the array or not
// Special NOTE: if the elements are in infinite supply, then just reverse the jth loop : for (j = a[i]; j <= S; ++j)

//////////////////////////////////////////////////////////////////////////////////////////////
// bottom up // 
bool isSubset(int a[],int n,int sum){
	bool subset[n+1][sum+1];
	for(int i=0;i<=n;i++) subset[i][0] = true;       //  if sum = 0 ,then it is possible to get it via an empty subset
	for(int i=1;i<=sum;i++) subset[0][i] = false;    //  if the set is empty, and sum is positive then it is not possible to get the sum
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<a[i-1]) subset[i][j] = subset[i-1][j];
			
			else subset[i][j] = subset[i-1][j] || subset[i-1][j-a[i-1]];
		}
	}
	return subset[n][sum];
}

//  lets say we have a set = { 2,3,7,8,10 } and we want sum =11
/*  if we have sum 2 and set 3 , here sum is less than 3 , so we go to previous set ie 2 , and assign it the value at 2.the value at 2 may be true or false
depending on whether it was possible to get sum=2 from element 2. 

if we have sum =9 and set =7 , here sum> set by 2 . then we have two choices : 1. we assign it the value of the previous set 3 and set 3 will have value true or false
depending on whether it is possible to get sum 9 from elements {2,3}.
2.we pick the element 7 and now the difference is (9-7)=2 ,and then we go the previous elements and assign it the value where sum is 2.this value will be true or false depending on
whether it was possible to get sum 2 from the previous elements.*/




