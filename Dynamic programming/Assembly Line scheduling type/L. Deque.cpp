/*/*Taro and Jiro will play the following game against each other.

Initially, they are given a sequence (a1,a2,a3...an). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:

Remove the element at the beginning or the end of a. The player earns x points, where x is the removed element.
Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize
X - Y, while Jiro tries to minimize X- Y.

Assuming that the two players play optimally, find the resulting value of X - Y.

Constraints
All values in input are integers.
1 ≤ N ≤ 3000
1 ≤ ai ≤ 10^9
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3000 + 2;
ll dp[maxn][maxn];
int a[maxn];

ll solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    ll &res = dp[l][r];
    if (res != -1) return res;

    ll op1 = a[l] + min(solve(l + 2, r), solve(l + 1, r - 1));
    ll op2 = a[r] + min(solve(l, r - 2), solve(l + 1, r - 1));

    res = max(res, max(op1, op2));
    return res;
}

int main() {

    int n;
    scanf("%d", &n);
    ll sum = 0L;

    for (int &x : a) {
        scanf("%d", &x);
        sum += x;
    }

    memset(dp, -1, sizeof(dp));

    cout << (2 * solve(0, n - 1) - sum);
}