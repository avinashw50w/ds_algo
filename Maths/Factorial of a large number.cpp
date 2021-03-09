#include <bits/stdc++.h>
using namespace std;

void multiply(string &s, int x) {
	int carry = 0;
	for (int i = 0; i < s.size(); ++i) {
		int sum = (s[i] - '0') * x + carry;
		carry = sum / 10;
		sum %= 10;
		s[i] = sum + '0';
	}

	if (carry) {
		string t = to_string(carry);
		reverse(t.begin(), t.end());
		s += t;
		// or you can do this
		// while (carry) {
		//     s += (carry % 10) + '0';
		//     carry /= 10;
		// }
	}
}

string factorial(int n) {
	string res = "1";
	for (int i = 2; i <= n; ++i) {
		multiply(res, i);
	}

	reverse(res.begin(), res.end());
	return res;
}

int main() {
	cout << factorial(50);
	return 0;
}