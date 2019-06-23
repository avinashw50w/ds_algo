/*There are N nodes in a graph labeled from 1 to N. Each node has an associated cost with it, given by cost array. 
You wish to connect this graph by constructing edges between the nodes.

You can construct an edge between two nodes a and b iff cost[a] ≥ 0 AND cost[b] ≥ 0
The cost of the construction of the edge is equal to cost[a] + cost[b]
Some edges already exist. Hence, some nodes are already connected. 
You wish to find the minimum cost of connecting the entire graph.

Input
The first line of the input consists of two integers - N and M. N is number of planets and M is number 
of pairs of planets which have a mutual agreement, i.e they have a spaceway between them. 
Then, M lines follow, each containing two space separated integers A and B, 
denoting a mutual agreement and hence a spaceway to travel, between plenet A and planet B. 
Then, N lines follow. The ith line has an integer C. If C ≥ 0, then it represents the tax value 
which the GFA has to pay to the government of planet i (it's a type 1 government). 
If C < 0, then it represents the money the ith government will pay to the GFA (it's a type 2 government).

Output
Print the minimum amount needed for the GFA to fulfill their plan if it can be fulfilled, else print "-1" (without quotes).

Constraints
1 ≤ N ≤ 100,000
0 ≤ M ≤ 1,000,000
0 ≤ |C| ≤ 10,000
1 ≤ A,B ≤ N
A ≠ B*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int INF = 1e8;
int N, M, par[MAXN], src[MAXN], dest[MAXN], C[MAXN];
int MN[MAXN]; // MN[i] stores the cost of the node which has the minimum cost in the set i

int findSet(v) {
	return (v == par[v]) ? v: (par[v] = findSet(v));
}

void Union(int a, int b) {
	a = findSet(a);
	b = findSet(b);

	MN[a] = min(MN[a], MN[b]);
	par[b] = a;
}

bool all_belong_to_same_set(int N) {
	int x = findSet(1);

	for(int i = 2; i <= N; ++i) {
		if(findSet(i) != x)
			return false;
	}
	return true;
}

int main() {

	cin >> N >> M;

	int pos = 0;

	while(M--) {
		cin >> src[pos] >> dest[pos];
		pos++;
	}

	int mini = -1, minCost = INF;

	for(int i = 1; i <= N; ++i) {
		cin >> C[i];

		if(C[i] < 0)
			MN[i] = INF;
		else MN[i] = C[i];

		if( 0 <= C[i] and C[i] < minCost) {
			mini = i;
			minCost = C[i];
		}
	}


	if(mini == -1) {
		cout << -1 << endl;
		return 0;
	}

	for(int i = 1; i <= N; ++i) 
		par[i] = i;

	for(int i = 0; i < pos; ++i) {
		Union(src[i], dest[i]);
	}

	// if all the nodes belong to the same set, 
	// then there is no need to connect any nodes, so cost incurred will be 0
	if(all_belong_to_same_set(N)) {
		cout << 0 << endl;
		return 0;
	}

	int m = mini; // the node with the min cost >= 0
	int ms = findSet(m); // the set in which the min cost node lies
	int cost = 0;

	for(int i = 1; i <= N; ++i) {
		// if the node i lies in the same set whete the min cost node lies, then continue
		if(findSet(i) == ms)
			continue;
		else {
			// find the set in which the node i lies
			int a = findSet(i);
			// find the min cost of the node which lies in the set i
			a = MN[a];

			if(a == INF) {
				cout << -1 << endl;
				return 0;
			}

			cost += a + cost[m];

			Union(m, a);
		}
	}

	cout << cost << endl;
}