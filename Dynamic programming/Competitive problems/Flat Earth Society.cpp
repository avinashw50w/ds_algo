#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;
int A[maxn], dp[maxn];

int main() {
	int t, n, l, r;
	cin >> t;

	while (t--) {
		cin >> n >> l >> r;
		for (int i = 0; i < n; ++i) cin >> a[i];

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; ++i) {
			int op1 = a[i] + (i-l-1 >= 0 ? dp[i-l-1] : 0);
			int op2 = dp[i-1];

			dp[i] = max(op1, op2);
		}

		cout << dp[n-1] << endl;
	}
}