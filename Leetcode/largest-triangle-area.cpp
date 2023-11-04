/*You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        int n = points.size();
        if (n < 3) return 0;
        double ans = 0.0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    vector<int> p1 = points[i], p2 = points[j], p3 = points[k];
                    int ax = p1[0], ay = p1[1];
                    int bx = p2[0], by = p2[1];
                    int cx = p3[0], cy = p3[1];
                    double area = (double)abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by))/2;
                    ans = max(ans, area);
                }
            }
        }
        
        return ans;
    }
};