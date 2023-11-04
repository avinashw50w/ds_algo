/*An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        
        int dist[1<<N][N];
        for (int i = 0; i < (1<<N); ++i)
            for (int j = 0; j < N; ++j) 
                dist[i][j] = INT_MAX;
        
        queue<pair<int,int>> q;
        
        for (int i = 0; i < N; ++i) {
            q.push({1 << i, i});
            dist[1 << i][i] = 0;
        }
        
        while(!q.empty()) {
            auto top = q.front(); 
            q.pop();
            
            int mask = top.first;
            int u = top.second;
            int d = dist[mask][u];
            if (mask == (1<<N) - 1) return d;
            
            for (auto v: graph[u]) {
                int mask2 = mask | (1<<v);
                if (dist[mask2][v] > 1 + d) {
                    dist[mask2][v] = 1 + d;
                    q.push({mask2, v});
                }
            }
        }
        
        return -1;
    }
};