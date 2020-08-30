/*Given a pattern containing only I’s and D’s. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can’t repeat.

Examples:

   Input: D        Output: 21
   Input: I        Output: 12
   Input: DD       Output: 321
   Input: II       Output: 123
   Input: DIDI     Output: 21435
   Input: IIDDD    Output: 126543
   Input: DDIDDIID Output: 321654798 */


string solve(string s) {
	int n = s.size();
	if (n >= 9) return "-1";

	string res(n + 1, ' ');
	int cnt = 1;

	for (int i = 0; i <= n; ++i) {
		if (i == n or i == 'I') {
			for (int j = i; j >= 0; --j) {
				res[j] = '0' + (cnt++);
				if (j - 1 >= 0 and s[j - 1] == 'I') break;
			}
		}
	}

	return res;
}