/*We define f(X, Y) as number of different corresponding bits in binary representation of X and Y.
For example,f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively.
The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,�, AN. Find sum of f(Ai, Aj) for all pairs (i, j)
such that 1 <= i, j <= N. Return the answer modulo 109+7.

For example,

A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) +
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8

Assume that all values in input have only 1 bit i.e. Ai = 0 or 1.
Lets say A = count of elements which are 0
and B = count of elements which are 1

In this case our answer is just 2AB, since each such pair contributes 1 to answer.

Can we combine this logic if we have multiple bits?

Note that all bits are independent in counting, since we are counting number of bits which are different in each pair.
So, we just do the same process for all different bits. Since Ai is an integer, we just have to do this for 31 different bits,
so our solution is O(31*N).  */



#include <bits/stdc++.h>
#define MOD 1000000007ll
using namespace std;
typedef long long LL;

int solve(int arr[], int n) {

    int ans = 0;
    // traverse over all bits
    for (int i = 0; i < 31; i++) {

        // count number of elements with ith bit set
        long long count = 0;
        for (int j = 0; j < n; j++) if ( arr[j] >> i & 1 ) count++;

        // add to answer count * (n - count) * 2
        ans += (count * ((LL)n - count) * 2ll) % MOD;
        if (ans >= MOD) ans -= MOD;
    }

    return ans;
}

int main() {

    int arr[] = {1, 3, 5};
    int n = sizeof arr / sizeof arr[0];
    cout << solve(arr, n) << endl;
    return 0;
}
