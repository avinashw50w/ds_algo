/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() and a[q.back()] <= a[i]) q.pop_back();
            q.push_back(i);
        }
        
        for (int i = k; i < a.size(); ++i) {
            res.push_back(a[q.front()]);
            while (!q.empty() and i-q.front() >= k) q.pop_front();
            while (!q.empty() and a[q.back()] <= a[i]) q.pop_back();
            q.push_back(i);
        }
        res.push_back(a[q.front()]);
        return res;
    }
};