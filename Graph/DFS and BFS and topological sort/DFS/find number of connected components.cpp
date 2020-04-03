// to find the number of connected components in a disconnected graph  //
#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int N;
vi V;
vi *G;

void dfs(int i){
	if(!V[i]){
		V[i]=true;
		for_each(ALL(G[i]) , dfs);
	}
}

int connectedComponents(){
	int ans=0;
	for(int i=0;i<N;i++){
		if(!V[i]){
			ans++;
			dfs(i);       //  dfs call to vertex i will visit all the vertices that are connected to i,and will not visit the vertex 
		}                 //  that is not connnected to i.
	}
	return ans;
}

/* for a graph like this :
    1            4
  /  \         /  \
 2    3       5    6            the ans will be 2 .