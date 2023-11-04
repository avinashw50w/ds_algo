/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.*/

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.size() < b.size()) swap(a, b);
		int n = a.size(), m = b.size();

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0, i = 0, j = 0;

		while (i < n || j < m) {
			int sum = (i < n ? a[i] - '0' : 0) + (j < m ? b[j] - '0' : 0) + carry;
			carry = sum == 3 ? 1 : sum == 2 ? 1 : 0;
			sum = sum == 3 ? 1 : sum == 2 ? 0 : sum;
			a[i] = sum + '0';

			i++; j++;
		}

		if (carry) a += carry + '0';

		reverse(a.begin(), a.end());

		return a;
	}
};