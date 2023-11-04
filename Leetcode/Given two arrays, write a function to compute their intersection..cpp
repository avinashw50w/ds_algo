/*Given two arrays, write a function to compute their intersection.
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Input: nums1 = [1,2], nums2 = [1,1]
Output: [4,9]
Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> f;
    vector<int> res;
    if (nums1.size() < nums2.size()) swap(nums1, nums2);
    for (int e : nums1) f[e]++;
    for (int e : nums2) if (f[e]) res.push_back(e), f[e]--;
    return res;
}