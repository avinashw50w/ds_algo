#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void sieve(ll l,ll r){
	bool primes[r-l+1];
	for(ll i=0;i<(r-l+1);i++) primes[i]=true;
	for(ll i=2;i*i<=r;i++){
		for(ll j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
		primes[j-l]=false;
	}
	for(ll i=max(l,(ll)2);i<=r;i++){
		if(primes[i-l]) cout<<i<<"\n";
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		ll n,m; cin>>m>>n;
		sieve(m,n);
	}
	return 0;
}
