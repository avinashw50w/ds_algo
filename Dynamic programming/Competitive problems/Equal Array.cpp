/*GIven and array A of integers of size N. Find the min non -ve integer X such that adding X to A[j]
makes the sum of elements from index 1 to j and j+1 to N equal. 1 <= j <= N-1.
if No such X exists then print -1;
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+2;
ll a[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        for (int i = 1; i < n; ++i) a[i] += a[i-1];
        
        ll ans = a[n-1] + 2;

        for (int i = 0; i < n-1; ++i) {
            ll diff = a[i] - (a[n-1] - a[i]);
            if (diff <= 0) ans = min(ans, abs(diff));
        }
    
        cout << (ans > a[n-1] ? -1 : ans) << endl;
    }
}