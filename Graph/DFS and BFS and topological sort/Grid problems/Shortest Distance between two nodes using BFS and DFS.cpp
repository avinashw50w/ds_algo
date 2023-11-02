/*Shortest dist between two points in a grid can be solved by using both BFS and DFS.
NOTE: BFS is more efficient to find the shortest dist between two nodes, while DFS uses backtracking to find the min possible distance
DFS can be used to find the shortest path between two nodes in a tree, coz in a tree every path is unique
*/


// Using BFS

const int maxn = 1e2;
int grid[maxn][maxn];
int vis[maxn][maxn];


struct Node {
    int x, y, dist;
};

int BFS(int sx, int sy, int dx, int dy) {

    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(Node(sx, sy, 0));

    while(!q.empty()) {
        vis[x][y] = 1;

        Node top = q.front(); q.pop();
        int x = top.x;
        int y = top.y;
        int dist = top.dist;

        if (x == dx and y == dy) return dist;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!safe(nx, ny) or vis[nx][ny]) continue;
            q.push(Node(nx, ny, dist + 1));
        }
    }

    return -1;
}


// Using DFS (inefficient)

int findMinDist(int sx, int sy, int dx, int dy) {

    memset(vis, 0, sizeof(vis));
    fill(&dp[0][0], &dp[N][0], INT_MAX);
    dis[sx][sy] = 0;

    dfs(sx, sy);

    return dist[dx][dy];
}

void dfs(int x, int y) {
    vis[x][y] = 1;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!safe(nx, ny) or vis[nx][ny]) continue;
        dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
        dfs(nx, ny);
    }

    vis[x][y] = 0;
}


// another BFS way
int G[maxn][maxn];

int BFS(int sx, int sy, int dx, int dy) {
    vector<vector<int>> dist = vector<vector<int>(N, vector<int>(N, -1));

    queue<array<int,2>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        int x = top[0], y = top[1];

        if (x == dx and y == dy) return dist[x][y];

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!safe(nx, ny) or dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}
