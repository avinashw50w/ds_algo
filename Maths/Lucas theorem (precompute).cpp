#include <bits/stdc++.h>
using namespace std;

// Calculate nCr % mod , where mod is varying, it is prime, and is not greater than 100 (because we cannot take an array of size > 10^6) //
int dp[50][50][50];

long long C(int n, int r, int m) {
	if(r<0 or r>n) return 0;
	if(r==0 or r==n) return 1;

	if(n >= m)
		return (C(n/m, r/m, m) * C(n%m, r%m, m)) % m;
	
	if(dp[n][r][m] != -1) return dp[n][r][m];
		
	else return dp[n][r][m] = (C(n-1, r-1, m) + C(n-1, r, m)) % m;
}

int main() {
	int n,r,m;
	memset(dp,-1,sizeof dp);
	while(cin>>n>>r>>m){
		cout<< C(n,r,m) <<endl;
	}
}