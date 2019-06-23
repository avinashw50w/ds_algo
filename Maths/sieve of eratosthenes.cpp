#include<iostream>
#include <cmath>
#include<vector>
#define pb push_back
#define ll long long int
using namespace std;
#define MAXN 9999999

// use this one to quickly store all the primes upto MAXN in array p . //
bool vis[MAXN+1];
vector<int> p; 

void seive() {
	p.push_back(2);
	
	for(int i = 3; i < MAXN; i += 2){
		if(!vis[i]){
			p.push_back(i);
			
			for(int j = i*i; j<MAXN; j += 2*i) 
				vis[j] = true;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
const int MAXN = 1e6;
bool p[MAXN];
vector<ll> primes;

void sieve(){
	memset(p, true, sizeof(p));
	p[0]=false;p[1]=false;
	ll i;
	for(i=2;i*i<MAX;i++){
		if(p[i]){
			primes.pb(i);
			for(ll j=i*i;j<MAX;j+=i) p[j]=false;
		}
	}
	while(i<MAX){
		if(p[i]) primes.pb(i);
		i++;
	}
}

// function to check if a no n is prime or not
bool is_prime(int n) {
	if(n < MAX) return p[MAX];
	else {
		for(int i = 0; i < primes.size(); ++i) 
			if(n % primes[i] == 0) return false;
	}

	return true;
}

int main(){
	seive();
	for(ll i=0;i<primes.size();i++) cout<<primes[i]<<" ";
	return 0;
}

////////////////////////////////////////////////////////////////////
// another way
void sieve(){
	int i;
	primes.push_back(2);
	for(i=2*2;i<=MAX;i+=2) 
		isprime[i] = false;
	for(i=3;i*i<=MAX;i+=2){
		if(isprime[i]){
			primes.push_back(i);
			for(int j=i*i;j<=MAX;j+=i)
			isprime[j]=false;
		}
	}
	while(i<=MAX){
		if(isprime[i])
			primes.push_back(i);
		i+=2;
	}
}

///////////////////////////////////////////////////////////////////////
// there's another way of doing this by using bitset
#include <bitset>
bitset<10000010> b;
void sieve(){
	b.reset();     // reset all bits to 0
	b.flip();      // set all bits to 1
	b.set(0,false); b.set(1,false);     // set 0 and 1 as false
	for(ll i=2;i*i<=MAX;i++){
		if(b.test((size_t)i));
		primes.push_back(i);
		for(ll j=i*i;j<=MAX;j+=i)
		b.set((size_t)j,false);
	}
}
