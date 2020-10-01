/* You are given a rooted Tree of N ( 10^5 nodes ). There would be M updates (10^5) to the tree which are of the form

Add x y – Add y to node x .

AddUp x y – Add y to x , parent of x , parent of parent of x  uptill Root.

After that there will be Q queries ( 10^5) of the form:
VAL x: value of node x
SUB x: sum of subtree rooted at x

INPUT: first line is the no of test cases
second line contains N, M and Q, representing the no of nodes, no of operations and no of queries
in the next N lines, the ith line represents the parent of i
next M lines are the operations of the from x y
next Q lines are the queries
Hint : Lazy Update as queries have no update value query.*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))

typedef int64_t ll;

const int mod = (int)1e9 + 7;
const int SZ = 100000 + 5;


struct node {

	ll value, upval, total;

} tree[SZ];

int par[SZ];


int main() {
	int test; cin >> test;

	int N, M, Q;

	while (test--) {

		cin >> N >> M >> Q;

		rep(i, 1, N + 1) {

			cin >> par[i];

			tree[i].value = tree[i].upval = tree[i].total = 0LL;

		}

		ll X, Y;

		string type;

		while (M--) {

			cin >> type >> X >> Y;

			if (type == "ADD")
				tree[X].value = (tree[X].value + Y) % mod;

			else
				tree[X].upval = (tree[X].upval + Y) % mod;

		}

		for (int i = N; i >= 1; --i) {

			tree[i].value = (tree[i].value + tree[i].upval) % mod;

			tree[i].total = (tree[i].total + tree[i].value) % mod;

			tree[par[i]].upval = (tree[par[i]].upval + tree[i].upval) % mod;

			tree[par[i]].total = (tree[par[i]].total + tree[i].total) % mod;
		}

		while (Q--) {

			cin >> type >> X;

			if (type == "VAL") cout << tree[X].value << endl;

			else cout << tree[X].total << endl;
		}
	}
}