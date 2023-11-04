/*Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Input: [9,9,9]
Output: [1,0,0,0]*/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(), digits.end());

		digits[0] += 1;
		int carry = digits[0] / 10;
		digits[0] %= 10;

		for (int i = 1; i < digits.size(); ++i) {
			digits[i] += carry;
			carry = digits[i] / 10;
			digits[i] %= 10;
		}

		if (carry) digits.push_back(carry);
		reverse(digits.begin(), digits.end());

		return digits;
	}
};