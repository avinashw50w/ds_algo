/*you have given array of Size N and two numbers M, K. K is size of subarray and M is count of subarray.
You have to return sum of max M subarray of size K (non-overlapping)

N = 7, M = 3 , K = 1

A={2 10 7 18 5 33 0} = 61 — subsets are: 33, 18, 10 (top M of size K)

M=2,K=2
{3,2,100,1} = 106 - subsets are: (3,2), (100,1) 2 subsets of size 2*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int a[], int N, int M, int K) {
	vector<int> ksum;
	int sum = 0, l = 0;
	for (int i = 0; i < K; ++i)
		sum += a[i];
	ksum.push_back(sum);

	for (int i = K; i < N; ++i) {
		sum += a[i] - a[i - K];
		ksum.push_back(sum);
	}

	int dp[N - K + 1];
	dp[0] = ksum[0];
	for (int i = 1; i < N - K + 1; ++i) {
		dp[i] = max(dp[i - 1], ksum[i] + (i - K >= 0) ? dp[i - K] : 0);
	}

	sort(dp, dp + N - K + 1, greater<int>());

	vector<int> ans;
	for (int i = 0; i < M; ++i)
		ans.push_back(dp[i]);

	return ans;
}


int main() {
	int a[] = {5, 2, 4, 6, 3, 7, 1, 8};
	N = sizeof(a) / sizeof(a[0]);
	K = 3;
	int sum = 0, j = 0;
	vector<int> ans = solve(a, N, 3, K);
	for (int i = 0; i < 3; ++i) cout << ans[i] << " ";
}


///////////////////////////////////////////////////////////////////
/*
const int maxn = 50;
int N, K;
int dp[maxn][maxn];
int ksum[maxn];

int solve(int index, int M) {
	if(M == 0 || index >= N) return 0;

	if(dp[index][M] != -1) return dp[index][M];

	int mxSum = 0;
	for(int i = index; i < N-K+1; ++i) {
		int t = ksum[i] + solve(i+K, M-1);
		maxSum = max(maxSum, t);
	}
	return dp[index][M] = maxSum;
}

///////////////////////////////////////////////////////////*/