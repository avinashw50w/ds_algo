/*A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool toeplitz = true;
        int M = matrix.size();
        int N = matrix[0].size();
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || j == 0) continue;
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    toeplitz = false; break;
                }
            }
            
            if (!toeplitz) break;
        }
        
        return toeplitz;
    }
};