#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define WHITE 0
#define GREY  1
#define BLACK 2

vi *G;                  // Graph 
int V[1010] = {0};     // visited array
/*=======================================================*/
bool IsCyclic(int u) {
    if(V[u] == WHITE) {
        V[u] = GREY;
        for(auto &i: G[u]){
            if(V[i] == WHITE and IsCyclic(i))
				return true;
            else if(V[i] == GREY) return true;
        }
    }
    V[u] = BLACK;
    return false;
}
/*===========================================================*/
int main() {
    int N, M, u, v;
    cin >> N >> M;          // N and M are the no of nodes and edges respectively.
    G = new vi[N+1];
    for(int i=0;i<M;++i){
        cin >> u >> v;
        G[u].push_back(v);
    }
    bool cycle = false;
    for(int i=0;i<N;++i){
        if(IsCyclic(i)){
            cycle = true;
            break;
        }
    }    
    
    (cycle == true)? puts("cycle exists") : puts("No cycle exists");
    
    return 0;
}
