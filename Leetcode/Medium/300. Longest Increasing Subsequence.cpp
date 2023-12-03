/*Given an integer array nums, return the length of the longest strictly increasing 
subsequence

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/
class Solution {
    vector<int> v;
public:
    int lowerBound(int x) {
        if (v.empty() || v.back() < x) return v.size();
        int l = 0, r = v.size() - 1, mid, ans = 0;

        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (v[mid] >= x) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        
        for (int e: a) {
            int pos = lowerBound(e);
            if (pos < v.size()) v[pos] = e;
            else v.push_back(e);
        }

        return v.size();
    }
};

// another implementation of lower bound
int lowerBound(int x) {
    int n = v.size(), l = 0, r = n;
    while(l < r) {
        int m = (l+r)/2;
        if (v[m] >= x) r=m;
        else l=m+1;
    }
    if (l < n && x > v[l]) l++;
    return l;
}