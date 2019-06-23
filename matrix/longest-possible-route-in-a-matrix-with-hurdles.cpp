/*Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of longest possible route possible 
from source to destination within the matrix. We are allowed to move to only adjacent cells which are not hurdles. 
The route cannot contains any diagonal moves and a location once visited in a particular path cannot be visited again.

The idea is to use Backtracking. We start from the source cell of the matrix, move forward in all four allowed directions 
and recursively checks if they leads to the solution or not. If destination is found, we update the value of longest path 
else if none of the above solutions work we return false from our function.*/

class Solution {
    int R, C;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
public:
    int solve(vector<vector<int>> grid, int x, int y, int dest_x, int dest_y, int vis[R][C]) {
        if (x == dest_x and y == dest_y) return 0;

        int res = INT_MIN;
        vis[x][y] = 1;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and nx < R and ny >= 0 and ny < C and !vis[nx][ny] and grid[nx][ny] == 1) {
                int t = solve(grid, nx, ny, dest_x, dest_y, vis);
                if (t != INT_MAX) res = max(res, t);
            }
        }

        vis[x][y] = 0;
        return (res != INT_MIN) ? 1+res : INT_MAX;
    }
    int longestPath(vector<vector<int>> grid, int src_x, int src_y, int dest_x, int dest_y) {
        R = grid.size();
        C = grid[0].size();

        int vis[R][C];
        memset(vis, 0, sizeof(vis));

        if (grid[src_x][src_y] == 0) return -1;

        int res = solve(grid, src_x, src_y, dest_x, dest_y, vis);

        return (res != INT_MAX) ? res : -1;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////
#define R 10
#define C 8
#define found first
#define value second

typedef pair<bool, int> pii;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

pii LongestPath(int mat[R][C], int i, int j, int x, int y, bool vis[R][C]) {

	if(i == x and j == y) return make_pair(true, 0);

	if(i<0 or i>=R or j<0 or j>=C or mat[i][j] == 0 or vis[i][j]) 
		return make_pair(false, INT_MAX);

	vis[i][j] = true;

	int res = INT_MIN;
	pii sol;
	
	for(int k = 0; k < 4; ++k) {
		
		sol = LongestPath(mat, i+dx[k], j+dy[k], x, y, vis);

		if(sol.found)
			res = max(res, sol.value);
	}

	vis[i][j] = false;

	if(res != INT_MIN) return make_pair(true, 1 + res);

	else return make_pair(false, INT_MAX);
}

//////////////////////////////////////////////////////////////////////////////
