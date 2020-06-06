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
					Q.push({nx, ny});
				}
			}
		}

		Q.pop(); // pop the delimiter

		// if there are rotten oranges left in the queue, then push the delimiter
		if (!Q.empty()) 
			Q.push({-1, -1});
	}

	return ans;
}


//////////////////////////////////////////////////////
// similar question: find minimum passes to convert all the -ve nos in a matrix to positive.
// In one pass u can convert all the neighboring cells around a cell containing +ve no from -ve to +ve

// M x N matrix
#define M 4
#define N 5

// Data structure to store the cell coordinates of the matrix
struct Point {
	int x, y;
};

// Function to check whether given coordinates is a valid cell or not
bool isValid(int i, int j) { return (i >= 0 && i < M) && (j >= 0 && j < N); }

int dx[] = { -1,  0, 0, 1 };
int dy[] = {  0, -1, 1, 0 };

// Returns true if the matrix contains at least one negative value
bool hasNegative(int mat[][N])
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] < 0)
				return true;
		}
	}

	return false;
}

// Find minimum number of passes required to convert all negative values
// in the given matrix to positive
int convert(int mat[][N]) {
	queue<Point> Q;

	// enqueue cell coordinates of all positive numbers in the matrix
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] > 0)
				Q.push({i,j});
		}
	}

	// to keep track of time taken to make all numbers positive
	int passes = 0;

	// loop till all reachable negative numbers in the matrix are processed
	while (!Q.empty()) {
		queue<Point> q;

		// copy contents of the original queue Q to the another queue q and
		// empty the original queue
		swap(Q, q);
		// Process all cells in the queue
		while (!q.empty()) {
			// pop front node and process it
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			// check all 4 adjacent cells of the current cell
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				// if current adjacent cell is valid and has negative value
				if (isValid(nx, ny) && mat[nx][ny] < 0) {
					// make the value positive
					mat[nx][ny] = -mat[nx][ny];

					// enqueue the adjacent cell
					Q.push({nx, ny});
				}
			}
		}
		// increment number of passes by 1
		passes++;
	}

	// return number of passes or 
	// inifinity if the matrix has an unreachable cell which is negative
	return hasNegative(mat) ? INT_MAX : (passes - 1);
}

int main()
{
	int mat[][N] =
	{
		{ -1, -9,  0, -1,  0 },
		{ -8, -3, -2,  9, -7 },
		{  2,  0,  0, -6,  0 },
		{  0, -7, -3,  5, -4 }
	};

	int pass = convert(mat);
	if (pass != INT_MAX)
		cout << "No of passes required is " << pass;
	else 
		cout << "Invalid Input";

	return 0;
}
