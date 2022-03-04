/*Find shortest safe route in a path with landmines
Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of
the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix.
We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe.
We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.

Examples:

Input:
A 12 x 10 matrix with landmines marked as 0

[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]
[ 1  1  1  1  0  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  0  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  0  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 0  1  1  1  1  0  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]

Output:
Length of shortest safe route is 13 (Highlighted in Bold) */
#define R 15
#define C 15

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int mat[R][C], vis[R][C];
int dist[R][C];

bool valid(int x, int y) { return (x >= 0 and x < R and y >= 0 and y < C); }

bool safe(int x, int y) { return (mat[x][y] == 1 and dis[x][y] == -1); }

void markUnsafeCells() {
	rep(i, 0, R) {
		rep(j, 0, C) {
			if (mat[i][j] == 0) {
				rep(k, 0, 4) {
					int nx = i + dx[k], ny = j + dy[k];
					if (valid(nx, ny))
						mat[nx][ny] = -1;
				}
			}
		}
	}
	rep(i, 0, R) rep(j, 0, C) if (mat[i][j] == -1) mat[i][j] = 0;
}

// using bfs (efficient: whenever shortest distance is asked use bfs or dijkshra algo)
// it's an example of multisource bfs
struct Point {
	int x, y;
	Point(int i, j) {
		x = i;
		y = j;
	}
};

int shortestPath() {
	markUnsafeCells();
	queue<Point> q;
	for (int i = 0; i < R; ++i) {
		if (mat[i][0] == 1) {
			q.push(Point(i, 0));
			dist[i][0] = 0;
		}
	}

	while (q.size()) {
		auto top = q.front(); q.pop();
		int x = top.x, y = top.y;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (valid(nx, ny) and safe(nx, ny)) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(Point(nx, ny));
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < R; ++i) {
		if (dist[i][C-1] != -1) ans = min(ans, dist[i][C-1]);
	}
}

/////////////////////////////////////////////////////////
// using dfs (inefficient : takes exponential time)
bool valid(int x, int y) { return (x >= 0 and x<R and y >= 0 and y < C); }

bool safe(int x, int y) { return (mat[x][y] == 1 and !vis[x][y]); }

void findShortestPathUtil(int x, int y, int &minDist, int dist) {
	if (y == C - 1) {
		minDist = min(minDist, dist);
		return;
	}

	if (dist > minDist) return;

	vis[x][y] = 1;

	rep(i, 0, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny) and safe(nx, ny))
			findShortestPathUtil(nx, ny, minDist, dist + 1);
	}

	// backtrack
	vis[x][y] = 0;
}

int findShortestPath() {
	int minDist = INT_MAX;

	markUnsafeCells();

	rep(i, 0, R) {
		if (mat[i][0] == 1) {
			memset(vis, 0, sizeof(vis));

			findShortestPathUtil(i, 0, minDist, 0);

			if (minDist == C - 1) break;
		}
	}

	return (minDist != INT_MAX) ? minDist : -1;
}

