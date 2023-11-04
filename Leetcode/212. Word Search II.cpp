/*Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once 
in a word.

NOTE: here dp solution will not work, cuz a char in the board can be taken atmost once.*/

class Solution {
    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };
public:
    
    bool dfs(string word, vector<vector<char>> &board, int pos, int r, int c) {
        if (pos == word.size()) return true;
        if (r < 0 or c < 0 or r >= board.size() or c >= board[0].size()) return false;
        if (board[r][c] != word[pos]) return false;
        
        board[r][c] = '#';
        
        bool ret = false;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            ret |= dfs(word, board, pos + 1, nr, nc);
        }
        
        board[r][c] = word[pos];
        
        return ret;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        vector<string> res;
        
        for (string word: words) {
            for (int i = 0; i < n; ++i) {
                bool ret = false;
                for (int j = 0; j < m; ++j) {
                    int pos = 0;
                    ret = dfs(word, board, pos, i, j);
                    if (ret) {
                        res.push_back(word);
                        break;
                    }
                }
                if (ret) break;
            }
        }
        
        return res;
    }
};