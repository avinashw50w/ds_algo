
const int maxn = 100;
typedef pair<int, int> pii;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct Node {
	pii pt;		// the point
	int dist;	// distance of the point from  the source
};

int mat[maxn][maxn];

int shortestPath(pii src, pii dest) {
	bool vis[maxn][maxn];
	memset(vis, false, sizeof(vis));
	
	queue<Node> Q;
	Q.push({src, 0});
	
	while(!Q.empty()) {
		Node top = Q.front();
		Q.pop();

		int x = top.pt.first, y = top.pt.second;
		int dist = top.dist;
		
		if(x == dest.first and y == dest.second)
			return dist;
			
		vis[x][y] = true;
		
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!valid(nx, ny) and mat[nx][ny]==0 and vis[nx][ny])
				continue;
			Q.push({{nx, ny}, dist + 1});
		}
	}
	
	return INT_MAX;
}

///////////////////////////////////////////////////////////////////////////////
// for calculating the shortest dist of any point from the source , use this method
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dist[maxn][maxn];
int N, M; // numbe of rows and colums

void shortestPath(pii src) {
	bool vis[N][M];
	memset(vis, false, sizeof vis);
	fill(&dist[0][0], &dist[N][0], INF);

	dist[src.first][src.second] = 0;

	queue<pii> Q;
	Q.push(src);

	while(!Q.empty()) {
		pii top = Q.front(); 
		Q.pop();

		int x = top.first, y = top.second;

		vis[x][y] = true;

		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!valid(nx, ny) and mat[nx][ny]==0 and vis[nx][ny])
				continue;
			if(dist[x][y] != INF and dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				Q.push({nx, ny});
			}
		}
	}
} 
