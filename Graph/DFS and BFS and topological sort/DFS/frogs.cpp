/* A lake contains a rectangular grid of stones evenly separated.
 *
 * Each stone has an attribute K that represents the maximum jump distance that a frog
 * can achieve when attempting to jump from that stone to another stone.
 *
 * Formally, given a stone (i, j) with some value K, the farthest stones that the frog can reach
 * with a single jump are those at (i+di, j+dj) such that abs(di)+abs(dj) = K.
 *
 * For example, if the stone at (2, 3) has K = 2, then the farthest stones reachable within one jump
 * are (2, 3+2) = (2, 5); (2, 3-2) = (2, 1); (2+1, 3+1) = (3, 4); (2+1, 3-1) = (3, 2);
 * (2-1, 3+1) = (1, 4); (2-1, 3-1) = (1, 2); (2+2, 3) = (4, 3) and (2-2, 3) = (0, 3)
 *
 * Write a program that finds and prints the path that minimizes the number of jumps to go from a
 * source stone to a destination stone.
 *
 * The frog is not allowed to go outside the bounds of the stones grid. Furthermore, the frog
 * doesn't necessarily have to jump the maximum distance K on each stone.
 *
 * Source: Careercup
 */

const int maxn = 1e5 + 5;
bool vis[maxn][maxn];
int R, C;
int mat[maxn][maxn];

void init() {
	cin >> R >> C;

	REP(i, 0, R) 
		REP(j, 0, C) {
			int k; cin >> k;
			mat[i][j] = k;
		}

	int start_x, start_y;
	int end_x, end_y;

	cin >> start_x >> start_y;
	cin >> end_x >> end_y;

	memset(vis, 0, sizeof(vis));
}

void minJumps(vector<pair<int, int>> &path, vector<pair<int, int>> &buff, int x, int y, int destx, int desty) {
	if(x < 0 || x >= R || y < 0 || y >= C || vis[x][y]) 
		return;

	if(x == dx and y == dy) {
		if(path.size() == 0 or buff.size() + 1 < path.size()) {
			path = buff;
			path.push_back({x, y});
		}
	}

	buff.push_back({x, y});
	vis[x][y] = true;

	REP(jump, 1, mat[x][y]) {
		REP(d, 0, jump) {
			int dx = d;
			int dy = jump-d;

			minJumps(path, buff, x + dx, y + dy, destx, desty);
			minJumps(path, buff, x + dx, y - dy, destx, desty);
			minJumps(path, buff, x - dx, y + dy, destx, desty);
			minJumps(path, buff, x - dx, y - dy, destx, desty);
		}
	}

	vis[x][y] = false;
	buff.pop_back();
}

int main() {

	init();

	vector<pair<int,int>> path;
	vector<pair<int,int>> buff;

	minJumps(path, buff, start_x, start_y, end_x, end_y);

	for(auto p : path)
		cout << p.first << ", " << p.second << endl;
}

