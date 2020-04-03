/*Minimum time required to rot all oranges
Given a matrix of dimension m*n where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0: Empty cell

1: Cells have fresh oranges

2: Cells have rotten oranges 
So we have to determine what is the minimum time required so that all the oranges become rotten. 
A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] 
(up, down, left and right). If it is impossible to rot every orange then simply return -1.*/


int solve(vector<vector<int>> grid) {

	int ans = 0;
	int N = grid.size();
	int M = grid[0].size();

	queue<pair<int,int>> Q;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (grid[i][j] == 2) Q.push({i, j});

	Q.push({-1, -1}); // put a delimiter

	while (!Q.empty()) {
		int flag = 0;

		while(!isDelimiter(Q.front())) {
			auto top = Q.front(); Q.pop();

			int x = top.first, y = top.second;

			if (!flag) ans++, flag = 1;

			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 and nx < N and ny >= 0 and ny < M and grid[nx][ny] == 1) {
					grid[nx][ny] = 2;
					q.push({nx, ny});
				}
			}
		}

		Q.pop(); // pop the delimiter

		// if there are rotten oranges left in the queue, then push the delimiter
		while (!Q.empty()) 
			Q.push({-1, -1});
	}

	return ans;
}

