/*Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2. */


int solve(int a, int b, int m) {
    if(b == 0) return 1;
    long long x = solve(a, b/2, m);
    x = (x*x)%m;
    if(b&1) x = (x*a)%m;
    return (int)x;
}


int Solution::pow(int x, int n, int d) {
    if(x == 0) return 0;
    bool neg = false;
    if(x < 0) x = -x, neg = true;
    int ans = solve(x, n, d);

    return (neg and n&1)? (ans*(-1)+d)%d : ans;
}