/*We have a bag containing A gold coins, B silver coins, and C bronze coins.
Until the bag contains 100 coins of the same color, we will repeat the following operation:

Operation: Randomly take out one coin from the bag. (Every coin has an equal probability of
 being chosen.) Then, put back into the bag two coins of the same kind as the removed coin.

Find the expected value of the number of times the operation is done.

Constraints
0≤A,B,C≤99
A+B+C≥1

removing 1 and then adding two coins means we are increasing that coin by 1.
*/
const int maxn = 101;
double dp[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];

int solve(int A, int B, int C) {
	if (A == 100 or B == 100 or C == 100) return 0;

	if (vis[A][B][C]) return dp[A][B][C];
	vis[A][B][C] = 1;

	int s = A + B + C;
	double ans = 1 + 1.0 * A / S * solve(A + 1, B, C) + 1.0 * B / S * solve(A, B + 1, C)
	             + 1.0 * C / S * solve(A, B, C + 1);

	return dp[A][B][C] = ans;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << setprecision(12);
	cout << fixed;
	cout << solve(a, b, c);
}