/*Special integer, K, of an array, is an integer such that none of its subarray of size K has sum of elements greater than X.
Find the maximum possible value of K

N <= 10^5
X <= 10^18
1 <= A[i] <= min(X, 10^9)

Input Format:
First line consists of two space separated integers denoting N and X.
Second line consists of N space separated integers denoting the array A.

Output Format:
Print the maximum possible value of special integer.
SAMPLE INPUT 
4 8
1 2 3 4

SAMPLE OUTPUT 
2
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
typedef long long ll;
ll N, X, A[MAXN];

int check(ll k, ll X) {
    ll sum = 0, i;
    for (i = 0; i < N; ++ i) {
        if (sum > X) return 0;
        if (i < k) sum += A[i];
        else {
            sum -= A[i-k];
            sum += A[i];
        }
    }

    return sum <= X;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; ++i) cin >> A[i];

    ll l = 1, r = N, ans = -1;

    while (l <= r) {
        ll mid = (l+r)>>1;
        if (check(mid, X)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << "\n";
}