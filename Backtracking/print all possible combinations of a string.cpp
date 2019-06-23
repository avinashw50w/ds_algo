/*Print all possible combinations of a string. 
eg. AABC: '', A, AA, AAB, AABC, AAC, AA, AAB, AABC, AAC, AB, ABC, AC, A, AA, AAB, AABC, AAC, AB, ABC, AC, B, BC, C */

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> f;

void print(char s[], int n) {
	for (int i = 0; i < n; ++i) cout << s[i];
	cout << ", ";
}

void printCombinations(string s, char out[], int pos, int len) {
	
	print(out, len);

	for (int i = pos; i < s.size(); ++i) {
		if (f[s[i]] == 0) continue;

		out[len] = s[i];

		f[s[i]]--;

		printCombinations(s, out, i, len+1);

		f[s[i]]++;
	}
}


int main() {

	string s; s = "AABC";

	for (int i = 0; i < s.size(); ++i) {
		f[s[i]]++;
	}

	char out[s.size()];

	printCombinations(s, out, 0, 0);
}