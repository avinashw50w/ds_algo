/*Given an m x n matrix, return all elements of the matrix in spiral order.*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int n = mat.size(), m = mat[0].size();
        int t = 0, b = n-1, l = 0, r = m-1, dir = 0;
        while (t <= b and l <= r) {
            if (dir == 0) {
                for (int i = l; i <= r; ++i)
                    res.push_back(mat[t][i]);
                t++;
            } else if (dir == 1) {
                for (int i = t; i <= b; ++i)
                    res.push_back(mat[i][r]);
                r--;
            } else if (dir == 2) {
                for (int i = r; i >= l; --i)
                    res.push_back(mat[b][i]);
                b--;
            } else if (dir == 3) {
                for (int i = b; i >= t; --i)
                    res.push_back(mat[i][l]);
                l++;
            }

            dir = (dir + 1) % 4;
        }

        return res;
    }
};