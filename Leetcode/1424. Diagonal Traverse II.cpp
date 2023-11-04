/*Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
1 2 3 4 5
6 7
8
9 10 11
12 13 14 15

[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int mxlen = 0;
        for (auto e: nums) mxlen = max(mxlen, (int)e.size());

        vector<vector<int>> tmp(n + mxlen);
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                tmp[i + j].push_back(nums[i][j]);
            }
        }
        
        vector<int> res;
        for (auto p: tmp) {
           for (int e: p) res.push_back(e); 
        }
        return res;
    }
};