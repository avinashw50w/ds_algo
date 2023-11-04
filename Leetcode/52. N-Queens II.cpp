/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.*/
class Solution {
    int N;
    int cnt;
    vector<int> rowpos;
public:
    bool safe(int r, int c) {
        for (int i = 1; i < c; ++i) {
            if (rowpos[i] == r or (abs(rowpos[i] - r) == abs(i - c))) return false;
        }
        return true;
    }
    
    void solve(int col) {
        if (col > N) {
            cnt++;
            return;
        }
        for (int row = 1; row <= N; ++row) {
            if (!safe(row, col)) continue;
            rowpos[col] = row;
            solve(col + 1);
        }
    }
    
    int totalNQueens(int n) {
        N = n;
        cnt = 0;
        rowpos.resize(N+1);
        solve(1);
        return cnt;
    }
};