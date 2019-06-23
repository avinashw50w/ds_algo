
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int dp[100][100];
int mat[100][100];

bool safe(int x, int y) { return (x>=0 and x<n and y>=0 and y<n)}

int fun(int x, int y) {

	if(dp[x][y] != -1) return dp[x][y];

	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(!safe(nx, ny)) continue;

		if(mat[x][y] + 1 == mat[nx][ny])
			return dp[x][y] = 1 + fun(nx, ny);
	}

	return dp[x][y] = 1;
}

int findlongestpath() {
	int ans = 0;
	memset(dp, -1, sizeof(dp));

	for(int i=0; i<n; ++i) { 
		for(int j=0; j<n; ++j) {
			if(dp[i][j] == -1) 
				fun(i, j);
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}