/*You are given N stones, labeled from 1 to N. The i-th stone has the weight W[i].
There are M colors, labeled by integers from 1 to M. The i-th stone has the color C[i]
(of course, an integer between 1 to M, inclusive). You want to fill a Knapsack with these stones.
The Knapsack can hold a total weight of X. You want to select exactly M stones; one of each color. The sum of the weights of the stones must not exceed X. You want to fill the Knapsack as much as possible.
Write a program that takes all the above values as input and calculates the best way to
fill the Knapsack – that is, the way that minimizes the unused capacity.
OUTPUT: the unused capacity

Input

The first line of input contains the integer T, the number of test cases. Then follows the description of T test cases. The first line of each test case contains three integers, N, M and X, separated by singlespace. The next line contains N integers, W[1], W[2], W[3] … W[N], separated by single space. The next line contains N integers C[1], C[2], C[3] … C[N], separated by single space.

Output

An optimal way of filling the Knapsack minimizes unused capacity. There may be several optimal ways of filling the Knapsack. Output the unused capacity of the Knapsack (a single integer on a line by itself) for an optimal way. If there is no way to fill the Knapsack, output -1. Output T lines, one for each test case.

Constraints

1 ≤ T ≤ 10

1 ≤ M ≤ 100

M ≤ N ≤ 100

1 ≤ W[i] ≤ 100

1 ≤ C[i] ≤ M

1 ≤ X ≤ 10000*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))

const int maxx = 10101;
const int maxn = 101;

int W[maxn];
// dp[i][j] : whether its possible to fill stones of color 1 to i with a total weight of j
bool dp[maxn][maxx];

vector<int> v[maxn];

int main() {
	int t; cin >> t;

	int N, M, X;

	while (t--) {

		cin >> N >> M >> X;

		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		rep(i, 0, M + 1) v[i].clear();

		rep(i, 1, N + 1) cin >> W[i];

		rep(i, 1, N + 1) {
			int color;
			cin >> color;
			v[color].push_back(W[i]);
		}

		// iterate through each color
		rep(i, 1, M + 1) {

			int sz = v[i].size();
			// iterate through stones of color i
			rep(j, 0, sz) {

				for (int k = 0; k + v[i][j] <= X; ++k)

					dp[i][k + v[i][j]] |= dp[i - 1][k];

			}
		}

		int ans = -1;

		for (int k = X; k >= 0; --k)
			if (dp[M][k]) {
				ans = X - k;
				break;
			}

		cout << ans << endl;
	}

	return 0;
}