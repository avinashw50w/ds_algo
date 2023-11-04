/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.

Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3*/
class Solution {
public:
    double getSlope(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return INT_MAX;
        if (a[1] == b[1]) return 0;
        return (double)(a[1] - b[1])/(double)(a[0] - b[0]);
    }
    
    bool isSame(vector<int> a, vector<int> b) {
        return a[0] == b[0] and a[1] == b[1];
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        if (n <= 2) return n;
        
        set<vector<int>> st;
        
        for (int i = 0; i < n and st.count(points[i]) == 0; ++i) {
            map<double,int> mp;
            int same = 0, localMax = 1;
            
            for (int j = i + 1; j < n; ++j) {
                if (isSame(points[i], points[j])) {
                    same++;
                    continue;
                }
            
                double slope = getSlope(points[i], points[j]);
                
                if (mp.count(slope) == 0) mp[slope] = 1;
                mp[slope]++;
                
                localMax = max(localMax, mp[slope]);
            }
            
            st.insert(points[i]);
            ans = max(ans, localMax + same);
        }
        
        return ans;
    }
};