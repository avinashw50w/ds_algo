/*You are given an array A consisting of N elements. Your task is to find the maximal subarray sum after applying the following operation exactly once:

Select any subarray and set all the elements in it to zero.*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), left(n), right(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        left[i] = max(left[i], sum);
        sum = max(sum, 0LL);
    }

    sum = 0;
    for (int i = n-1; i >= 0; --i) {
        sum += a[i];
        right[i] = max(right[i], sum);
        sum = max(sum, 0LL);
    }

    ll leftmax = 0, ans = 0;

    for (int i = 0; i < n; ++i) {
        ans = max(ans, leftmax + right[i]);
        leftmax = max(leftmax, left[i]);
    }
    ans = max(ans, leftmax);

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}