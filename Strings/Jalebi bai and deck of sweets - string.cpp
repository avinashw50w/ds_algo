/*given two strings A and B, our task is to make them equal.
we can perform the following operation:
1. Pick any two consecutive characters which are equal from any one of the string and remove one of the characters from it.
Print YES if it is possible otherwise print NO

eg. A - rrrjj
	B - rrjj

We can pick two consecutive r's from A and remove one r from it, so A becomes rrjj = B. So ans is YES*/

#include <iostream>
#include <algorithm>
using namespace std;

int solve(string A, string B) {
	int ret = 0;
	int lA = unique(A.begin(), A.end()) - A.begin();
	int lB = unique(B.begin(), B.end()) - B.begin();

	if(lA != lB) return ret;

	for(int i = 0; i < lA; ++i)
		if(A[i] != B[i])
			return ret;

	return 1;
}

int main() {
	string A, B;

	cin >> A >> B;

	puts(solve(A, B) ? "YES" : "NO");
}