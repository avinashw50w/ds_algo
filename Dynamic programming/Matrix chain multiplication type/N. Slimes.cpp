/*There are N slimes lining up in a row. Initially, the i-th slime from the left has a size of ai.
Taro is trying to combine all the slimes into a larger slime. He will perform the following operation
repeatedly until there is only one slime:
Choose two adjacent slimes, and combine them into a new slime. The new slime has a size of x + y, where x and y are the sizes of the slimes before combining them. Here, a cost of x + y is incurred. The positional relationship of the slimes does not change while combining slimes.
Find the minimum possible total cost incurred.
Constraints
All values in input are integers.
2≤N ≤400 1≤ai ≤109
Input
Input is given from Standard Input in the following format:
Output
Print the minimum possible total cost incurred.

explanation: cost of combining a,b,c,d = cost of combining(a,b) + cost of combining(c,d) + cost of combining(ab, cd)
                                       = cost of combining(a,b) + cost of combining(c,d) + ((a+b) + (c+d))
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 400 + 5;
const ll INF = 1e18L;
ll dp[maxn][maxn];
ll prefix_sum[maxn];

void min_self(ll &a, ll b) {
    a = min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> slimes(n);
    for (int &x: slimes) cin >> x;

    fill(&dp[0][0], &dp[n][0], INF);
    
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0LL;
        prefix_sum[i] += slimes[i] + (i > 0 ? prefix_sum[i-1] : 0);
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n-len; ++i) {
            int j = i + len - 1;
            ll sum = prefix_sum[j] - (i > 0 ? prefix_sum[i-1] : 0);
            for (int k = i; k < j; ++k) {
                min_self(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
            }
        }
    }

    cout << dp[0][n-1] << "\n";

}