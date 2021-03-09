/*Given a binary matrix of N x M, containing at least a value 1. The task is to find the distance of nearest 1 in the matrix for each cell. The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

Examples:

Input : N = 3, M = 4
        mat[][] = { 0, 0, 0, 1,
                    0, 0, 1, 1,
                    0, 1, 1, 0 }
Output : 3 2 1 0
         2 1 0 0
         1 0 0 1
Explanation:
For cell at (0, 0), nearest 1 is at (0, 3),
so distance = (0 - 0) + (3 - 0) = 3.
Similarly, all the distance can be calculated.

IDEA: use BFS
store all position of all the 1's and then do bfs to find the distance
*/

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<vector<int>> solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();

	int vis[n][m], dist[n][m];
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vis[i][j] = 0;
			dist[i][j] = INT_MAX;
			if (mat[i][j] == 1) {
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		int x = p.first, y = p.second;
		vis[x][y] = 1;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and mat[nx][ny] != 1) {
				dist[nx][ny] = min(dist[ny][ny], dist[x][y] + abs(nx - x) + abs(ny - y));
				q.push({ nx, ny });
			}
		}
	}

	return dist;
}

////////////////////////////////////////////////
// below method is the same as above, just the 2d array is implemented as 1d
vector<vector<int>> solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();

	vector<int> vis(n * m, 0), dist(n * m, INT_MAX);
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 1) {
				int t = i * m + j;
				dist[t] = 0;
				q.push(t);
			}
		}
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();
		int x = u / m;
		int y = u % m;
		vis[u] = 1;

		for (int i = 0; i < 4; ++i) {
			int ny = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 and nx < n and ny >= 0 and ny < m and mat[nx][ny] != 1) {
				int v = nx * m + ny;
				if (!vis[v]) {
					dist[v] = min(dist[v], abs(nx - x) + abs(ny - y) + dist[u]);
					q.push(v);
				}
			}
		}
	}

	vector<vector<int>> res = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < dist.size(); ++i) {
		int x = i / m, y = i % m;
		res[x][y] = dist[i];
	}

	return res;
}

