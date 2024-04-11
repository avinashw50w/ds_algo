/*Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that 
each unique element appears at most twice. The relative order of the elements should be kept the same.

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int k = 0, n = a.size();
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 and a[i] == a[i-1]) cnt++;
            else cnt = 1;
            if (cnt <= 2) a[k++] = a[i];
        }

        return k;
    }
};