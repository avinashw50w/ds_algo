/*You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<array<int,3>> st;
        int k = nums.size(), n = nums[0].size();
        for (int i = 0; i < k; ++i) {
            st.insert({ nums[i][0], i, 0 });
        }
        int l, r, ans = INT_MAX;
        while (st.size() == k) {
            auto top = *st.begin();
            auto bottom = *st.rbegin();
            int mn = top[0];
            int mx = bottom[0];
            
            if (ans > mx - mn) {
                ans = mx - mn;
                l = mn;
                r = mx;
            }
            
            st.erase(top);
            
            int r = top[1];
            int c = top[2];
            if (c + 1 < nums[r].size()) st.insert({ nums[r][c+1], r, c+1 });
        }
        
        return { l, r };
    }
};