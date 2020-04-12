/*Little monk has travelled across the world but he has never seen a place like byteland. The mountains in the byteland have a unique order. Height of ith mountain is represented by an interval (li, ri) i.e. the height of the mountain is in increasing order, li, li+1, li+2, ... ri.
The heights of mountains are such that if i < j then ri < lj. Now the little monk wants to know xth smallest height in the byteland.

Note: x will be always in the given range of intervals.

Input Format:
First line contains two space separated integers, N  and Q , number of mountains and number of queries.
Next N lines contains two separated integers each,  and  .  line contains the starting height and the end height of the ith mountain.
Next Q lines contains one integer, x , each, denoting the queries.

N <= 10^5
Q <= 10^5
li, ri <= 10^18

Output Format:
For each query, print  smallest height in the byteland.

SAMPLE INPUT 
3 3
1 10
11 20
21 30
5
15
25*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;

int main() {
    cin >> n >> q;
    ll a[n+1], l[n+1], r[n+1];

    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        a[i] = a[i-1] + (r[i] - l[i] + 1);
    }

    while (q--) {
        ll x; cin >> x; 
        --x;
        ll idx = lower_bound(a+1, a+n+1, x) - a;

        cout << (x - a[idx-1] + l[idx]) << "\n";
    }
}