/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res;

        for (int i = 0; i < k; ++i) {
            while (!q.empty() and nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }

        for (int i = k; i < n; ++i) {
            res.push_back(nums[q.front()]);
            while (!q.empty() and i - q.front() >= k) q.pop_front();
            while (!q.empty() and nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }

        res.push_back(nums[q.front()]);

        return res;
    }
};