#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 1e3;
const int CHARSET = 255;

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int trie[MAXN][CHARSET], leaf[MAXN];
int ROOT = 0, tsz = 1;
char mat[MAXN][MAXN];
int vis[MAXN][MAXN];
set<string> ans;
int N, M;

void init() {
	memset(trie, -1, sizeof(trie));
	memset(leaf, 0, sizeof(leaf));
	memset(vis, 0, sizeof(vis));
	ans.clear();
}

void insert(string word) {
	int node = ROOT;
	for(int i = 0; i < word.size(); ++i) {
		if(trie[node][word[i]] == -1)
			trie[node][word[i]] = tsz++;
		
		node = trie[node][word[i]];
	}
	++leaf[node];
}

void solve2(int x, int y, int node, string &s) {

	if(leaf[node]) ans.insert(s);

	vis[x][y] = 1;

	node = trie[node][mat[x][y]];

	for(int k = 0; k < CHARSET; ++k) {
		if(trie[node][k] == -1) continue;

		char c = (char)k;
		
		for(int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(!(nx >= 0 and nx < N and ny >= 0 and ny < M)) continue;

			if(!vis[nx][ny] and mat[nx][ny] == c) {
				s += c;
				solve2(nx, ny, node, s);
			}
		}
	}	

	vis[x][y] = 0;
}

void solve() {
	init();

	int X; cin >> X;
	string s;

	while(X--) {
		cin >> s;
		insert(s);
	}
	
	cin >> N >> M;

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			cin >> mat[i][j];

	s = "";
	int node = ROOT;

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j) 
			if(trie[node][mat[i][j]] != -1) {
				s += mat[i][j];
				solve2(i, j, node, s);
				s = "";
			}

	for(auto w: ans) cout << w << endl;
}

int main() {
	int T; cin >> T;

	while(T--) {
		solve();
	}
}