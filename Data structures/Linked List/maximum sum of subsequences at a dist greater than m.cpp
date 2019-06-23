#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> a = {3, 4, -2, 1, -2, 4, 6, -3, 5};

	int n = a.size();

	int m = 3;

	int dp[n+1];
	
	dp[0] = a[0];
	for(int i=1; i<m ;++i) dp[i] = max(a[i], dp[i-1]);

	for(int i=m; i<n; ++i) {
		dp[i] = max(dp[i-1], a[i] + dp[i-m]);
	}

	cout << *max_element(dp, dp+n) << endl;
}