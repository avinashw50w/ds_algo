// factorial of a number
long long fac(int n) {
	long long res = 1;
	for (int i = 2; i <= n; ++i) res *= i;
	return res;
}

// recursive
long long fac(int n) {
	if (n < 2) return 1;
	return n * fac(n - 1);
}

// precompute
const int maxn = 100;
long long f[maxn];
void precompute() {
	f[0] = f[1] = 1;
	for (int i = 2; i < maxn; ++i) f[i] = i * f[i - 1];
}

// for storing large factorials, use log operation
// n! = 2^f[n] = (long long) pow(2.0, f[n])
// usually used while computing binomial coefficients
// eg. nCr = n!/(n-r)! * r!
// => log(nCr) = log(n!) - log((n-r)!) - log(r!)
//             = f[n] - f[n-r] - f[r]
//  so, nCr = 2^(log(nCr))  = 2^(f[n] - f[n-r] - f[r])
long long f[maxn];
void precompute() {
	for (int i = 2; i < maxn; ++i)
		f[i] = log2(i) + f[i - 1];
}
