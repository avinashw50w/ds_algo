#include<bits/stdc++.h>
using namespace std;
int maxIncreasingSubsequece(int A[],int n){
	int maxx[n],maximum=0;
	for(int i=0;i<n;i++) maxx[i] = A[i];
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[j]<A[i])
			maxx[i] = max(maxx[i] , maxx[j]+A[i]);
		}
	}

	maximum = *max_element(maxx,maxx+n);
	
	return maximum;
}

/*Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array
 such that the intgers in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5},
  then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) 
  and if the input array is {10, 5, 4, 3}, then output should be 10

Solution
This problem is a variation of standard Longest Increasing Subsequence (LIS) problem. We need a slight change in the Dynamic Programming solution of LIS problem.
 All we need to change is to use sum as a criteria instead of length of increasing subsequence.
*/
