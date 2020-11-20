/*Tuzki's love for Fibonacci numbers led him to formulate the following interesting function F, on an array A :

F(A) =(Fibonacci(Sum(A))) % (10^9 + 7)

where Sum(A) denotes the sum of array A's elements and Fibonacci(A) denotes the
Fibonacci number.

Tuzki is so obsessed with this interesting function that he decides to calculate the following expression, G, accurately and efficiently:

G = (∑ F(A(l...r))) % (10^9 + 7), where 1 <= l <= r <= n

This is a tough task for Tuzki and he can't do it alone! Given the values of n and array A
 for q queries, help Tuzki by finding and printing the value of
 G modulo (10^9 + 7) on a new line for each query.

Input Format

The first line contains a single integer, q, denoting the number of queries.
The 2q subsequent lines describe each query over two lines:

The first line of each query contains an integer, n, denoting the size of array A.
The second line of each query contains n space-separated integers denoting the respective values of array A.

IDEA:
F(A(l..r)) = F(A(l..r-1)) * F(A[r]) + F(A[r])
eg. A = [1,2,3]
F([1,2,3]) = F([1,2])
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;
struct matrix {
    ll ar[2][2];
};
matrix operator*(matrix a, matrix b) {
    matrix ans;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans.ar[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                ans.ar[i][j] += (a.ar[i][k] * b.ar[k][j]) % MOD;
            }
        }
    }
    return ans;
}

matrix operator+(matrix a, matrix b) {
    matrix ans;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans.ar[i][j] = (a.ar[i][j] + b.ar[i][j]) % MOD;
        }
    }
    return ans;
}

matrix _pow(matrix m, int n) {
    if (n == 1)
        return m;
    if (n & 1)
        return (m * _pow(m, n - 1));
    m = _pow(m, n >> 1);
    m = m * m;
    return m;
}

matrix get_pow(ll k) {
    matrix ans;
    ans.ar[0][0] = ans.ar[0][1] = ans.ar[1][0] = 1;
    ans.ar[1][1] = 0;
    ans = _pow(ans, k);
    return ans;
}
matrix ans;
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, j, x;
        ll sum = 0;
        matrix temp;
        cin >> n;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                ans.ar[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++) {
            cin >> x;
            temp = get_pow(x);
            ans = ans * temp + temp;
            sum += ans.ar[1][0];
            sum %= MOD;
        }
        cout << sum << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

#define MAX 100009
#define ll long long
#define MOD 1000000007

ll arr[MAX];

struct node {
    ll s[3];
    ll c[3];
    ll l[3];
    ll r[3];
};
struct node segtree[4 * MAX];

void multiply(ll F[2][2], ll M[2][2])
{
    ll x = (((F[0][0] * M[0][0]) % MOD) + ((F[0][1] * M[1][0]) % MOD)) % MOD;
    ll y = (((F[0][0] * M[0][1]) % MOD) + ((F[0][1] * M[1][1]) % MOD)) % MOD;
    ll z = (((F[1][0] * M[0][0]) % MOD) + ((F[1][1] * M[1][0]) % MOD)) % MOD;
    ll w = (((F[1][0] * M[0][1]) % MOD) + ((F[1][1] * M[1][1]) % MOD)) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ll F[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

ll fib(ll n)
{
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}


void build_segtree(int low, int high, int pos) {
    if (low == high) {
        ll par1 = fib(arr[low] - 1) % MOD;
        ll par2 = fib(arr[low]) % MOD;
        ll par3 = (par1 + par2) % MOD;
        segtree[pos].s[0] = par2;
        segtree[pos].s[1] = par1;
        segtree[pos].s[2] = par3;
        segtree[pos].c[0] = par2;
        segtree[pos].c[1] = par1;
        segtree[pos].c[2] = par3;
        segtree[pos].l[0] = par2;
        segtree[pos].l[1] = par1;
        segtree[pos].l[2] = par3;
        segtree[pos].r[0] = par2;
        segtree[pos].r[1] = par1;
        segtree[pos].r[2] = par3;
        return;
    }
    int mid = (low + high) / 2;
    build_segtree(low, mid, 2 * pos + 1);
    build_segtree(mid + 1, high, 2 * pos + 2);

    segtree[pos].s[0] = ((segtree[2 * pos + 1].s[0] * segtree[2 * pos + 2].s[2]) % MOD + (segtree[2 * pos + 1].s[1] * segtree[2 * pos + 2].s[0]) % MOD) % MOD;
    segtree[pos].s[1] = ((segtree[2 * pos + 1].s[0] * segtree[2 * pos + 2].s[0]) % MOD + (segtree[2 * pos + 1].s[1] * segtree[2 * pos + 2].s[1]) % MOD) % MOD;
    segtree[pos].s[2] = ((segtree[2 * pos + 1].s[2] * segtree[2 * pos + 2].s[2]) % MOD + (segtree[2 * pos + 1].s[0] * segtree[2 * pos + 2].s[0]) % MOD) % MOD;

    segtree[pos].c[0] = segtree[2 * pos + 1].c[0] + segtree[2 * pos + 2].c[0];
    segtree[pos].c[0] %= MOD;
    segtree[pos].c[0] += (segtree[2 * pos + 1].r[0] * segtree[2 * pos + 2].l[2]) % MOD + (segtree[2 * pos + 1].r[1] * segtree[2 * pos + 2].l[0]) % MOD;
    segtree[pos].c[0] %= MOD;

    segtree[pos].c[1] = segtree[2 * pos + 1].c[1] + segtree[2 * pos + 2].c[1];
    segtree[pos].c[1] %= MOD;
    segtree[pos].c[1] += (segtree[2 * pos + 1].r[0] * segtree[2 * pos + 2].l[0]) % MOD + (segtree[2 * pos + 1].r[1] * segtree[2 * pos + 2].l[1]) % MOD;
    segtree[pos].c[1] %= MOD;

    segtree[pos].c[2] = segtree[2 * pos + 1].c[2] + segtree[2 * pos + 2].c[2];
    segtree[pos].c[2] %= MOD;
    segtree[pos].c[2] += (segtree[2 * pos + 1].r[2] * segtree[2 * pos + 2].l[2]) % MOD + (segtree[2 * pos + 1].r[0] * segtree[2 * pos + 2].l[0]) % MOD;
    segtree[pos].c[2] %= MOD;
    ///
    segtree[pos].l[0] = segtree[2 * pos + 1].l[0];
    segtree[pos].l[0] += (segtree[2 * pos + 1].s[0] * segtree[2 * pos + 2].l[2]) % MOD + (segtree[2 * pos + 1].s[1] * segtree[2 * pos + 2].l[0]) % MOD;
    segtree[pos].l[0] %= MOD;

    segtree[pos].l[1] = segtree[2 * pos + 1].l[1];
    segtree[pos].l[1] += (segtree[2 * pos + 1].s[0] * segtree[2 * pos + 2].l[0]) % MOD + (segtree[2 * pos + 1].s[1] * segtree[2 * pos + 2].l[1]) % MOD;
    segtree[pos].l[1] %= MOD;

    segtree[pos].l[2] = segtree[2 * pos + 1].l[2];
    segtree[pos].l[2] += (segtree[2 * pos + 1].s[2] * segtree[2 * pos + 2].l[2]) % MOD + (segtree[2 * pos + 1].s[0] * segtree[2 * pos + 2].l[0]) % MOD;
    segtree[pos].l[2] %= MOD;
    ///
    segtree[pos].r[0] = segtree[2 * pos + 2].r[0];
    segtree[pos].r[0] += (segtree[2 * pos + 2].s[0] * segtree[2 * pos + 1].r[2]) % MOD + (segtree[2 * pos + 2].s[1] * segtree[2 * pos + 1].r[0]) % MOD;
    segtree[pos].r[0] %= MOD;

    segtree[pos].r[1] = segtree[2 * pos + 2].r[1];
    segtree[pos].r[1] += (segtree[2 * pos + 2].s[0] * segtree[2 * pos + 1].r[0]) % MOD + (segtree[2 * pos + 2].s[1] * segtree[2 * pos + 1].r[1]) % MOD;
    segtree[pos].r[1] %= MOD;

    segtree[pos].r[2] = segtree[2 * pos + 2].r[2];
    segtree[pos].r[2] += (segtree[2 * pos + 2].s[2] * segtree[2 * pos + 1].r[2]) % MOD + (segtree[2 * pos + 2].s[0] * segtree[2 * pos + 1].r[0]) % MOD;
    segtree[pos].r[2] %= MOD;
}
int main() {
    int t, n, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);
        build_segtree(0, n - 1, 0);

        printf("%lld\n", segtree[0].c[0]);
    }
    return 0;
}
