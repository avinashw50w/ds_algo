/*Chef has a string S consisting of N lowercase English alphabets. 
He has prepared a list L consisting of all non empty substrings of the string S.

Now he asks you Q questions. To ith question, you need to count the 
number of ways to choose exactly Ki equal strings from the list L. 
As answer could be large you need to find it modulo 109+7.

Input
The first line of the input contains an integer T denoting the number of test cases. First line of each test case contains 
two space-separated integers N and Q denoting the length of the string S and amount of questions. 
The next line of each test case contains a single string S. Each of the next Q lines contains a single integer Ki.

Output
For each test case, output Q lines, each line should contain one integer - 
amount of ways to choose exactly Ki equal strings from the list L.

Constraints
T = 1
1 ≤ N ≤ 5000
1 ≤ Q ≤ 105
1 ≤ Ki ≤ 109
Example
Input:
1
5 4
ababa
2
1
3
4
Output:
7
15
1
0
Explanation
L = {"a", "b", "a", "b", "a", "ab", "ba", "ab", "ba", "aba", "bab", "aba", "abab", "baba", "ababa"}.

k1 = 2: There are seven ways to choose two equal strings ("a", "a"), ("a", "a"), ("a", "a"), ("b", "b"), ("ab", "ab"), ("ba", "ba"), ("aba", "aba").
k2 = 1: We can choose any string from L (15 ways).
k3 = 3: There is one way to choose three equal strings - ("a", "a", "a").
k4 = 4: There are no four equal strings in L .*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MOD = 1e9 + 7;
typedef long long ll;

string S;
int N;
int Z[MAXN], cnt[MAXN], freq[MAXN];
int nCr[MAXN][MAXN];
ll ans[MAXN];

void init() {
	for(int i = 0; i < MAXN; ++i) {
		Z[i] = 0;
		ans[i] = 0;
		cnt[i] = 0;
		freq[i] = 0;
	}
}

void buildnCr() {
	for(int i = 1; i < MAXN; ++i) nCr[i][1] = i;

	for(int i = 2; i < MAXN; ++i)
		for(int j = 2; j <= i; ++j)
			nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;
}

void buildZ(string S) {
	int N = S.size();
	int L, R, K;
	Z[0] = S.size();

	L = R = 0;

	for(int i = 1; i < N; ++i) {
		if(i < R) {
			L = R = i;
			while(R < N and S[R-L] == S[R]) R++;
			Z[i] = R-L; R--;
		}
		else {
			K = i-L;
			if(Z[k] < R-i+1) Z[i] = Z[k];
			else {
				L = i;
				while(R < N and S[R-L] == S[R]) R++;
				Z[i] = R-L; R--;
			}
		}
	}
}

void preprocess() {

	for(int i = 0; i < N; ++i) {

		for(int j = 1; j <= N; ++j) Z[j] = 0, freq[j] = 0;

		buildZ(S.substr(i));

		for(int j = 0; j < N; ++j) freq[Z[j]]++;

		for(int j = N-1; j >= 1; --j) freq[j] += freq[j+1];

		for(int j = 1; j <= N; ++j) cnt[freq[j]]++;
	}

	ans[1] = (N*(N+1)) >> 1;

	for(int i = 2; i < N; ++i) {
		for(int j = i; i < N; ++j)
			ans[i] = ((cnt[j] - cnt[j+1]) * nCr[j][i]) % MOD;
	}
}

int main() {
	int T; cin >> T;
	int q;

	buildnCr();
	while(T--) {

		init();
		cin >> N >> q;
		cin >> S;

		preprocess();

		while(q--) {
			int K; cin >> K;

			if(K > N) cout << "0\n";
			else cout << ans[K] << endl;
		}
	}
}