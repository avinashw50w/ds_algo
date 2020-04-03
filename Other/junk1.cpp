#include <iostream>
using namespace std;
void subsetsum(int a[],int n){
	int S = accumulate(a,a+n,0);
	int dp[S+2];
	dp[0]=1;
	for(int i=0;i<n;++i)
	for(int j=S;j>=a[i];j--)
	dp[j] |= dp[j-a[i]];
}
////////////////////////////////////////////////////
int fenwick[100000];
void update(int idx, int val){  //  O(logn)
	while(idx<=100000){
	fenwick[idx] += val;
	idx += (idx & -idx)
	}
}
int query(int idx){          //  O(logn)
	int sum = 0; 
	while(idx>0){
	sum += fenwick[idx];
	idx -= (idx & -idx);
	}
}
int getsum(int a,int b){ return query(b) - query(a-1); }
////////////////////////////////////////////////////////////////////
vii G[N];
vi D;
void dijkstra(int source){        //  O(ElogV)
	D.assign(N,oo);
	D[source] = 0;
	set<pii> Q;
	Q.insert({0,source});
	while(!Q.empty()){
		auto top = Q.begin();
		int u = top->second;
		Q.erase(top);
		for(auto &c : G[u]){
			int v = c.first , w = c.second;
			if(D[v] > D[u]+w){
				if(Q.find({D[v],v}) != Q.end())
					Q.erase(Q.find({D[v],v}));
				D[v] = D[u]+w;
				Q.insert({D[v],v});
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////
vi primes;
vector<bool> isprime;
void sieve(){
	ll i;
	isprime.assign(MAX,true);
	for(i=2; i*i<=MAX; i++){
		if(isprime(i)){
			primes.pb(i);
			for(ll j=i*i; j<=MAX; j+=i)
				isprime[j] = false;
		}
	}
	while(i<=MAX){
		if(isprime(i))
			primes.pb(i);
	}
}
////////////////////////////////////////////////////////////////////////
void LIS(int a[], int n){
	set<int> st;
	set<int>::iterator it;
	st.clear();
	for(int i=0; i<n; ++i){
		st.insert(a[i]); it = st.find(a[i]);
		it++; if(it != st.end()) st.erase(it);
	}
	cout << st.size();
}
//////////////////////////////////////////////////////////////////////
int eulerPhi(int n){
	int res = n;
	for(ll i=2; i*i<=n; ++i){
		if(n%i == 0) res -= res/i;
		while(n%i == 0) n/=i;
	}
	if(n>1) res -= res/n;
	return res;
}
