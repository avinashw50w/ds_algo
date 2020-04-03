#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9 + 2;
int D, A, M, B, X;

long long solve(long long x) {
    long long amt = D;
    amt += (x / (M+1)) * (A*M) + (x / (M+1)) * B + (A * (x % (M+1)));
    
    return amt >= X;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> D >> A >> M >> B >> X;

        int l = 0, r = maxn;
        int mid, ans = -1;
        while (l <= r) {
            
            mid = (l+r)>>1;
            
            if (solve(mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        cout << ans << endl;
    }
}