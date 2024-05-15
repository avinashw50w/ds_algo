/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int t = 0, b = n-1, l = 0, r = n-1, dir = 0, cnt = 1;
        while (t <= b and l <= r) {
            if (dir == 0) {
                for (int i = l; i <= r; ++i)
                    res[t][i] = cnt++;
                t++;
            } else if (dir == 1) {
                for (int i = t; i <= b; ++i)
                    res[i][r] = cnt++;
                r--;
            } else if (dir == 2) {
                for (int i = r; i >= l; --i)
                    res[b][i] = cnt++;
                b--;
            } else if (dir == 3) {
                for (int i = b; i >= t; --i)
                    res[i][l] = cnt++;
                l++;
            }

            dir = (dir + 1) % 4;
        }

        return res;
    }
};