#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int grid[maxn][maxn]; // grid[i][j] stores the edge length between i and j, otherwise -1
vis[maxn][maxn];
int N, M;

struct Node {
	int x, y, dist;
};

void bfs(int sx, int sy, int dx, int dy) {
	memset(vis, 0, sizeof(vis));
	queue<Node> q;
	q.push(Node(sx, sy, 0));

	while (!q.empty()) {
		Node u = q.front(); q.pop();
		int x = u.x, y = u.y, dist = u.dist;

		if (x == dx and y == dy) return dist;

		vis[x][y] = 1;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 and nx < N and ny >= 0 and ny < M
				and !vis[nx][ny]
				and grid[nx][ny] != -1)
			{
				q.push(Node(nx, ny, dist + 1));
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> grid[i][j];
	}

	cin >> sx >> sy >> dx >> dy;
	cout << bfs(sx, sy, dx, dy);
}
