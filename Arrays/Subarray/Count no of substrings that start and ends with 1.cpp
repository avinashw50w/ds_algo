/*Given a binary string S. The task is to count the number of substrings that starts and end with 1.
Note: The starting and the ending 1s should be different.
Input:
S = "10101"
Output: 3
Explanation: The 3 substrings are "101",
"10101" and "101".*/

int solve(string s) {
	int ans = 0, cnt = -1;
	for (char c : s) {
		if (c == '1') {
			cnt++;
			ans += cnt;
		}
	}

	return ans;
}