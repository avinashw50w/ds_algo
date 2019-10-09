/*Transform One String to Another using Minimum Number of Given Operation
Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. 
If yes, then output minimum no. of operations required for transformation.

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
	int n = a.size(), m = b.size();
	if (n != m) return 0;

	int f[26] = {0};

	// check if both a and b contains the same characters
	for (int i = 0; i < n; ++i) f[a[i]-'a']++;
	for (int i = 0; i < n; ++i) f[b[i]-'a']--;

	for (int i = 0; i < 26; ++i) if (f[i] != 0) return 0;

	int res = 0;

	for (int i = n-1, j = n-1; i >= 0; --i) {

		while (i >= 0 and a[i] != b[j]) i--, res++;

		if (i >= 0) i--, j--;
	}

	return res;
}

