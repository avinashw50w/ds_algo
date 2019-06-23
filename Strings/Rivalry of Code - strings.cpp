/*Given two string A and B, convert A to B using only the following operations : 
1. Add one or more characters
2. Replacing one character with another

operation 1. does not consume time 
operation 1. consumes 1 unit of time 

find the minimum time to convert string A to B */

/*we just need to check how many characters of A match with B (index wise) and then subtract it from A's length*/

#include <bits/stdc++.h>
using namespace std;

int findMatch(string A, string B, int offset) {
	int cnt = 0;

	for(int i = 0; i < A.size(); ++i)
		if(A[i] == B[i+offset]) cnt++;

	return cnt;
}

int solve(string A, string B) {
	int n = A.length(), m = B.length();
	int cnt = 0, res = 0;

	for(int i = 0; i < abs(n - m) + 1; ++i) {
		cnt = 0;
		cnt = findMatch(A, B, i);
		res = max(res, cnt);
	}
	return n - res;
}

int main() {
	string A, B;
	cin >> A >> B;

	cout << solve(A, B) << endl;
}