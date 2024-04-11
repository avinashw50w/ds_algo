/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.

IDEA: use backtracking*/
class Solution {
    vector<vector<char>> a;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
public:
    bool isValid(int x, int y) {
        return x >= 0 and x < a.size() and y >= 0 and y < a[0].size();
    }
    
    int solve(int x, int y, int wi, string word) {
        if (wi == (int) word.size()-1) {
            return true;
        }
        
        char c = a[x][y];
        a[x][y] = '#';
        int ans = false;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) and a[nx][ny] == word[wi + 1] and a[nx][ny] != '#')
                ans |= solve(nx, ny, wi + 1, word);
        }
        
        a[x][y] = c;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        a = board;
        int n = a.size(), m = a[0].size();
        

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == word[0]) {
                    if (solve(i, j, 0, word)) return true;
                }
            }
        }

        return false;
    }
};