/*Split the binary string into substrings with equal number of 0s and 1s
eg. Input: str = “0100110101”
Output: 4
The required substrings are 01 | 0011 | 01 | 01
*/

int splits(string s) {
	int c0 = 0, c1 = 0, cnt = 0;
	for (char c : s) {
		if (c == '0') c0++;
		else c1++;
		if (c0 == c1) cnt++;
	}
	if (c0 != c1) return -1;
	return cnt;
}

// another way
int splits(string s) {
	char a = s[0];
	int cnt = 0, ans = 0;
	for (char c : s) {
		if (c == a) cnt++;
		else cnt--;
		ans += cnt == 0;
	}

	if (cnt != 0) return -1;
	return ans;
}