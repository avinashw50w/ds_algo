// O(N^2)
// longest strictly increasing subsequence
// Time : O(N^2), space : O(N)
int LIS(vector<int> a) {
	int n = a.size();
	// dp[i] = the longest increasing subsequence till index i
	// the minimum increasing subsequece at any index is 1(the element itself)
	vector<int> dp(n, 1);
	int ans = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				// either include the element or don't include it
				dp[i] = max(dp[i] , dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}

	return ans;
}

// O(nlogn)
// longest strictly increasing subsequence
/*Algo :
1. take a vector v
2. iterate over array elements.
3. find the lower_bound of a[i] in v, let's say p
4. if p < v.size(), means a[i] is <= the largest element in v, then replace v[p] with a[i]
5. else push a[i] to v
6. final ans = v.size()
*/

int LIS(vector<int> a) {
	int n = a.size();
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		if (p < v.size())
			v[p] = a[i];
		else
			v.push_back(a[i]);
	}

	return v.size();
}

// longest non-decreasing subsequence
// Time : O(nlogn)
int LIS(vector<int> a) {
	int n = a.size();
	vector<int> v;

	for (int i = 0; i < n; ++i) {
		int p = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
		if (p < v.size())
			v[p] = a[i];
		else
			v.push_back(a[i]);
	}

	return v.size();
}