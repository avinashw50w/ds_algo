/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above*/

class Solution {
    vector<int> rowpos;
    vector<vector<string>> res;
    int N;
public:
    void storesol() {
        
        vector<string> s(N);
        for (auto &e: s) e = string(N, ' ');
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (rowpos[j] == i) s[i-1][j-1] = 'Q';
                else s[i-1][j-1] = '.';
            }
        }
        res.push_back(s);
    }
    
    bool safe(int r, int c) {
        for (int i = 1; i < c; ++i) {
            if (rowpos[i] == r or (abs(rowpos[i] - r) == abs(i - c))) return false;
        }
        return true;
    }
    
    void solve(int col) {
        if (col > N) {
            storesol();
            return;
        }
        for (int row = 1; row <= N; ++row) {
            if (!safe(row, col)) continue;
            rowpos[col] = row;
            solve(col + 1);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        rowpos.resize(n+1);
        N = n;
        solve(1);
        return res;
    }
};