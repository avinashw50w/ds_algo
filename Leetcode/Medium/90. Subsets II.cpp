/*Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10*/

// T: O(2^n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int mask = 1<<n;
        for (int i = 0; i < mask; ++i) {
            vector<int> t;
            for (int j = 0; j < n; ++j) {
                if (i>>j&1) t.push_back(nums[j]); 
            }
            st.insert(t);
        }

        for (auto e: st) ans.push_back(e);
        return ans;
    }
};

// using recursion 
// fastest one
// T: O(2^n)
class Solution {
    vector<int> num;
    vector<int> ds;
    set<vector<int>> st;
public:
    void solve(int idx){
        if(idx == num.size()){
            st.insert(ds);
            return;
        }
        // pick ele
        ds.push_back(num[idx]);
        solve(idx+1);
        // don't pick ele
        ds.pop_back();
        solve(idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        num = nums;
        sort(num.begin(),num.end());
        vector<vector<int>> ans;

        solve(0);

        for(auto e : st){
            ans.push_back(e);
        }
        return ans;
    }
};
// another recursive way
// T: O(2^n)
class Solution {
public:
    set<vector<int>> st;
    vector<int> num, v;
    void solve(int id) {
        st.insert(v);
        for(int i=id; i<num.size(); i++) {
            v.push_back(num[i]);
            solve(i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        num = nums;
        solve(0);
        vector<vector<int>> ans;
        for(auto x: st) ans.push_back(x);
        return ans;
    }
};