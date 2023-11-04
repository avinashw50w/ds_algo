/*Akash is interested in a new function F such that,

F(x) = GCD(1, x) + GCD(2, x) + ... + GCD(x, x)

where GCD is the Greatest Common Divisor.
Now, the problem is quite simple. Given an array A of size N, there are 2 types of queries:
1. C X Y : Compute the value of F( A[X] ) + F( A[X + 1] ) + F( A[X + 2] ) + .... + F( A[Y] ) (mod 10^9 + 7)
2. U X Y: Update the element of array A[X] = Y

Input:
First line of input contain integer N, size of the array.
Next line contain N space separated integers the elements of A.
Next line contain integer Q, number of queries.
Next Q lines contain one of the two queries.

Output:
For each of the first type of query, output the required sum (mod 10^9 + 7).

Constraints:
1 <= N <= 106
1 <= Q <= 105
1 <= Ai <= 5*105

For Update ,
1 <= X <= N
1 <= Y <= 5*105

For Compute ,
1 <= X <= Y <= N

SAMPLE INPUT 
3
3 4 3
6
C 1 2
C 1 3
C 3 3
U 1 4
C 1 3
C 1 2

Pillai's arithmetical function

In number theory, the gcd-sum function also called Pillai's arithmetical function is defined for every n by 
P(n) = k=1 to n ∑ gcd(k, n)
is equivalent to :
P(n) = for all d|n ∑ d * phi(n/d)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500000 + 2;
const int maxn1 = 1e6 + 2;
const ll mod = 1e9 + 7;

ll f[maxn], fs[maxn], bit[maxn1], a[maxn1];

void add_self(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void update(int i, ll val, int n) {
    for (; i <= n; i += i & -i) add_self(bit[i], val);
}

ll get(int i) {
    ll ret = 0;
    for (; i > 0; i -= i & -i) add_self(ret, bit[i]);
    return ret;
}

ll query(int l, int r) {
    return (get(r) - get(l-1) + mod) % mod;
}

void pre() {
    int i, j, k, ans;
    for(i = 0; i < maxn; ++i)
        f[i] = i;
    for(i = 2; i < maxn; ++i)
    {
        if(f[i] == i)
        {
            f[i] = i - 1;
            for(j = 2*i; j < maxn; j += i)
                f[j] -= (f[j] / i);
        }
    }
    for(i = 1; i < maxn; ++i)
    {
        for(j = i, k = 1; j < maxn; j += i, k++)
        {
            fs[j] += i*f[k];
        }
    }
}

int main() {
    pre();
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        update(i, fs[a[i]], n);
    }
    
    int q; cin >> q;
    while(q--) {
        char c;
        int x, y;
        cin >> c;
        if (c == 'U') {
            cin >> x >> y;
            update(x, -fs[a[x]], n);
            update(x, fs[y], n);
            a[x] = y;
        }
        else {
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
        
        
    }
}