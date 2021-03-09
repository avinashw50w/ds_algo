/*Transform One String to Another using Minimum Number of Given Operation
Given two strings A and B, the task is to convert A to B if possible. The only operation
allowed is to put any character from A and insert it at front. Find if it’s possible to convert
the string. If yes, then output minimum no. of operations required for transformation.

Examples:

Input:  A = "ABD", B = "BAD"
Output: 1
Explanation: Pick B and insert it at front.

Input:  A = "EACBD", B = "EABCD"
Output: 3
Explanation: Pick B and insert at front, EACBD => BEACD
             Pick A and insert at front, BEACD => ABECD
             Pick E and insert at front, ABECD => EABCD*/

int solve(string a, string b) {
	map<char, int> f;
	for (char c : a) f[c]++;
	for (char c : b) f[c]--;
	for (auto [c, cnt] : f) if (cnt) return -1;

	int i = a.size() - 1, j = b.size() - 1;
	int ans = 0;
	while (i >= 0) {
		while (i >= 0 and a[i] != b[j]) {
			ans++;
			--i;
		}

		if (i >= 0) {
			--i;
			--j;
		}
	}

	return ans;
}