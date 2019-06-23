/* )()(()))*/
// NOTE: this stack solution gave a WRONG ans in LEETCODE. ONLY the DP solution is correct
int solve(string s) {
	int n = s.size(), mx = 0, cnt = 0;
	stack<char> st;
	st.push(-1);

	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') st.push(i);
		else {
			st.pop();

			if (!st.empty()) mx = max(mx, i-st.top());

			else st.push(i);
		}
	}

	return mx;
}

// dp approach

// eg : ))()(())
int solve(string s) {
	int n = s.size();

	int dp[n+2]; // dp[i] stores the longest valid parentesis unto index i

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n; ++i) {
		if (s[i] == ')' and i-dp[i-1]-1 >= 0 and s[i-dp[i-1]-1] == '(')
			dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >= 0) ? dp[i-dp[i-1]-2] : 0);
	}

	return *max_element(dp, dp+n);
}