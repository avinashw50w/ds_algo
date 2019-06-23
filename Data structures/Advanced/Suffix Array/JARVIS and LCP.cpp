/*JARVIS(Just A Rather Very Intelligent System) has still many things to learn to become more intelligent. 
Tony Stark wants to teach Competitive Programming to it. So he starts directly with Strings and tells JARVIS 
about Longest Common Prefix(LCP) of two strings. Also Tony gives JARVIS a set of strings S1, S2, ..., Sn. 
JARVIS starts playing with those strings and comes up with a problem. The problem is as follows, 

If LCP of Xth and Yth strings is L then how many times L occures in the set as a substring of any string? 

JARVIS comes with many such X's and Y's to Pepper. Being very busy, she asks you to tell the answers of the JARVIS' quesions. 
Can you help her answering the questions?
Input
The first line contains N, the number of strings in the set.
The Next N lines contain the strings of the given set.
The next line contains Q, the number of questions.
Each line of the next Q lines contains Xi and Yi, the indexes(1-based) of the two strings of ith question.
Output
For each question, output on a separate line the answer of the question.
Constraints
1 ≤ N ≤ 105
1 ≤ Length of Si ≤ 105
1 ≤ Q ≤ 105
1 ≤ Xi ≤ Yi ≤ N
Sum of lengths of all strings ≤ 5*105
Strings contain only lower case letters.*/

#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 5 * (int)1e3 + 2;
const int MAXN = 1e3+2;
const int LOGN = 22;

int n, N;
string S;
int lind[MAXN], SA[MAXLEN], lcp[MAXLEN], inv[MAXLEN], id[MAXLEN], _log[MAXLEN], LCP[MAXLEN][LOGN];
vector<string> inp;

struct suffix {
	int idx;
	int rank[2];
} L[MAXLEN];

bool cmp(struct suffix a, struct suffix b) {
	if(a.rank[0] == b.rank[0]) return a.rank[1] < b.rank[1];
	return a.rank[0] < b.rank[0];
}

void buildSuffixArray() {

	for(int i = 0; i < N; ++i) {
		L[i].idx = i;
		L[i].rank[0] = S[i] - 'a';
		L[i].rank[1] = i+1 < N ? S[i+1] - 'a' : -1;
	}

	sort(L, L+N, cmp);

	for(int k = 4; k < 2*N; k *= 2) {
		int rank, prev_rank;
		rank = 0;
		prev_rank = L[0].rank[0];
		L[0].rank[0] = 0;
		id[L[0].idx] = 0;

		for(int i = 1; i < N; ++i) {
			if(L[i].rank[0] == prev_rank && L[i].rank[1] == L[i-1].rank[1]) {
				L[i].rank[0] = rank;
			}
			else
			{
				prev_rank = L[i].rank[0];
				L[i].rank[0] = ++rank;
			}

			id[L[i].idx] = i;
		}

		for(int i = 0; i < N; ++i) {
			int nextIdx = L[i].idx + (k>>1);
			L[i].rank[1] = nextIdx < N ? L[id[nextIdx]].rank[0] : -1;
		}

		sort(L, L+N, cmp);
	}

	for(int i = 0; i < N; ++i) 
		SA[i] = L[i].idx;
}

void buildLCP() {
	int k = 0;

	for(int i = 0; i < N; ++i) inv[SA[i]] = i;

	for(int i = 0; i < N; ++i) {
		if(inv[i] == N-1) {
			k = 0;
			continue;
		}

		int j = SA[inv[i]+1];
		while(i+k < N and j+k < N and S[i+k] == S[j+k]) k++;

		lcp[inv[i]] = k;
		if(k) --k;
	}
}

void buildLog() {
	_log[1] = 0;
	for(int i = 2; i < MAXLEN; ++i)
		_log[i] = _log[i/2] + 1;
}

void buildSparseLCP() {

	buildLog();

	for(int i = 0; i < N; ++i) LCP[i][0] = lcp[i];

	for(int j = 1; (1<<j) <= N; ++j)
		for(int i = 0; i + (1<<j) <= N; ++i)
			LCP[i][j] = min(LCP[i][j-1], LCP[i + (1<<(j-1))][j-1]);
}

int query(int L, int R) {

	if(L == R) return N - SA[L];
	R--;
	int j = _log[R-L+1];
	return min(LCP[L][j], LCP[R-(1<<j)+1][j]);
}

int niche(int x, int y, int L) {
	int l, r, mid, lower;
	l = 0, r = lower = x;

	while(l <= r) {
		mid = (l+r) >> 1;
		if(query(mid, x) < L) l = mid + 1;
		else {
			r = mid - 1;
			lower = min(lower, mid);
		}
	}
	return lower;
}

int upar(int x, int y, int L) {
	int l, r, mid, upper;
	l = upper = x, r = N-1;

	while(l <= r) {
		mid = (l+r) >> 1;
		if(query(max(x, y-1), mid) < L) r = mid-1;
		else {
			l = mid + 1;
			upper = max(upper, mid);
		}
	}
	return upper;
}

int main() {
	cin >> n;

	for(int i = 0; i < n; ++i) {
		if(i) S += "$";
		string tmp; cin >> tmp;
		lind[i] = S.length();
		S += tmp;
		inp.push_back(tmp);
	}

	S += "$";
	N = S.length();

	buildSuffixArray();
	buildLCP();
	buildSparseLCP();
	
	
	// set<string> st;
	// cout << "SUFFIXES: ";
	// for(int i = 0; i < S.length(); ++i) { st.insert(S.substr(i)); cout << S.substr(i) <<", "; } cout << "\n\n";
	// cout << "SORTED SUFFIXES: ";
	// for(auto i: st) cout << i << ", "; cout << "\n\n";
	// cout << "SUFFIX ARRAY: ";
	// for(int i = 0; i < 20; ++i) cout << SA[i] <<", "; cout << "\n\n";
	// cout << "INVERSE: ";
	// for(int i = 0; i < 20; ++i) cout << inv[i] << ", "; cout << "\n\n";
	// cout << "LCP ARRAY: ";
	// for(int i = 0; i < 20; ++i) cout << lcp[i] << ", "; cout << "\n\n";
	

	int q, u, v, x, y;

	cin >> q;

	while(q--) {
		cin >> u >> v;
		u--;
		v--;

		x = inv[lind[u]]; // position of uth string in the suffix array
		y = inv[lind[v]]; // position of vth string in the suffix array

		if(x > y) swap(x, y);

		int L = query(x, y); // find LCP of both the strings
		int t = min(inp[u].length(), inp[v].length());
		if(L > t) L = t;

		if(L == 0) {
			cout << "0" << endl;
			continue;
		}

		int lower = niche(x, y, L);

		int upper = upar(x, y, L);

		cout << upper - lower + 1 << endl;
	}
} 
