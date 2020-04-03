/*N chef's are there. Each chef has a dish which is given a value (denoted by S[i]). You need to answer 2 queries : 
1. 0 x y : Chef containing dish x competes with chef containing dish y. 
If both dishes belong to same chef print "Invalid Query!" , 
otherwise the winner of the round will obtain all the dishes of the loser which will then be eliminated.
2. 1 x : Output the chef which contains the dish x.

Input
First line of input contains an integer T denoting the number of test cases. For each test case, 
the first line contains an integer N denoting the number of chefs in the contest. 
The next line contains N space separated integers where the ith integer represents S[i]. 
The next line contains an integer Q denoting the number of queries. 
Q lines follow where each line can be of the format 0 x y or 1 x as described in the problem statement.

Output
For each test, print in each line the answer for the queries as described in the problem statement .

Constraints
1 ≤ T ≤ 25
1 ≤ N ≤ 10000(104)
0 ≤ S[i] ≤ 1000000(106)
1 ≤ Q ≤ 10000(104)
1 ≤ x, y ≤ N*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+5;
int N, par[MAXN], rank[MAXN], S[MAXN];


int findSet(int v) {
	return (v == par[v]) ? v: (par[v] = findSet(par[v]));
}

void Union(int x, int y) {
	x = findSet(x);
	y = findSet(y);

	if(x == y) 
		cout << "Invalid query!\n";

	if(S[x] < S[y])
		par[x] = y;
	else if(S[y] < S[x])
		par[y] = x;
}

int main() {
	int T; cin >> T;
	while(T--) {
		cin >> N;

		for(int i = 1; i <= N; ++i) {
			cin >> S[i];
			par[i] = i;
		}

		int Q, c, a, b; 
		cin >> Q;

		while(Q--) {
			cin >> c;

			if(c == 0) {
				cin >> a >> b;
				Union(a, b);
			}
			else {
				cin >> a;
				cout << findSet(a) << endl;
			}
		}
	}
}