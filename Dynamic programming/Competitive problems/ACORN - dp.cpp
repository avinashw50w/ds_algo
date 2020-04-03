/*Abridged problem statement: Given t oak trees, the height h of all trees, the height f that Jayjay
loses when it flies from one tree to another,i.e, Jayjay should descend at max to height f when flying from 
one tree to another, 1 ≤ t, h ≤ 2000, 1 ≤ f ≤ 500, and the positions of acorns
on each of oak trees: acorn[tree][height], determine the maximum number of acorns that Jayjay
can collect in one single descent.

Na¨ıve DP Solution: Use a memo table total[tree][height] that stores the best possible acorns
collected when Jayjay is on a certain tree at certain height. Then Jayjay recursively tries to either
go down (-1) unit on the same oak tree or flies (-f) unit(s) to t−1 other oak trees from this position.
This approach requires up to 2000 × 2000 = 4M states and has time complexity 4M × 2000 = 8B
operations. This approach is clearly TLE!
Better DP Solution: We can actually ignore the information: “on which tree Jayjay is currently
at” as just memoizing the best among them is sufficient. Set a table: dp[height] that stores the
best possible acorns collected when Jayjay is at this height. The bottom-up DP code that requires
only 2000 = 2K states and time complexity of 2000 × 2000 = 4M is as follow:*/

const int MAXN = 2001;

int acorn[MAXN][MAXN];
int dp[MAXN];
int t, h, f;

int solve() {
	for (int tree = 0; tree < t; ++tree)
		dp[h] = max(dp[h], acorn[tree][h]);

	for (int height = h-1; height >= 0; --height) {
		for (int tree = 0; tree < t; ++tree) {
			acorn[tree][height] += max(acorn[tree][height+1], (height + f <= h) ? dp[height+f] : 0);
			dp[height] = max(dp[height], acorn[tree][height]);
		}
	}

	return dp[0];
}

