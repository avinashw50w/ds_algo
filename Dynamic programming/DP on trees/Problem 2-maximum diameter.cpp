#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int N;              // no of nodes
vi G[N];            // graph
int f[N],g[N],diameter;       //  f and g used are to store the maximum diameter of each node for two different cases 

void dfs(int v,int pv){
	vi fvalues;              //  to store the values of f
	for(auto u:G[v]){        //  traverse all children of v
		if(u==pv) continue;
		dfs(u,v);
		fvalues.push_back(f[u]);      //  store the values of f in fvalues
	}

	sort(fvalues.begin(), fvalues.end(),greater<int>);    // sort in descending order to get the max of them
	f[v]=1;
	if(!fvalues.empty())
		f[v]+=fvalues.front();            //  get the max from fvalues
	if(fvalues.size()>=2)
		g[v]+=fvalues[0]+fvalues[1];          //  get the maximum two from fvalues

	diameter = max(diameter,f[v]+g[v]);      // update the diameter
}


/*Problem 2:
Given a tree T of N nodes, calculate longest path between any two nodes(also known as diameter of tree).

First, lets root tree at node 1. Now, we need to observe that there would exist a node x such that:
Longest path starts from node x and goes into its subtree(denoted by blue lines in the image). Lets define by f(x) this path length.
Longest path starts in subtree of x, passes through x and ends in subtree of x(denoted by red line in image). 
Lets define by g(x) this path length.

If for all nodes x, we take maximum of f(x),g(x), then we can get the diameter. But first, we need to see how we can calculate 
maximum path length in both cases.

Now, lets say a node V has n children v1,v2,...,vn. We have defined f(i) as length of longest path that starts at node i and ends
 in subtree of i. We can recursively define f(V) as 1+max(f(v1),f(v2),...,f(vn)), because we are looking at maximum path length 
 possible from children of V and we take the maximum one. So, optimal substructure is being followed here. Now, note that 
 this is quite similar to DP except that now we are defining functions for nodes and defining recursion based on values of children. 
 This is what DP on trees is.

Now, for case 2, a path can originate from subtree of node vi, and pass through node V and end in subtree of vj, where i≠j. 
Since, we want this path length to be maximum, we'll choose two children vi and vj such that f(vi) and f(vj) are maximum. 
We say that g(V)=1+sum of two max elements from set{f(v1),f(v2),...,f(vn)}.

For implementing this, we note that for calculating f(V), we need f to be calculated for all children of V. 
So, we do a DFS and we calculate these values on the go. See this implementation for details.

If you can get the two maximum elements in O(n), where n is number of children then total complexity will be O(N), 
since we do this for all the nodes in tree.
*/
