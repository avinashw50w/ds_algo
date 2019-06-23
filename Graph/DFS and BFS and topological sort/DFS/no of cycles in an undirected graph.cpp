#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];
vector<int> V;

int n,m;
int cycles = 0;

int dfs(int u, int par){
	V[u] = 1;
	for(auto i: g[u]){
		if(!V[i]) dfs(i);
		else if (i != par) cycles++;
	}
}

int numofcycles(){
	V.assign(n,0);
	for(int i=0;i<n;++i){
		if(!V[i]){
			dfs(i, -1);
		}
	}
	return cycles;
}

int main(){
	int u,v;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << numofcycles() << endl;
	
	return 0;
}
