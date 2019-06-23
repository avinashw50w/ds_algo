#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int dp[10004];

void add_self(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int x, k;
    while (t--) {   
        cin >> x >> k;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i <= x; ++i) {
            for (int j = i+1; j <= min(i+k, x); ++j)
                add_self(dp[j], dp[i]);
        }
        cout << dp[x] << "\n";
    }
}