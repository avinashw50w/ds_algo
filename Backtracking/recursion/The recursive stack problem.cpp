/*
1. () - score 1
2. AB - score is A + B 
3. (A) - score is 2 * A

where A and B are balanced parenthesis. Find the score of any balanced paranthesis

eg. (()(()))
score = 6

explanation: ( 1 + (1) ) => ( 1 + 2*1 ) => ( 3 ) => 2 * 3 = 6
*/

vector<int> en;

int solve(int lo, int hi) {
	if (lo > hi) return 1;

	int mid = en[lo];

	if (mid == hi) 
		return 2 * solve(lo+1, hi-1);
	
	return solve(lo, mid) + solve(mid+1, hi);
}

void findScore(string s) {
	stack<int> st;

	int n = s.size();
	en.resize(n);

	for (int i = 0; i < n; ++i) {
		if (s[i] == ')') {
			int t = st.top();
			en[t] = i;
			st.pop();
		} else {
			st.push(i);
		}
	}

	cout << solve(0, n-1);
}