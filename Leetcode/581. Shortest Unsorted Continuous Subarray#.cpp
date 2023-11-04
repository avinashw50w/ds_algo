/*Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

In the brute force approach, we consider every possible subarray that can be formed from the given array nums. For every subarray nums[i:j] considered, we need to check whether this is the smallest unsorted subarray or not. Thus, for every such subarray considered, we find out the maximum and minimum values lying in that subarray given by max and min respectively.

If the subarrays nums[0:i-1] and nums[j:n-1] are correctly sorted, then only nums[i:j] could be the required subrray. Further, the elements in nums[0:i-1] all need to be lesser than the min for satisfying the required condition. Similarly, all the elements in nums[j:n-1] need to be larger than max.*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size(), mn = INT_MAX, mx = INT_MIN;
        // find the first breakpoint(first no from start which is not in sorted order)
        // then after that find the min element
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) flag = true;
            if (flag) mn = min(mn, a[i]);
        }

        // find the second breakpoint(first no from end which is not in sorted order)
        // then find the maximum element
        flag = false;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > a[i + 1]) flag = true;
            if (flag) mx = max(mx, a[i]);
        }

        int l, r;
        for (l = 0; l < n; ++l) {
            if (a[l] > mn) break;
        }
        for (r = n - 1; r >= 0; --r) {
            if (a[r] < mx) break;
        }

        return r - l < 0 ? 0 : r - l + 1;
    }
};