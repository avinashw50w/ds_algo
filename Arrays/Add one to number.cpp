/*Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

eg. 0 1 2 3  => 124
9 9 => 100 */

vector<int> solve(vector<int> &A) {
	int n = A.size();
	vector<int> res;
	int sum = 0, carry = 0;

	for (int i = n-1; i >= 0; --i) {
		sum = A[i] + carry;
		carry = sum/10;
		sum  %= 10;

		res.push_back(sum);
	}

	if (carry) res.push_back(carry);

	while(res[res.size()-1] == 0) res.pop_back();
	reverse(res.begin(), res.end());

	return res;
}
