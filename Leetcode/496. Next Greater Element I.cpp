/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


Just store the next greater for each ele of nums2.
Then for each ele of nums1, store its next greater*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> next;
        stack<int> st;
        
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() and st.top() <= nums2[i]) st.pop();
            next[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        
        vector<int> res;
        for (int e: nums1) res.push_back(next[e]);
            return res;
    }
};

// another way
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> next;
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() and nums2[i] > st.top()) {
                next[st.top()] = nums2[i];
                st.pop();
            }
            next[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        
        vector<int> res;
        for (int e: nums1) {
            res.push_back(next[e]);
        }

        return res;
    }
};