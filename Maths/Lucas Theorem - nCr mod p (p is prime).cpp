/* Calculate nCr % mod , when n and r are very large and mod is prime */

#include <bits/stdc++.h>
using namespace std;

// if m is varying then do this, othewise precompute nCr % m // 
ll nCr(int n, int r, int m){
	ll C[2][r+1] = {};
    for(int i=0; i<=n; ++i){
    	for(int j=0; j<=i and j<=r; ++j){
    		if(j==0 or j==i)
    			C[i&1][j] = 1;
    		else 
    			C[i&1][j] = (C[(i-1)&1][j] + C[(i-1)&1][j-1]) % m;
    	}
    }
    return C[n&1][r];
}

ll Lucas(int n, int r, int m) {
	if(r == 0) return 1;
	int ni = n%m;
	int ri = r%m;
	if(ri > ni) return 0;
	return (Lucas(n/m, r/m, m) * nCr(ni, ri, m)) % m;
}




