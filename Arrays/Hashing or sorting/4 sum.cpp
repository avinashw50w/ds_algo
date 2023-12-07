/*Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]*/

/////////////////////////////////////

class Solution {
    typedef long long ll;
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());
        set<vector<int>> st;
        vector<vector<int>> res;

        for (int i = 0; i < n-3; ++i) {
            for (int j = i+1; j < n-2; ++j) {
                int l = j+1, r = n-1;
                while (l < r) {
                    ll sum = (ll)a[i]+a[j]+a[l]+a[r];
                    if (sum == target) {
                        st.insert({a[i],a[j],a[l],a[r]});
                        l++; r--;
                    }
                    else if (sum < target) l++;
                    else r--;
                }
            }
        }

        for (auto e: st) res.push_back(e);
            return res;
    }
};



//////////////////////////////////////////////////////////
// Using hashing
// it doesn't return all the distinct quadruples

vector<vector<int>> solve(vector<int> a, int target) {
    int n = a.size();
    vector<vector<int>> res;
    set<vector<int>> st;
    unordered_map<int, vector<array<int,2>>> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val = target - (a[i] + a[j]);

            if (mp.count(val)) {
                for (auto p: mp[val]) {
                    int x = p[0], y = p[1];
                    st.insert({a[x], a[y], a[i], a[j]});
                }
            }
        }
        for (int j = 0; j < i; ++j) {
            mp[a[i] + a[j]].push_back({i, j});
        }
    }

    for (auto e: st) res.push_back(e);
        return res;
}