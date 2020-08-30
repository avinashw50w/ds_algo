/*Given integers A, B and N, you should calculate the GCD of A^N+B^N and |A−B|. (Assume that GCD(0,a)=a for any positive integer a). Since this number could be very large, compute it modulo 1000000007 (109+7).

idea: since A^N + B^N will be very large, just consider the divisors of |A-B|
calculate all the divisors of |A-B| and check which divisor divides A^N + B^N,
if d divides A^N + B^N then update the max divisor(coz we are finding the greatest common divisor)

(A^N + B^N) % d = 0
(A^N % d + B^N % d) % d = 0
*/

const int mod = 1e9 + 7;

int power(int a, int b, int m) {
    long long res = 1LL;
    for (; b; b >>= 1; a = (a * a) % m)
        if (b & 1) res = (res * a) % m;
    return res;
}

int getGCD(int A, int B, int N) {
    if (A == B) {
        return (power(A, N, mod) + power(B, N, mod)) % mod;
    }
    int maxd = 1;
    int num = abs(A - B);
    for (int i = 1; i * i <= num; ++i) {
        if (n % i == 0) {
            int t = (power(A, N, i) + power(B, N, i)) % i;
            if (t == 0) maxd = max(maxd, t);
            if (i != num / i) {
                t = (power(A, N, num / i) + power(B, N, num / i)) % num / i;
                if (t == 0) maxd = max(maxd, num / i);
            }
        }
    }

    return maxd;
}



