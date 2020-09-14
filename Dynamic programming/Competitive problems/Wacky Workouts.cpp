/*The government of virtualBit believes that the health of its citizens is the highest priority. It has devised an N-day health plan. During these N days, the citizens are encouraged to go to the gym for workouts.

A person may or may not go to the gym on any day. The people of virtualBit are a lazy lot, and they don't want to go to the gym for more than one consecutive day. Given the number of days N, print the number of ways the N-day plan can be completed.

Note that it is possible to not go to the gym on any day at all and still complete the plan.

Input

The first line contains T, the number of test cases.

Each test case contains a number N denoting the number of days.

Output

Each test case contains a single number denoting the number of ways by which the N-day plan may be completed.

Output your answer modulo 109+7.

Constraints

1 <= T <= 60000

1 <= N <= 10^18

SAMPLE INPUT
2
2
3
SAMPLE OUTPUT
3
5
Explanation
In the first test case the plan can be completed by going only on the first day, only on the second day or on no day at all.

In the second test case, the plan can be completed by any of the following combinations.

{}, {1}, {2}, {3}, {1,3}*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
const ll mod = 1e9 + 7;
ll n;

typedef vector<vector<ll>> vvi;

vvi mul(vvi a, vvi b) {
    vvi res {{0, 0}, {0, 0}};
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            rep(k, 0, 2)
            res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;

        }
    }
    return res;
}

vvi mpow(vvi a, ll n) {
    vvi res {{1, 0}, {0, 1}}; // identity matrix ( which is similar to value 1 in matrix arithmatic )
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}


ll fib(ll n) {
    vvi a {{1, 1}, {1, 0}};
    vvi ans = mpow(a, n);
    return ans[0][0] % mod;
}
int main() {
    int t;
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << fib(n + 1) << endl;
    }
}