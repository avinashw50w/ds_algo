/*Given a 3 x 3 tic-tac-toe grid. Two players A and B play the game.
A marks X and B marks O. 
Note that the first one to play marks X in the board. So after any move the count of X must be 
either equal to or 1 greater than the count of O
1. Only one player can win.
2. Let count of X and O be cntX and cntY, then either cntX == cntY or cntX == cntY + 1
3. If O wins then cntX == cntY
4. if X wins then cntX == cntY + 1
*/

#include <iostream> 
using namespace std; 
  
// This matrix is used to find indexes to check all 
// possible wining triplets in board[0..8] 
int win[8][3] = {{0, 1, 2}, // Check first row. 
                {3, 4, 5}, // Check second Row 
                {6, 7, 8}, // Check third Row 
                {0, 3, 6}, // Check first column 
                {1, 4, 7}, // Check second Column 
                {2, 5, 8}, // Check third Column 
                {0, 4, 8}, // Check first Diagonal 
                {2, 4, 6}}; // Check second Diagonal 
  
// Returns true if character 'c' wins. c can be either 
// 'X' or 'O' 
bool isCWin(char *board, char c) 
{ 
    // Check all possible winning combinations 
    for (int i=0; i<8; i++) 
        if (board[win[i][0]] == c && 
            board[win[i][1]] == c && 
            board[win[i][2]] == c ) 
            return true; 
    return false; 
} 
  
// Returns true if given board is valid, else returns false 
bool isValid(char board[9]) 
{ 
    // Count number of 'X' and 'O' in the given board 
    int xCount=0, oCount=0; 
    for (int i=0; i<9; i++) { 
        if (board[i]=='X') xCount++; 
        if (board[i]=='O') oCount++; 
    } 
  
    if (xCount==oCount || xCount==oCount+1) { 
        // Check if 'O' is winner 
        if (isCWin(board, 'O')) 
        { 
            // Check if 'X' is also winner, then 
            // return false 
            if (isCWin(board, 'X')) 
                return false; 
  
            // Else return true xCount and yCount are same 
            return (xCount == oCount); 
        } 
  
        // If 'X' wins, then count of X must be greater 
        if (isCWin(board, 'X') && xCount != oCount + 1) 
        return false;  
  
        // If 'O' is not winner, then return true 
        return true; 
    } 
    return false; 
} 
  
// Driver program 
int main() 
{ 
char board[] = {'X', 'X', 'O', 
                'O', 'O', 'X', 
                'X', 'O', 'X'}; 
(isValid(board))? cout << "Given board is valid": 
                    cout << "Given board is not valid"; 
return 0; 
} 