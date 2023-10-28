/*Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u->v, 
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which means that all paths will be of finite length. 
Now let S be the longest path from u(source) to v(destination). Since S is the longest path there can be no incoming edge 
to u and no outgoing edge from v, if this situation had occurred then S would not have been the longest path
=> indegree(u) = 0 and outdegree(v) = 0

Algorithm:
Steps involved in finding the topological ordering of a DAG:

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 5: Repeat Step 3 until the queue is empty.

Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

How to find in-degree of each node?
There are 2 ways to calculate in-degree of every vertex:
Take an in-degree array which will keep track of
1) Traverse the array of edges and simply increase the counter of the destination node by 1.

for each node in Nodes
	indegree[node] = 0;
for each edge(src,dest) in Edges
	indegree[dest]++
Time Complexity: O(V+E)

2) Traverse the list for every node and then increment the in-degree of all the nodes connected to it by 1.

	for each node in Nodes
		If (list[node].size()!=0) then
		for each dest in list
			indegree[dest]++;
Time Complexity: The outer for loop will be executed V number of times and the inner for loop will be executed E number of times, 
Thus overall time complexity is O(V+E).

The overall time complexity of the algorithm is O(V+E)*/

typedef vector<int> vi;
const int maxn = 1000
vi G[maxn];
int N;

vector<int> topologicalSorting() {
	int inDegree[N] = {0};

	for(int u = 0; u < N: ++u) {
		for(auto v: G[u])
			inDegree[v]++;
	}

	queue<int> q;
	for(int i = 0; i < N; ++i)
		if(inDegree[i] == 0)
			q.push(i);

	int nodeCnt = 0;
	vi res;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		res.push_back(u);

		for(int v: G[u])
			if(--inDegree[v] == 0)
				q.push(v);

		nodeCnt++;
	}

	if(nodeCnt != N) { cout << "Topological Sorting not possible.\n"; return vi(); }

	return res;
}