/*Given an array of integers whose elements represents the sides lengths.
Find the no of triangles that can be formed from the array elements*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a) {
	int n = a.size();
	if (n < 3) return 0;
	int res = 0;

	sort (a.begin(), a.end());

	for (int i = 2; i < n; ++i) {
		int l = 0, r = i - 1;
		while (l < r) {
			if (a[l] + a[r] > a[i]) {
				// If it is possible with a[l], a[r]
                // and a[i] then it is also possible
                // with a[l+1]..a[r-1], a[r] and a[i]
				res += r - l;
				r--;
			}
			else if (a[l] + a[r] <= a[i]) l++;
		}
	}
	return res;
}

int main() {
	int n ; cin >> n;
	vector<int> a {4, 3, 5, 7, 6};
	cout << solve(a);
}