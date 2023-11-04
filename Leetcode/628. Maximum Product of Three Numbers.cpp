/*Given an integer array nums, find three numbers whose product is maximum and return the maximum product.



Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
*/
// find 3 maximum and 2 minimum
// ans = max(prod of 3 max, prod of 2 min and the maximum)

int maximumProduct(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    int ans = INT_MIN;

    for (int i = 0; i <= 3; ++i) {
        int prod = 1;
        for (int j = 0; j < i; ++j) prod *= nums[j];
        for (int j = 0; j < 3 - i; ++j) prod *= nums[nums.size() - 1 - j];
        ans = max(ans, prod);
    }

    return ans;
}

////////////////////////////////////////////////
int maximumProduct(vector<int>& nums) {

    int mx1, mx2, mx3, mn1, mn2;
    mx1 = mx2 = mx3 = INT_MIN;
    mn1 = mn2 = INT_MAX;

    for (int e : nums) {
        if (e > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = e;
        }
        else if (mx2 < e and e <= mx1) {
            mx3 = mx2;
            mx2 = e;
        }
        else if (mx3 < e and e <= mx2) {
            mx3 = e;
        }

        if (e < mn1) {
            mn2 = mn1;
            mn1 = e;
        }
        else if (mn2 > e and e >= mn1) {
            mn2 = e;
        }
    }

    return max(mx1 * mx2 * mx3, mn1 * mn2 * mx1);
}