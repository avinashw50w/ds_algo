#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60606;
const int LOGN = 18;

struct entry{
	int rk[2];
	int idx;

} L[MAXN];

int P[LOGN][MAXN];

char S[MAXN];

bool comp(struct entry a, struct entry b) {
	return a.rk[0] == b.rk[0] ? (a.rk[1] < b.rk[1] ? 1: 0) : (a.rk[0] < b.rk[0] ? 1: 0);
}

int main() {
	gets(S);

	int N = strlen(S);
	for(int i=0; i<N; ++i) P[0][i] = S[i] - 'a';

	for(int step=1, cnt=1; cnt < N; step++, cnt *= 2) {

		for(int i=0; i<N; ++i) {
			L[i].rk[0] = P[step-1][i];
			L[i].rk[1] = i + cnt < N ? P[step-1][i+cnt] : -1;
			L[i].idx = i;
		}

		sort(L, L+N, comp);

		for(int i=0; i<N; ++i)
			P[step][L[i].idx] = ( i>0 && L[i].rk[0] == L[i-1].rk[0] && L[i].rk[1] == L[i-1].rk[1] ? P[step][L[i-1].idx] : i );

		return 0;
	}
}