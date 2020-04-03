
int maxSum(int a[], int n) {

	int inc = a[0];
	int exl = 0;

	for(int i = 1; i < n; ++i) {
		int tmp = inc;

		inc = max(inc, exl+a[i]);

		exl = tmp;

	}

	return max(inc, exl);
}

////////////////////////////////////////
// dp way

dp[n];

dp[0] = a[0];
dp[1] = a[1];

for (int i = 2; i < n; ++i)
	dp[i] = max(dp[i-1], a[i]+dp[i-2]);
	
	
return max(dp[n-2], dp[n-1]);
