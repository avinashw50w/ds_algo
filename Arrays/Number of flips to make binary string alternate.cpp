/*Given a binary string, that is it contains only 0s and 1s. We need to make this string a
sequence of alternate characters by flipping some of the bits, our goal is to minimize the
number of bits to be flipped.
Examples :

Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th
bit from 1 to 0 to make alternate
string “0101010101”.*/

int solve(string s, char required) {
	int flips = 0;
	for (char c : s) {
		flips += c != required;
		required = required == '0' ? '1' : '0';
	}
	return flips;
}

int flips(string s) {
	return min(solve(s, '0'), solve(s, '1'));
}

// Approach 2:
// type 1: 010101
// type 2: 1010101
// count the no of replacements 'cnt' to convert the string to type 1,
// then ans = min(cnt, len - cnt), where len is the size of the string
// here len - cnt is the no of no of replacements to convert str to type 2

int solve(string s) {
	int n = s.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1 and s[i] == '0') cnt++;
		if (i & 1 ^ 1 and s[i] == '1') cnt++;
	}
	return min(cnt, n - cnt);
}