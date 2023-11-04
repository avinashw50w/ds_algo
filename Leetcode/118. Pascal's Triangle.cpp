/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.*/

class Solution {
public:
    // nCr => nCr+1
    // n*(n-1)*...*(n-r+1)/r! => n*(n-1)*...*(n-r+1)*(n-r)/(r+1)!
    // nCr * (n-r)/(r+1) => nCr * (n-(r+1-1))/(r+1) => nCr * (n-r`+1)/r`
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;

        for (int row = 0; row < numRows; ++row) {
            vector<int> v(row + 1);
            int curr = 1;
            for (int i = 0; i <= row / 2; ++i) {
                if (i == 0) v[i] = v[row - i] = 1;
                else {
                    curr = (curr * (row - i + 1)) / i;
                    v[i] = v[row - i] = curr;
                }
            }
            res.push_back(v);
        }

        return res;
    }
};