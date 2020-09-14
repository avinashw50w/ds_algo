#include <iostream>
using namespace std;


// naive solution  O(2^n) //
int func(int n) {
  if (n < 2) return n;
  else return func(n - 1) + func(n - 2);
}

// using three variables
int fib(int n) {
  int a = 0, b = 1, c = a + b;
  for (int i = 2; i < n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }

  return c;
}

// bottom up  O(n) //
int fib[1000];
int func() {
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 1000; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];
}

////////////////////////////////////////////////////////
// top down  O(n) //

int fib[1000]; // memset to -1 //
int func(int n) {
  if (n < 2)
    return fib[n] = n;
  if (fib[n] != -1) return fib[n];

  return fib[n] = func(n - 1) + func(n - 2);
}

////////////////////////////////////////////////////////////////////////

// calculate in O(logn + loglogn) //

const int MAX = 1000;

// Create an array for memoization
int f[MAX] = {0};

// Returns n'th fuibonacci number using table f[]
int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return (f[n] = 1);

  if (f[n]) return f[n];

  int k = (n & 1) ? (n + 1) / 2 : n / 2;

  f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
         : (2 * fib(k - 1) + fib(k)) * fib(k);

  return f[n];
}

/* Proof :
In the matirx equation :
  |1 1|^n = |Fn+1   Fn|
  |1 0|   |Fn   Fn-1|
Taking determinant on both sides, we get
(-1)n = Fn+1Fn-1 – Fn2
Moreover, since AnAm = An+m for any square matrix A, the following identities can be derived
(they are obtained form two different coefficients of the matrix product)

FmFn + Fm-1Fn-1 = Fm+n-1

By putting n = n+1,

FmFn+1 + Fm-1Fn = Fm+n

Putting m = n

F2n-1 = Fn2 + Fn-12

F2n = (Fn-1 + Fn+1)Fn = (2Fn-1 + Fn)Fn (Source: Wiki)

To get the formula to be proved, we simply need to do following
If n is even, we can put k = n/2
If n is odd, we can put k = (n+1)/2

*/

///////////////////// for higher fibonacci ///////////////////////////////////////

// matrix form //

typedef vector<vector<ll>> vvi;

vvi mul(vvi a, vvi b) {
  vvi res {{0, 0}, {0, 0}};
  rep(i, 0, 2) {
    rep(j, 0, 2) {
      rep(k, 0, 2)
      res[i][j] += (a[i][k] * b[k][j]);
      res[i][j] %= mod;
    }
  }
  return res;
}

vvi mpow(vvi a, ll n) {
  vvi res {{1, 0}, {0, 1}}; // identity matrix ( which is similar to value 1 in matrix arithmatic )
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}


ll fib(ll n) {
  vvi a {{1, 1}, {1, 0}};
  vvi ans = mpow(a, n);
  return ans[0][1];
}

int main() {
  cout << fib(6);
  return 0;
}

/////////////////////////////////////////////////////////////
// O(1) for nth fibonacci
// 1/sqrt(5) * ((1+sqrt(5))/2)^n
#define round(x) x < 0 ? x-0.5 : x+0.5

int fib(int n)
{
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}
