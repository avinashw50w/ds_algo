/*Given an unsorted array, find the lenght of the longest subsequence of consecutive numbers in the array.

eg. [4, 1, 2, 5, 6],  ans = 3 [4,5,6] */

int solve(vector<int> a) {
	int n = a.size();
	unordered_set<int> st(a.begin(), a.end());

	int ans = 0;
	for (int e : st) {
		if (st.count(e - 1) == 0) {
			int len = 1;
			while (st.count(e + len)) len++;
			ans = max(ans, len);
		}
	}

	return ans;
}

// Time complexity : O(n)
// Space complexity : O(n)

