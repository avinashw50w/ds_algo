/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]*/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 and j >= 0) {
            if (B[j] >= A[i]) A[k--] = B[j--];
            else A[k--] = A[i--];
        }

        while (j >= 0) A[k--] = B[j--];
    }
};