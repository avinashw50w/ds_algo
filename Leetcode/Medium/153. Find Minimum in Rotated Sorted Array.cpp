/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
210. Course Schedule II
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.*/
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size(), l = 0, r = n-1;
        if(a[l] <= a[r])
            return a[l];
        while(l <= r){
            int mid = l+(r-l)/2;
            if (a[mid] > a[mid+1])
                return a[mid+1];
            else if (a[mid] < a[mid-1])
                return a[mid];
            else if (a[mid] >= a[r])
                l=mid+1;
            else
                r=mid-1;
        }
        return a[0];
    }
};