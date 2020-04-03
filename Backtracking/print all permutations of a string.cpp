/*Print all possible permutations of a string. 
eg. AABC: AABC, AACB, AABC, AACB, ABAC, ABAC, ABCA, ABCA, ACAB, ACAB, ACBA, ACBA, AABC, AACB, AABC, AACB, ABAC, 
ABAC, ABCA, ABCA, ACAB, ACAB, ACBA, ACBA, BAAC, BAAC, BACA, BACA, BAAC, BAAC, BACA, BACA, BCAA, BCAA, BCAA, 
BCAA, CAAB, CAAB, CABA, CABA, CAAB, CAAB, CABA, CABA, CBAA, CBAA, CBAA, CBAA */

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> f;

void print(char s[], int n) {
	for (int i = 0; i < n; ++i) cout << s[i];
	cout << ", ";
}

void printPermutations(string s, char out[], int len) {
	
	if (len == s.size()) {
		print(out, len);
		return;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (f[s[i]] == 0) continue;

		out[len] = s[i];

		f[s[i]]--;

		printPermutations(s, out, len+1);

		f[s[i]]++;
	}
}


int main() {

	string s; s = "AABC";

	for (int i = 0; i < s.size(); ++i) {
		f[s[i]]++;
	}

	char out[s.size()];

	printPermutations(s, out, 0);
}