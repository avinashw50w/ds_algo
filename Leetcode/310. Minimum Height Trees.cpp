/*A tree is an undirected graph in which any two vertices are connected by exactly
 one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges
 where edges[i] = [ai, bi] indicates that there is an undirected edge between
 the two nodes ai and bi in the tree, you can choose any node of the tree as the
  root. When you select a node x as the root, the result tree has height h.
  Among all possible rooted trees, those with minimum height (i.e. min(h))
  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

IDEA: node having degree of 1 can't be the root, so store all the nodes with
degree of 1 in a queue and do a bfs on each of the nodes and keep removing them
from the queue. during bfs, while traversing through the children of the nodes
decrement their degree by 1 and if the child's degree becomes 1 then push it to
the queue.
keep repeating the above step until the the nodes left are > 2, then final ans
will be all the nodes that are left in the queue.
*/

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> res;
    if (n == 0 or edges.empty()) {
        res.push_back(0);
        return res;
    }

    vector<int> g[n + 1];
    vector<int> degree(n, 0);

    for (auto e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) q.push(i);
    }

    while (n > 2) {
        int cnt = q.size();
        n -= cnt;

        while (cnt--) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                --degree[v];
                if (degree[v] == 1) q.push(v);
            }
        }
    }

    while (!q.empty()) res.push_back(q.front()), q.pop();

    return res;
}