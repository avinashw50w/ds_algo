/*Given an array A of integers of size N. Find the maximum sum of all the elements of the subarray 
such that all the elements of the subarray are <= K

INPUT
First line of input contains a single integer T denoting the number of test cases . 
First line of each test case contains two space separated integers N and K where N 
being the number of stacks of coins. Second line of each test case contains N space 
separated integers denoting the number of coins Hi on each stack .

OUTPUT
For each test case , Print the maximum number of coins Xsquare can collect following the above gaming strategy.

CONSTRAINTS
1 ≤ T ≤ 105

1 ≤ N ≤ 105

1 ≤ K ≤ 109

1 ≤ Hi ≤ 109

Note :
sum of N over all the test case will not exceed 106.

SAMPLE INPUT 
2
8 1
3 2 2 3 1 1 1 3
8 2
3 2 2 3 1 1 1 3
SAMPLE OUTPUT 
3
4

Explanation
Test 1 : N = 8 , K = 1 3 2 2 3 1 1 1 3 We can collect coins from stacks numbered 5 , 6 and 7 .

Test 2 : N = 8 , K = 2 3 2 2 3 1 1 1 3 We can collect coins from stacks numbered 2 and 3 .*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 2;

int main() {
	int t, n, k;
	ll h[maxn], dp[maxn];
	cin >> t;

	while (t--) {
		cin >> n >> k;

		for (int i = 1; i <= n; ++i) cin >> h[i];

		memset(dp, 0, sizeof(dp));
		ll ans = 0;
		
		for (int i = 1; i <= n; ++i) {
			if (h[i] <= k) dp[i] = dp[i-1] + h[i];
			ans = max(ans, dp[i]);
		}

		cout << ans << endl;
	}
}