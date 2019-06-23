#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1234567
const int mod = (int)1e9 + 7;

int fac[N], ifac[N];

ll modpow(ll a, ll b) {
	if(b == 0) return 1;
	ll x = modpow(a, b/2);
	x = (x*x)%mod;
	if(b&1) x = (x*a)%mod;
	return x;
}

void precompute() {
	fac[0] = 1;
	for(int i=1; i< N; ++i)
		fac[i] = (i * fac[i-1])%mod;

	ifac[N-1] = modpow(fac[N-1], mod-2);
	for(int i=N-2; i>=0; --i)
		ifac[i] = ((i+1) * ifac[i+1])%mod;
}

ll nCr(int n, int r){
	ll ret = fac[n];
	ret *= ifac[r];
	ret %= mod;
	ret *= ifac[n-r];

	return ret%mod;
}

int main() {
	
	precompute();

	int n, r;
	cin>>n>>r;

	cout << nCr(n, r) << endl;
}