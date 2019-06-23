#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> a = {5, 5, 10 ,100, 10, 5};

	int n = a.size();

	int dp[n+1];
	dp[0] = a[0];
	dp[1] = a[1];

	for(int i=2; i<n; ++i) {
		dp[i] = max(dp[i-1], a[i] + dp[i-2]);
	}

	cout << *max_element(dp, dp+n) << endl;
}