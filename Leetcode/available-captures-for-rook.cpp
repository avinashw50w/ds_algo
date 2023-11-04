/*On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, 
white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p'
 respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions 
(north, east, west, and south), then moves in that direction until it chooses to stop, 
reaches the edge of the board, or captures an opposite colored pawn by moving to the 
same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

 [[".",".",".",".",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 [".",".",".","R",".",".",".","p"],
 [".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.*/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int N = board.size();
        unordered_map<int, int> x, y;
        int a, b;
        
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) 
                if (board[i][j] == 'R') {
                    a = i; b = j;
                    break;
                }
                
        
        int cnt = 0;
        for (int i = a+1; i < N; ++i) 
            if (board[i][b] == 'p') { cnt++; break; }
            else if (board[i][b] == 'B') break;
        
        for (int i = a-1; i >= 0; --i)
            if (board[i][b] == 'p') { cnt++; break; } 
            else if (board[i][b] == 'B') break;
        
        for (int j = b+1; j < N; ++j)
            if (board[a][j] == 'p') { cnt++; break; }
            else if (board[a][j] == 'B') break;
        
        for (int j = b-1; j >= 0; --j)
            if (board[a][j] == 'p') { cnt++; break; }
            else if (board[a][j] == 'B') break;
        
        return cnt;
    }
};