/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO 
NOT allocate another 2D matrix and do the rotation.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();

        for (int i = 0; i < n/2; ++i) {
            for (int j = i; j < n-1-i; ++j) {
                int t = a[i][j];
                a[i][j] = a[n-j-1][i];
                a[n-j-1][i] = a[n-i-1][n-j-1];
                a[n-i-1][n-j-1] = a[j][n-i-1];
                a[j][n-i-1] = t;
            }
        }
    }
};