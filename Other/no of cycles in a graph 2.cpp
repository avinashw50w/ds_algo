#include<iostream>
#include<list>
#include<stack>
#include<cstring>
using namespace std;
int main(){
	int n,e;
	cout<<"Enter the no of vertices :";
	cin>>n;
	list<int> adj[n+1];
	stack<int> s;
	bool visited[n+1];
	cout<<"\nEnter the no of edges :";
	cin>>e;
	int u,v;
	cout<<"\nEnter the edges :";
	for(int i=0;i<e;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	memset(visited,false,sizeof(visited));
	list<int>::iterator it;
	int cycles=0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			s.push(i);
			visited[i] = true;
			while(!s.empty()){
				int v=s.top();
				s.pop();
				for(it=adj[v].begin();it!=adj[v].end();++it){
					if(!visited[*it]){
						s.push(*it);
						visited[*it] = true;
					}
					else cycles++;
				}
			}
		}
	}
	
	cout<<"\nNo. of cycles in the graph : "<<cycles;
	
	return 0;
}
