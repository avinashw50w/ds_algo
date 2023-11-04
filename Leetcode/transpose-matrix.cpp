/*Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
       // for transpose (i, j) => (j, i)
        int N = A.size();
        int M = A[0].size();
        vector<vector<int>> res(M, vector<int>(N));
        
        
        for (int i = 0; i < N; ++i) 
            for (int  j = 0; j < M; ++j) 
                res[j][i] = A[i][j];
        
        return res;
    }
};