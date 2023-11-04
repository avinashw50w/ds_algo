/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.*/

class Solution {
public:
	int reverse(int x) {
		int last, ans = 0;
		while (x) {
			last = x % 10;
			x /= 10;
			if (ans > INT_MAX / 10 or (ans == INT_MAX / 10 and last > 7)) return 0;
			if (ans < INT_MIN / 10 or (ans == INT_MIN / 10 and last < -8)) return 0;
			ans = ans * 10 + last;
		}

		return ans;
	}
};