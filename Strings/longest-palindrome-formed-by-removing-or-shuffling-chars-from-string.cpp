/*Find longest palindrome formed by removing or shuffling chars from string
Given a string, find the longest palindrome that can be constructed by removing or shuffling characters from the string.
Return only one palindrome if there are multiple palindrome strings of longest length.

The idea is to use above observation in our solution. As shuffling of characters is allowed, order of characters doesn’t matter in the input string.
We first get frequency of each character in the input string. Then all characters having even occurrence (say 2n) in the input string will be
part of the output string as we can easily place n characters in ‘beg’ string and the other n characters in the ‘end’ string (by preserving
the palindromic order). For characters having odd occurrence (say 2n + 1), we fill ‘mid’ with one of all such characters. and remaining 2n
characters are divided in halves and added at beginning and end.*/

string longestPalindrome(string s) {

	int n = s.length();

	map<char, int> f;
	for (char c : s) f[c]++;

	string beg = "", end = "", mid = "";

	for (auto [c, cnt] : f) {
		if (cnt & 1) mid = c;
		beg += string(cnt / 2, c);
	}

	end = beg;

	reverse(end.begin(), end.end());

	return (beg + mid + end);
}