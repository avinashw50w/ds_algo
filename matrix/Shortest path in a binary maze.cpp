/*Given a MxN matrix where each element can either be 0 or 1. We need to find the shortest
 path between a given source cell to a destination cell. The path can only be created out
 of a cell if its value is 1.
Expected time complexity is O(MN).
For example –

Input:
mat[ROW][COL]  = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
Source = {0, 0};
Destination = {3, 4};

Output:
Shortest Path is 11

IDEA: use BFS whenever asked for shortest path from src to dest
*/

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

bool safe(int n, int m, int x, int y) {
	return (x >= 0 and x < n and y >= 0 and y < m and mat[x][y] == 1 and !vis[x][y]);
}

int solve(vector<vector<int>> mat, Point src, Point dest) {
	int n = mat.size(), m = mat[0].size();
	queue<pair<Point, int>> q;
	bool vis[n][m];
	memset(vis, 0, sizeof(vis));

	q.push({src, 0});

	while (!q.empty()) {
		auto top = q.top(); q.pop();
		int x = top.first.x;
		int y = top.first.y;
		int d = top.second;

		if (dest.x == x and dest.y == y) return d;
		if (vis[x][y]) continue;
		vis[x][y] = true;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (safe(n, m, nx, ny)) {
				q.push({Point(nx, ny), d + 1});
			}
		}
	}

	return -1;
}