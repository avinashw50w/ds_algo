/*Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, 
then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order 
sequence is considered Bitonic with the increasing part as empty.

Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Solution
This problem is a variation of standard Longest Increasing Subsequence (LIS) problem. Let the input array be arr[] of length n. 
We need to construct two arrays lis[] and lds[] using Dynamic Programming solution of LIS problem. lis[i] stores the length of 
the Longest Increasing subsequence ending with arr[i]. lds[i] stores the length of the longest Decreasing subsequence starting 
from arr[i]. Finally, we need to return the max value of lis[i] + lds[i] – 1 where i is from 0 to n-1.*/

int lis(int a[], int n) {

	int lis[n], lds[n];	// logest increasing and longest decreasing subsequence //

	memset(lis, 1, sizeof(lis));
	memset(lds, 1, sizeof(lds));

	for(int i = 1; i < n; ++i) 
		for(int j = 0; j < i; ++j)
			if(a[j] < a[i] and lis[j] + 1 > lis[i])
				lis[i] = lis[j] + 1;

	for(int i = n-2; i >= 0; --i) 
		for(int j = n-1; j > i; --j)
			if(a[j] < a[i] and lds[j] + 1 > lds[i])
				lds[i] = lds[j] + 1;


	int ans = 1;

	for(int i = 0; i < n; ++i)
		ans = max(ans, lis[i] + lds[i] - 1);


	return ans;
	
}