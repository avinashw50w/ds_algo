/*
Company G has a main campus with N offices (numbered from 0 to N - 1) and M bidirectional roads 
(numbered from 0 to M - 1). The ith road connects a pair of offices (Ui, Vi), 
and it takes Ci minutes to travel on it (in either direction).

A path between two offices X and Y is a series of one or more roads that starts at X and ends at Y. 
The time taken to travel a path is the sum of the times needed to travel 
each of the roads that make up the path. (It's guaranteed that there is at least one path connecting any two offices.)

Company G specializes in efficient transport solutions, but the CEO has just realized that, embarrassingly enough, 
its own road network may be suboptimal! She wants to know which roads in the campus are inefficient. 
A road is inefficient if and only if it is not included in any shortest paths between any offices.

Given the graph of offices and roads, can you help the CEO find all of the inefficient roads?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each case begins 
with one line with two integers N and M, indicating the number of offices and roads. 
This is followed by M lines containing three integers each: Ui, Vi and Ci, 
indicating the ith road is between office Ui and office Vi, and it takes Ci minutes to travel on it.

Output

For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1). 
Then output the road numbers of all of the inefficient roads, 
in increasing order, each on its own line. (Note that road 0 refers to the 
first road listed in a test case, road 1 refers to the second road, etc.)

Limits

0 < Ci = 1000000.

Small dataset

1 = T = 10.
1 = N = M = 100.
Large dataset

1 = T = 3.
1 = N = 100.
1 = M = 10000.
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
lld dp[102][102];
int solve(){
	vector<pair<pii,int> >E;
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			dp[i][j] = MOD;
		}
		dp[i][i] = 0;
	}
	int u,v;
	lld x;
	for(int i=1;i<=M;++i){
		cin>>u>>v>>x;
		u++;
		v++;
		E.push_back(mpa(mpa(u,v),x));
		dp[u][v] = min(dp[u][v],x);
		dp[v][u] = min(dp[v][u],x);
	}
	for(int k=1;k<=N;++k){
		for(int j=1;j<=N;++j){
			for(int i=1;i<=N;++i){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=0;i<E.size();++i){
		int flag = 0;
		int u=E[i].fi.fi;
		int v=E[i].fi.se;
		int d = E[i].se;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(dp[i][u]+d+dp[v][j]==dp[i][j])
					flag=1;
			}
		}
		if(flag==0){
			cout<<i<<endl;
		}
	}
}
int main()
{
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		printf("Case #%d:\n",test);
		solve();
	}
}
