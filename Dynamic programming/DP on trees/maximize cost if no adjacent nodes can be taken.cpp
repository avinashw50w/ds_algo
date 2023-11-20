#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector< vector<int> >
#define MAX 10000
using namespace std;
int N=MAX;     // no of nodes
vi G[N];   // graph
int C[N];  // cost assosiated with each node
dp1[N],dp2[N];           //  dp1 is for storing optimal cost of the children of the current node and dp2 is for storing optimal cost of the grandchildren of the current node
void dfs(int u,int par){     // par is the parent of v
    dp1[u] = C[u];
    dp2[u] = 0;
	for(auto v: G[u]){       //  for all the childrens of v
		if(v == par) continue;    //  if child is the parent then do nothing and continue
		dfs(v,u);              // call dfs for all children of v
		dp1[u] += dp2[v];      // sum of costs of the grandchildren of v  (if cost of v is included)
		dp2[u] += max(dp1[v], dp2[v]);    // if cost of v is not included
	}
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}

/*Problem 1:
The first problem we solve is as follows: Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose a subset of nodes 
such that no two adjacent nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is maximum.

This problem is quite similar to 1-D array problem where we are given an array A1,A2,...,AN; we can't choose adjacent elements and we have to maximise sum of 
chosen elements. Remember, how we define our state as dp(i) denoting answer for A1,A2,...,Ai. Now, we define our recurrence as
 dp(i)=max(Ai+dp(i−2),dp(i−1))(two cases: choose Ai or not, respectively).

Now, unlike array problem where in our state we are solving for first i elements, in case of trees one of our states usually denotes which subtree 
we are solving for. For defining subtrees we need to root the tree first. Say, if we root the tree at node 1 and define our DP dp(V) as the answer 
for subtree of node V, then our final answer is dp(1).

Now, similar to array problem, we have to make a decision about including node V in our subset or not. If we include node V, we can't include any of its 
children(say v1,v2,...,vn), but we can include any grand child of V. If we don't include V, we can include any child of V.

So, we can write a recursion by defining maximum of two cases.
dp(V)=max(∑ni=1dp(vi),CV+∑ni=1sum of dp(j) for all children j of v_i).

As we see in most DP problems, multiple formulations can give us optimal answer. Here, from an implementation point of view, we can define an easier solution 
using DP. We define two DPs, dp1(V) and dp2(V), denoting maximum coins possible by choosing nodes from subtree of node V and if we include node V in our answer
 or not, respectively. Our final answer is maximum of two case i.e. max(dp1(1),dp2(1)).

And defining recursion is even easier in this case. dp1(V)=CV+∑ni=1dp2(vi)(since we cannot include any of the children) and dp2(V)=∑ni=1max(dp1(vi),dp2(vi))
(since we can include children now, but we can also choose not include them in subset, hence max of both cases).

About implementation now. You must notice that answer for a node is dependent on answer of its children. We write a recursive definition of DFS, 
where we first call recursive function for all children and then calculate answer for current node.*/
