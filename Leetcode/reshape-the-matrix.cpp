/*You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<int> tmp;
        int n = nums.size(), m = nums[0].size();
        
        if (n * m != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) tmp.push_back(nums[i][j]);
        
        int k = 0;
        for (int i = 0; i < r; ++i) 
            for (int j = 0; j < c; ++j)
                res[i][j] = tmp[k++];
        
        return res;
    }
};

/////////////////////////////////////////////////////////////////
// without using extra space (using modulus and division)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        
        if (n == 0 or (n * m != r * c)) return nums;
        vector<vector<int>> res(r, vector<int>(c));

        int k = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                res[k / c][k % c] = nums[i][j],
                k++;
        
        return res;
    }
};
