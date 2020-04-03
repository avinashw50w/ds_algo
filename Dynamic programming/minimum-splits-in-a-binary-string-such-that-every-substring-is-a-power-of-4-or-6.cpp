/*Minimum splits in a binary string such that every substring is a power of 4 or 6.
Given a string S composed of 0 and 1. Find the minimum splits such that the substring is a binary representation 
of the power of 4 or 6 with no leading zeros. Print -1 if no such partitioning is possible.

Examples:

Input: 100110110
Output: 3
The string can be split into a minimum of 
three substrings 100(power of 4), 110
(power of 6) and 110(power of 6).
*/

bool powerOf(int val, int p) {
	while(val > 1) {
		if (val % p != 0) return false;
		val /= p;
	}

	return true;
}

int solve(string s) {

	int n = s.size();

	int dp[n];

	dp[n-1] = (s[n-1] == '0') ? -1: 1;

	for (int i = n-2; i >= 0; --i) {
		if (s[i] == '0') dp[i] = -1;

		int val = 0;
		dp[i] = INT_MAX;

		for (int j = i; j < n; ++j) {
			val = (val * 2) + (s[j] - '0');

			if (powerOf(val, 4) || powerOf(val, 6)) {
				if (j == n-1) dp[i] = 1;
				else {
					if (dp[j+1] != INT_MAX)
						dp[i] = min(dp[i], 1 + dp[j+1]);
				}
			}
		}

		if (dp[i] == INT_MAX)
			dp[i] = -1;
	}

	return dp[0];
}

////////////////////////////////////////////////////
/// my version : going from start
/// dp[i] : splits required for the substring 0...i


#include <bits/stdc++.h>
using namespace std;

int isPowerof(int n, int p) {
	while(n%p == 0) n /=p ;
	return n == 1;
}

int solve(string s) {
	int n = s.size();

	int dp[n];
	fill(dp, dp+n, INT_MAX);

	dp[0] = s[0] == '0'? INT_MAX: 1;

	for (int i = 1; i < n; ++i) {
		int val = 0, mul = 1;
		
		for (int j = i; j > 0; --j) {
			val += (s[j]-'0')*mul;
			mul *= 2;

			if (val == 0) continue;
			if (isPowerof(val, 4) or isPowerof(val, 6)) {
				if (dp[j-1]  != INT_MAX) 
				dp[i] = min(dp[i], 1 + dp[j-1]);
			}
		}
	}

	return dp[n-1];
}


int main() {
	
	cout << solve("100110110");
}