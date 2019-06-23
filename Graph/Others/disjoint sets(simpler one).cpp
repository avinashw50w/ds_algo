#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> rank,parent;

void makeSet(int v){
	rank[v]=0;
	parent[v]=v;
}

int findSet(int v){
	if(parent[v]==v) return v;
	else return findSet(parent[v]);
}

void Union(int v1,int v2){
	if(rank[v1]>=rank[v2]){
		rank[v1] = (rank[v1]==rank[v2])? rank[v1]+1:rank[v1];
		parent[v2]=v1;
	}
	else parent[v1]=v2;
}