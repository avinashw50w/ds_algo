/*Find the maximum sum among all those subarrays whose size is between a and b.*/

int solve(vector<int> A, int a, int b) {
	int n = A.size();
	vector<int> sum(n+1, 0);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = A[i] + sum[i];
	}

	set<array<int, 2>> st;
	int ans = -1e9;

	for (int i = 0; i <= n; ++i) {
		if (i >= a)
			st.insert({sum[i - a], i - a});
		if (st.size())
			ans = max(ans, sum[i] - (*st.begin())[0]);
		if (i >= b)
			st.erase({sum[i - b], i - b});
	}

	return ans;
}