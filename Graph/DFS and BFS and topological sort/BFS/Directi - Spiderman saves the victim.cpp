/* Given a N x M grid
	Find the shortest path from (1,1) to (x,y).
	can move from (i, j) to (n, m) only if (n, m) lies adjacent up, down, left or right
	and abs(H[i][j], H[n][m]) <= D

	can be simply solved using bfs
	the only caveat here is the size of the matrix

	1 <= N, M <= 10000

	so we need to first create the adjacency list, then do bfs on it
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))

const int maxn = 10000 + 1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int M, N, X, Y, D;

int H[maxn][maxn], dist[maxn];
unordered_map<int, vector<int>> G;

void pre() {
	G.clear();

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (safe(nx, ny) and abs(H[i][j] - H[nx][ny]) <= D) {
					G[i * M + j].push_back( nx * M + ny );
				}
			}
		}
}

bool safe(int x, int y) {
	return (x >= 1 and x <= N and y >= 1 and y <= M);
}

void solve() {

	memset(dist, -1, sizeof(dist));

	queue<int> Q;

	Q.push( 1 * M + 1 );

	dist[1 * M + 1] = 0;

	while (!Q.empty()) {

		int u = Q.front(); Q.pop();

		for (int v : G[u]) {
			if (dist[v] == -1) {
				Q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}

	if (dist[X * M + Y] == -1) cout << "-1\n";
	else cout << dist[X * M + Y] << "\n";
}



int main() {
	int t; cin >> t;

	while (t--) {

		cin >> N >> M >> X >> Y >> D;

		rep(i, 1, N + 1) rep(j, 1, M + 1) cin >> H[i][j];

		pre();

		solve();
	}
}