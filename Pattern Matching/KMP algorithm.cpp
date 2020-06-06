#include <bits/stdc++.h>
using namespace std;
// Computes length of the longest proper prefix which is
// also a proper suffix for substring [0,i] , 0 <= i <= N-1
/*
Algo: j = 0, i = 1.
If pattern matches then f[i] = j+1, i++, j++;
Otherwise, while pat[i] doesn't match pat[j], do j = f[j-1];
 */
vector<int> LPS(string pat) {
	int l = pat.size(), j = 0;

	vector<int> f(l);
	f[0] = 0;

	for(int i = 1; i < l; ++i) {
		while(j >= 0 and pat[i] != pat[j]) {
			if(j > 0) j = f[j-1];
			else j = -1;
		}
		j++;
		f[i] = j;
	}

	return f;
}

void KMP(string txt, string pat) {

	vector<int> f = LPS(pat);

	int lt = txt.size();
	int lp = pat.size();
	int j = 0;
	for(int i = 0; i < lt; ++i) {
		while(j >= 0 and txt[i] != pat[j]) {
			if(j >= 1) j = f[j-1];
			else j = -1;
		}
		j++;
		if(j == lp) {
			cout << i-j+1 << endl;
			j = f[j-1];
		}
	}
}

int main() {

	string text = "ahgdhkreuwgdhkeiruoktgdhkiuoedlvn";
	string pat = "gdhk";

	KMP(text, pat);

}
