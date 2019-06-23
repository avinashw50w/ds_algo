/*Find all occurrences of a given word in a matrix
Given a 2D grid of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. 
Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

The solution should print all coordinates if a cycle is found. i.e.

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonals.

Input:
mat[ROW][COL]= { {'B', 'N', 'E', 'Y', 'S'},
     	         {'H', 'E', 'D', 'E', 'S'},
	        	 {'S', 'G', 'N', 'D', 'E'}
               };
Word = “DES”
Output:
D(1, 2) E(1, 1) S(2, 0) 
D(1, 2) E(1, 3) S(0, 4) 
D(1, 2) E(1, 3) S(1, 4)
D(2, 3) E(1, 3) S(0, 4)
D(2, 3) E(1, 3) S(1, 4)
D(2, 3) E(2, 4) S(1, 4)*/

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int x, int y, int id, int N, string path, vector<string> &pathArray) {

	if(id >= N or mat[x][y] != word[id]) return;

	path = path + word[id] + "(" + to_string(x) + "," + to_string(y) + ") ";
	
	if(id == N-1) pathArray.push_back(path);

	REP(i, 0, 8) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!valid(nx, ny)) continue;

		DFS(nx, ny, id+1, N, path, pathArray);
	}
}

vector<string> findWord(char mat[R][C], string word) {

	vector<string> paths;

	int N = word.length();

	REP(i, 0, R)
		REP(j, 0, C)
			if(mat[i][j] == word[0])
				DFS(i, j, 0, N, "", paths);

	return paths;
}