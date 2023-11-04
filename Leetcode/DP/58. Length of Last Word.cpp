/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World  "
Output: 5*/

class Solution {
public:
	int lengthOfLastWord(string s) {
		int ans = 0;

		int i = s.size() - 1;
		while (i >= 0 and s[i] == ' ') i--;
		for (; i >= 0; --i) {
			if (s[i] == ' ') break;
			ans++;
		}

		return ans;
	}
};