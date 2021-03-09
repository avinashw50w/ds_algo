/*There is a town represented as a two-dimensional grid with H horizontal rows and W vertical
columns.A character ai,j describes the square at the i-th row from the top and j-th column from
the left. Here, ai,j is one of the following: S , G , . , # , a, ..., and z.
# represents a square that cannot be entered, and a, ..., z represent squares with teleporters.
Takahashi is initially at the square represented as S. In each second, he will make one of the following moves:

Go to a non-# square that is horizontally or vertically adjacent to his current position.
Choose a square with the same character as that of his current position, and teleport to that square. He can only use this move when he is at a square represented as a, ..., or z.
Find the shortest time Takahashi needs to reach the square represented as G from the one represented as S.
If the destination is unreachable, report -1 instead.

Constraints:
1≤H,W≤2000
ai,j is S, G, ., #, or a lowercase English letter.
There is exactly one square represented as S and one square represented as G.*/

/*IDEA: use bfs. For teleporters, whenever u are at a teleporter insert all other teleporters
of the same type in the queue. It means that the dist between any pair of teleporters of
the same type is 1*/

const int maxn = 2001;
typedef pair<int, int> pii;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve() {
	int n, m; cin >> n >> m;
	vector<string> mat(n);
	int sx, sy, tx, ty;
	vector<pii> pos[26];

	for (int i = 0; i < n; ++i) {
		cin >> mat[i];
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (mat[i][j] == 'G') {
				tx = i;
				ty = j;
			}

			if ('a' <= mat[i][j] and mat[i][j] <= 'z') {
				int c = mat[i][j] - 'a';
				pos[c].insert({i, j});
			}
		}
	}

	queue<pii> q;
	int dist[maxn][maxn];
	memset(dist, -1, sizeof(dist));
	dist[sx][sy] = 0;
	q.push({sx, sy});

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if (mat[nx][ny] == '#') continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}

		if ('a' <= mat[x][y] and mat[x][y] <= 'z') {
			int t = mat[x][y] - 'a';
			for (auto &[nx, ny] : pos[t]) {
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
			// need to remove all the coordinates of teleporter t
			// otherwise the algo will iterate over it again, irrespective of the fact
			// that its shortest dist has already been calculated. Thus it will resutl in tle
			pos[t].clear();
		}
	}

	return dist[tx][ty];
}


/*IDEA: use dijsktra to find the shortest time to reach G.
Extra things to take care of : if we are at a teleporter say a, then push all the positions
of teleporter a in the queue and mark that teleporter visited.
Note that the dist btw any pair of teleporters of the same name will be 1

*/

typedef pair<int, int> pii;
const int maxn = 2002;
int vis[maxn + 1][maxn + 1];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve() {
	int h, w; cin >> h >> w;
	string mat[h];
	// position of S
	int sx, sy;
	// to store the positions of respective teleporters
	vector<pii> tel[26];

	for (int i = 0; i < h; ++i) {
		cin >> mat[i];
		for (int j = 0; j < w; ++j) {
			if (mat[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if ('a' <= mat[i][j] and mat[i][j] <= 'z')
				tel[mat[i][j] - 'a'].push_back({i, j});
		}
	}

	set<pair<int, pii>> q;
	q.insert({0, {sx, sy}});

	while (!q.empty()) {
		auto top = *q.begin();
		q.erase(top);
		int d = top.first;
		int x = top.second.first, y = top.second.second;
		// if it is a teleporter
		if (x == maxn) {
			if (vis[x][y]) continue;
			vis[x][y] = 1;
			for (auto p : tel[y]) {
				q.insert({d + 1, p});
			}

			continue;
		}

		if (x < 0 or x >= h or y < 0 or y >= w or vis[x][y] or mat[x][y] == '#')
			continue;

		vis[x][y] = 1;

		if (mat[x][y] == 'G') {
			return d;
		}

		for (int i = 0; i < 4; ++i) {
			q.insert({d + 1, {x + dx[i], y + dy[i]}});
		}
		// if curr char is a teleporter
		if ('a' <= mat[x][y] and mat[x][y] <= 'z') {
			q.insert({d, { maxn, mat[x][y] - 'a'}});
		}
	}

	return -1;
}