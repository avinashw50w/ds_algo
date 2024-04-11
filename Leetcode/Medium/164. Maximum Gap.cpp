/*Given an integer array nums, return the maximum difference between two successive elements in its 
sorted form. If the array contains less than two elements, return 0.

 expected time complexity : O(n)

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.*/
class Solution {
public:
    void _sort(vector<int> &a, int e) {
        vector<int> res(a.size());

        int f[10] = {};
        for (int x : a)
            f[(x / e) % 10]++;

        for (int i = 1; i < 10; ++i)
            f[i] += f[i - 1];

        for (int i = a.size() - 1; i >= 0; --i) {
            res[f[(a[i] / e) % 10] - 1] = a[i];
            f[(a[i] / e) % 10]--;
        }

        a = res;
    }

    void radixSort(vector<int> &a) {
        int mx = *max_element(a.begin(), a.end());
        for (int i = 1; mx / i > 0; i *= 10) {
            _sort(a, i);
        }
    }
    
    int maximumGap(vector<int>& a) {
        int n = a.size();
        if (n < 2) return 0;
        radixSort(a);
        int ans = -1e9;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, a[i] - a[i-1]);
        }
        return ans;
    }
};