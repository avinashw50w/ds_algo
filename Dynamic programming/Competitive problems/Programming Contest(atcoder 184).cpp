/*Takahashi will participate in a programming contest, which lasts for T minutes and
presents N problems. With his extrasensory perception, he already knows that it will take Ai
minutes to solve the i-th problem.He will choose zero or more problems to solve from the N
problems so that it takes him no longer than T minutes in total to solve them.
Find the longest possible time it takes him to solve his choice of problems.

Constraints
All values in input are integers.
1≤N≤40
1≤T≤10^9
1≤Ai≤10^9
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve() {
	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int &x : a) cin >> x;

	ll ans = 0LL;
	set<ll> possible;

	int L = n / 2, R = n - L;

	for (int i = 0; i < 1 << L; ++i) {
		ll sum = 0;
		for (int j = 0; j < L; ++j) {
			if (i >> j & 1)
				sum += a[j];
		}
		if (sum <= t) {
			possible.insert(sum);
			ans = max(ans, sum);
		}
	}

	for (int i = 0; i < 1 << R; ++i) {
		ll sum = 0;
		for (int j = 0; j < R; ++j) {
			if (i >> j & 1)
				sum += a[L + j];
		}

		if (sum <= t) {
			ans = max(ans, sum);
			ll target = t - sum;
			auto it = possible.upper_bound(t - sum);
			if (it != possible.begin()) {
				--it;
				ans = max(ans, sum + *it);
			}
		}
	}

	return ans;
}

int main() {
	cout << solve() << endl;
}