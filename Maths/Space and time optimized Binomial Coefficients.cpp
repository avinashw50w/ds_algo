/*Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

We have discussed a O(n*k) time and O(k) extra space algorithm in this post. The value of C(n, k) can be calculated in O(k) time and O(1) extra space.

C(n, k) = n! / (n-k)! * k!
        = [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) *
                                    ( k * (k-1) * .... * 1 ) ]
After simplifying, we get
C(n, k) = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]

Also, C(n, k) = C(n, n-k)  // we can change r to n-r if r > n-r */


long long nCr(int n, int r) {
    long long res = 1;

    r = min(r, n - r);

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// to handle overflow use log
// ncr = n!/(n-r)!r! = f[n] - f[n-r] - f[r]
// where f[n] = log2(n!)
int f[maxn];
void precompute() {
    f[0] = f[1] = 0;
    for (int i = 0; i < maxn; ++i) f[i] = log2(i) + f[i - 1];
}

ll ncr(ll n, ll r) {
    ll x = f[n] - f[n - r] - f[r];
    return 1 << x;
}