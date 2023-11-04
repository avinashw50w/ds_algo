/*Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.*/

class Solution {
public:
	bool isPalindrome(int x) {
		stringstream ss;
		string s;
		ss << x;
		ss >> s;

		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l] != s[r]) return false;
			l++; r--;
		}
		return true;
	}
};