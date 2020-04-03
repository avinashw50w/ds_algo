/*In Ancient Berland, there were N towns, along with M bidirectional roads connecting them. 
With time, some roads became unusable, and nobody repaired them.

As a person who is fond of Ancient Berland history, you now want to undertake a small research study. 
For this purpose, you want to write a program capable of processing the following kinds of queries:

D K : meaning that the road numbered K in the input became unusable. The road numbers are 1-indexed.
P A x : meaning that the population of the Ath town became x.
Let's call a subset of towns a region if it is possible to get from each town in the subset to every 
other town in the subset by the usable (those, which haven't already been destroyed) roads, possibly, 
via some intermediary cities of this subset. The population of the region is, then, the sum of populations 
of all the towns in the region.

You are given the initial road system, the initial population in each town and Q queries, each being one of two types above. 
Your task is to maintain the size of the most populated region after each query.

Input
The first line of each test case contains three space-separated integers — N, M, and Q — denoting the number of cities, 
the number of roads, and the number of queries, respectively.

The following line contains N space-separated integers, the ith of which denotes the initial population of the ith city.

The jth of the following M lines contains a pair of space-separated integers — Xj, Yj — denoting that there is a 
bidirectional road connecting the cities numbered Xj and Yj.

Each of the following Q lines describes a query in one of the forms described earlier.

Output
Output Q lines. On the ith line, output the size of the most populated region after performing i queries.

Constraints
1 ≤ Xj, Yj ≤ N
Roads' numbers are 1-indexed.
There is no road that gets removed twice or more.
1 ≤ Pi ≤ 105
Subtask 1 (30 points) : 1 ≤ N, M, Q ≤ 103
Subtask 2 (70 points) : 1 ≤ N, M, Q ≤ 5 × 105
Example
Input:
3 3 6
1 2 3
1 2
2 3
3 1
P 1 3
D 1
P 2 3
D 2
P 3 10
D 3

Output:
8
8
9
6
13
10*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

multiset<long long> S;

int n, m, q, x[MAXN], y[MAXN], A[MAXN], B[MAXN], par[MAXN], popul[MAXN], popul_before[MAXN];
long long region_popul[MAXN], ans[MAXN];
bool del[MAXN];
string type[MAXN];

long long most_populated_region_size() {
	auto it = S.end(); --it;
	return *it;
}

int findSet(int v) {
	return (v == par[v]) ? v : (par[v] = findSet(par[v]));
}

void link(int x, int y) {
	x = findSet(x);
	y = findSet(y);

	if(x == y) return;

	S.erase(S.find(region_popul[x]));
	S.erase(S.find(region_popul[y]));

	region_popul[y] += region_popul[x];
	S.insert(region_popul[y]);
	par[x] = y;
}

int main() {

	cin >> n >> m >> q;

	for(int i = 1; i <= n; ++i) 
		cin >> popul[i];

	for(int i = 1; i <= m; ++i)
		cin >> x[i] >> y[i];

	for(int i = 1; i <= q; ++i) {
		cin >> type[i];
		if(type[i] == "D") {
			cin >> A[i];
			del[A[i]] = true;
		}
		else {
			cin >> A[i] >> B[i];
			popul_before[i] = popul[A[i]];
			popul[A[i]] = B[i];
		}
	}

	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		region_popul[i] = popul[i];
		S.insert(region_popul[i]);
	}

	for(int i = 1; i <= m; ++i) {
		if(!del[i])
			link(x[i], y[i]);
	}

	ans[q] = most_populated_region_size();

	for(int i = q; i >= 1; --i) {
		if(type[i] == "D") {
			link(x[A[i]], y[A[i]]);
		}
		else {
			int region_id = findSet(A[i]);
			S.erase(S.find(region_popul[region_id]));
			region_popul[region_id] -= popul[A[i]];
			popul[A[i]] = popul_before[i];
			region_popul[region_id] = popul[A[i]];
			S.insert(region_popul[region_id]);
		}

		ans[i-1] = most_populated_region_size();
	}

	for(int i = 1; i <= q; ++i)
		cout << ans[i] << endl;
} 