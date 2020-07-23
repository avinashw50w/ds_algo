#include<bits/stdc++.h>
#define oo (1<<30)
using namespace std;
// dp solution //

int fun(int a[], int n) {
	int dp[n + 1] = {};
	dp[0] = a[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(a[i], a[i] + dp[i - 1]);
	}

	return *max_element(dp, dp + n);
}

/*  the concept is : S[i..j] = S[j] - S[i-1]   ,where S[i] means sum of all the elements from index position 0 to i.
 So,in order to maximise ( S[j] - S[i] ) , find the minimum value of S[i]  for all S[j] calculated till then.
 And at the same time keep track of the maximum value obtained so far.
 */
// But the time complexity of the above programe is O(nlogn) ,lower_bound takes logn time
// here is O(n) solution, it also handles the case when all the numbers are -ve
pre_sum = 0, maxi = -oo;
for (int i = 0; i < n; i++) {
	pre_sum += A[i];
	maxi = max(maxi, pre_sum);
	if (pre_sum < 0) pre_sum = 0;
}
cout << maxi;

/////////////////////////////////////////////////////////////
// a better one that handles handles the case when all numbers in array are negative. //
int maxSubArraySum(int a[], int size)
{
	int max_sum = a[0];
	int curr_max = a[0];

	for (int i = 1; i < size; i++)
	{
		curr_max = max(a[i], curr_max + a[i]);
		max_sum = max(max_sum, curr_max);
	}
	return max_sum;
}

////////////////////////////////////////////////////////////////////////
// this one also finds the start and end index of the maximum subarray //
int maxSubarraySum(int a[], int& start, int& finish, int n) {
	finish = -1; start = 0;
	int sum = 0, max_sum = INT_MIN;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum < 0) {
			sum = 0;
			start = i + 1;
		}
		if (sum > max_sum) {
			max_sum = sum;
			finish = i;
		}
	}

	if (finish != -1) return max_sum;

	// if all the numbers are negative  //
	max_sum = a[0];
	start = finish = 0;

	for (int i = 1; i < n; ++i) {
		if (a[i] > max_sum) {
			max_sum = a[i];
			start = finish = i;
		}
	}

	return max_sum;
}
