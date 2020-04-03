// time complexity  O(ElogE + ElogV)  //  to sort the edges : O(ElogE)  and for each edge we call findSet which takes O(ElogV)
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> RANK, PARENT;

void makeSet(int v){
	RANK[v] = 0;
	PARENT[v] = v;
}

int findSet(int v){
	if(PARENT[v] == v) return v;
	else return findSet(PARENT[v]);
}

void Union(int v1, int v2){
	if(RANK[v1] >= RANK[v2])
		RANK[v1] = (RANK[v1] == RANK[v2]) ? RANK[v1]+1 : RANK[v1],
		PARENT[v2] = v1;
	else PARENT[v1] = v2;
}

struct Edge{
	int u, v, weight;
	Edge(int a, int b, int c) : u(a), v(b), weight(c) {}
};

struct Graph{
	vector<int> vertices;
	vector<Edge> edges;
};

vector<Edge> SpanningTree;

void Kruskal(Graph &G){
	for(auto &c : G.vertices) makeSet(c);

	sort(G.edges.begin(), G.edges.end(), [](Edge a, Edge b){ return a.weight < b.weight; });
	
	for(Edge &e : G.edges){
		int set1 = findSet(e.u);
		int set2 = findSet(e.v);
		if(set1 != set2){
			SpanningTree.push_back(e);
			Union(set1, set2);
		}
	}
}

int main(){
	int a[] = {1,2,3,4,5};
	Graph G;
	G.vertices = vector<int>(a, a + sizeof a/sizeof a[0]);
	int u,v,wt;
	for(int i=0;i<5;++i){
		cin >> u >> v >> wt;
		G.edges.push_back(Edge(u, v, wt));
	}

	Kruskal(G);
	
	for(int i=0;i<G.edges.size();i++)
	cout << G.edges[i].u <<"---"<< G.edges[i].v << ", ";

	return 0;
}
