/*Abhishek Sinha like everyone else was a firm believer of Sphere Earth, believing what school has taught and not trusting their own insights.
Once Sir Notsocool Hawkins quoted "Everything in life doesn't need to be hard and complex, sometimes it is simple and flat, just like our Planet".

After getting motivated, Abhishek Sinha establishes 'Flat Earth Society' and to join the society, one must solve the following problem:

Given an array A consisting of N integers. In a single step player can choose an element of the array (let's denote it ak) and delete it, at that all elements equal to ak + 1,ak + 2......ak + R and ak - 1,ak - 2.....ak - L also must be deleted from the array. This step will add ak points to player. Player can perform any number of steps.

Find maximum points which can be obtained.



Input Format

First line contains T testcases.

Each Testcase contains three integers N, L and R, where N is number of elements in array, and use of L and R has been explained in Problem statement.

The next line contains N integers denoting elements of array A.

Output Format

A single line for each test case, output a single integer denoting the maximum points possible..

Constraints

1 <= T <= 100

1 <= N, L, R <= 10^5

1<= ak <=10^5*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;
int a[maxn], f[maxn], dp[maxn];

int main() {
    int t, n, l, r;
    cin >> t;

    while (t--) {
        cin >> n >> l >> r;

        memset(f, 0, sizeof(f));
        memset(dp, 0, sizeof(dp));

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
            mx = max(mx, a[i]);
        }

        int k = min(l, r);
        for (int e = 1; e <= mx; ++e) {
            if (e - k - 1 >= 0) dp[e] = max(
                                                dp[e - 1], // don't delete element e
                                                dp[e - k - 1] + e * f[e] // delete element e
                                            );
            else dp[e] = max(dp[e - 1], e * f[e]);
        }

        cout << dp[mx] << endl;
    }
}