/*Given the array nums consisting of n positive integers. You computed the sum of all non-empty continous subarrays from the array and then sort them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 10^9 + 7.*/
class Solution {
    const int mod = 1e9 + 7;
public:
    int rangeSum(vector<int>& a, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum = (sum + a[j]) % mod;
                sums.push_back(sum);
            }
        }

        int ans = 0;
        sort(sums.begin(), sums.end());
        --left; --right;
        for (int i = left; i <= right; ++i) ans = (ans + sums[i]) % mod;
        return ans;
    }
};