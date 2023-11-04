/*Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

IDEA: for every point i, store the no of points equidistant from i,
then choose any two ordered pairs nP2
*/

class Solution {
public:
    double dist(vector<int> a, vector<int> b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> mp;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                mp[dist(points[i], points[j])]++;
            }

            for (auto e : mp) {
                if (e.second > 1)
                    cnt += e.second * (e.second - 1); // all possible permutations
            }
        }

        return cnt;
    }
};