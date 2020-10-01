/*Find length of the longest consecutive path from a given starting character
Given a matrix of characters.
Find length of the longest path from a given character, such that all characters
in the path are consecutive to each other, i.e., every character
in path is next to previous in alphabetical order.
It is allowed to move in all 8 directions from a cell.

Input: mat[][] = { {a, c, d},
                   {h, b, e},
                   {i, g, f}}
      Starting Point = 'e'

Output: 5
If starting point is 'e', then longest path with consecutive
characters is "e f g h i".*/

int dx[] = {0, 1, 1, -1, 1, 0, -1, -1};
int dy[] = {1, 0, 1, 1, -1, -1, 0, -1};

char mat[maxn][maxn];
int dp[maxn][maxn];
int N, M;

bool valid(int x, int y) { return (x >= 0 and x<N and y >= 0 and y < M); }

bool adjacent(char curr, char prev) { return curr - prev == 1; }

int solve(int x, int y, char prev) {

    if (!valid(x, y) or !adjacent(mat[x][y], prev)) return 0;

    if (dp[x][y] != -1) return dp[x][y];

    int ans = 0;

    REP(i, 0, 8) {
        ans = max( ans, 1 + solve(x + dx[i], y + dy[i], mat[x][y]) );
    }

    return dp[x][y] = ans;
}

int getLength(char s) {

    int ans = 0;

    memset(dp, -1, sizeof(dp));

    REP(i, 0, N)
    REP(j, 0, M) {
        if (mat[i][j] == s) {
            REP(k, 0, 8) {
                ans = max( ans, 1 + solve(i + dx[k], j + dy[k], s) );
            }
        }
    }

    return ans;
}

int main() {

    char mat[R][C] = { {'a', 'c', 'd'},
        { 'h', 'b', 'a'},
        { 'i', 'g', 'f'}
    };

    cout << getLength(mat, 'a') << endl;
    cout << getLength(mat, 'e') << endl;
    cout << getLength(mat, 'b') << endl;
    cout << getLength(mat, 'f') << endl;
    return 0;
}