/*There are N dishes, numbered 1,2,..N.Initially, for each i (1≤i≤N), Dish i has ai (1≤ai≤3)
pieces of sushi on it.
Taro will perform the following operation repeatedly until all the pieces of sushi are eaten:
Roll a die that shows the numbers 1,2,…,N with equal probabilities, and let i be the outcome.
If there are some pieces of sushi on Dish i, eat one of them; if there is none, do nothing.
Find the expected number of times the operation is performed before all the pieces of sushi are eaten.
Constraints
All values in input are integers.
1≤N≤300
1≤ai≤3
*/

/*First : what really matters is the number of dishes with 0, 1, 2 and 3 sushis and not the order of the dishes.
So answer for 2,1,0,2,1 is same as answer for 0,1,1,2,2.

Number of dishes with 0 sushis is easily determined by N - one - two - three, where one is the
number of dishes with 1 sushi and N is the total number of dishes in the input.

Let F(x, y, z) be the expected moves needed for x dishes with 1 sushi, y with 2 and z with 3.

Now in the next move we can pick a dish with 1 sushi with a probability of x/N or p1.
we can pick a dish with 2 sushi with a probability of y/N or p2. we can pick a dish with 3
sushi with a probability of z/N or p3. we can pick a dish with 0 sushi with a probability of
(N - (x + y + z))/N or p0.

Now try to understand this :
F(x,y,z) = 1 + p0 * F(x,y,z) + p1 * F(x-1,y,z) + p2 * F(x+1,y-1,z) + p3 * F(x,y+1,z-1)

Here we add a 1 for the current move that we are making.
(Note : if you pick a dish with 3 sushi z decreases but y increases)

This equation now becomes :
(1 - p0) F(x,y,z) = 1 + p1 * F(x-1,y,z) + p2 * F(x+1,y-1,z) + p3 * F(x,y+1,z-1)

simplifies to:
F(x,y,z) = (1 + p1 * F(x-1,y,z) + p2 * F(x+1,y-1,z) + p3 * F(x,y+1,z-1)) / (1 - p0)
F(x,y,z) = (N * (1 + p1 * F(x-1,y,z) + p2 * F(x+1,y-1,z) + p3 * F(x,y+1,z-1))) / (x + y + z)
F(x,y,z) = (N + x * F(x-1,y,z) + y * F(x+1,y-1,z) + z * F(x,y+1,z-1))) / (x + y + z)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 305;
int n;
double dp[maxn][maxn][maxn];

double solve(int a, int b, int c) {
	if (a < 0 or b < 0 or c < 0) return 0.0;
	if (a == 0 and b == 0 and c == 0 ) return 0.0;
	if (dp[a][b][c] > 0) return dp[a][b][c];

	int total = a + b + c;
	double exp_val = n + a * solve(a - 1, b, c) + b * solve(a + 1, b - 1, c) + c * solve(a, b + 1, c - 1);

	return dp[a][b][c] = exp_val / total;
}

int main() {
	cin >> n;
	vector<int> cnt(4, 0);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		cnt[x]++;
	}

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= n; ++k)
				dp[i][j][k] = -1;

	double ret = solve(cnt[1], cnt[2], cnt[3]);
	cout << std::setprecision(12);
	cout << ret << endl;
}